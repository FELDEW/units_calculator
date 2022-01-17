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

void Unit::is_in_FOV(Unit& unit) {
	Vector diff = unit.position - this->position;
	float distance_length_pow2 = diff.get_vector_length();
	if (distance_length_pow2 <= Unit::_view_distance_pow2 && distance_length_pow2 != 0) {
		float angle = cos_angle_between_vectors(this->view_direction, diff.normalized(distance_length_pow2));
		float angle2 = cos_angle_between_vectors(unit.view_direction, diff.normalized(distance_length_pow2));
		if (angle > Unit::_cos_FOV) {
			this->local_mutex.lock();
			this->units_in_FOV_counter++;
			this->local_mutex.unlock();
		}
		if (angle2 > Unit::_cos_FOV) {
			unit.local_mutex.lock();
			unit.units_in_FOV_counter++;
			unit.local_mutex.unlock();
		}
	}
	return ;	
}

const std::string& Unit::get_name(void) const {
	return (this->name);
}

int Unit::get_units_in_FOV_counter(void) const {
	return (this->units_in_FOV_counter);
}

void Unit::set_FOV(const float& new_FOV) {
	Unit::_cos_FOV = cos(new_FOV * M_PI / 360);
}

void Unit::set_view_distance(const float& new_view_distance) {
	Unit::_view_distance_pow2 = pow(new_view_distance, 2);
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
	out << unit.get_name() << " sees " << unit.get_units_in_FOV_counter() << " units\n";
	return (out);
}

float Unit::_cos_FOV = 1;
float Unit::_view_distance_pow2 = 0;