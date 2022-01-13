#include "Unit.hpp"

Unit::Unit(const std::string& name, const Vector& position, const Vector& view_direction):name(name),position(position), view_direction(view_direction) {
	this->units_in_FOV_counter = 0;
}

Unit::Unit(const Unit& origin) {
	this->name = origin.name;
	this->position = origin.position;
	this->view_direction = origin.view_direction;
	this->units_in_FOV_counter = origin.units_in_FOV_counter;
}

Unit& Unit::operator=(const Unit& origin) {
	if (this == &origin)
		return (*this);
	this->name = origin.name;
	this->position = origin.position;
	this->view_direction = origin.view_direction;
	this->units_in_FOV_counter = origin.units_in_FOV_counter;
	return (*this);
}

bool Unit::is_in_FOV(const Unit& unit) {
	Vector diff = unit.position - this->position;
	float distance_length = diff.get_vector_length();
	if (distance_length <= Unit::_view_distance && distance_length != 0) {
		float angle = angle_between_vectors(this->view_direction, diff.normalized(distance_length));
		if (angle < Unit::_FOV / 2) {
			this->units_in_FOV_counter++;
			return true;
		}
	}
	return false;	
}

const std::string& Unit::get_name(void) const {
	return (this->name);
}

int Unit::get_units_in_FOV_counter(void) const {
	return (this->units_in_FOV_counter);
}

void Unit::set_FOV(const float& new_FOV) {
	Unit::_FOV = new_FOV;
}

void Unit::set_view_distance(const float& new_view_distance) {
	Unit::_view_distance = new_view_distance;
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
	out << unit.get_name() << " sees " << unit.get_units_in_FOV_counter() << " units\n";
	return (out);
}

float Unit::_FOV = 0;
float Unit::_view_distance = 0;