#include "Vector.hpp"

Vector::Vector(void):x(0), y(0) {}

Vector::Vector(const float& x, const float& y):x(x), y(y) {}

Vector::Vector(const Vector& origin) {
	this->x = origin.x;
	this->y = origin.y;
}

Vector& Vector::operator=(const Vector& origin) {
	if (this == &origin)
		return (*this);
	this->x = origin.x;
	this->y = origin.y;
	return (*this);
}

Vector Vector::operator-(const Vector& deducted) const {
	float new_x = this->x - deducted.x;
	float new_y = this->y - deducted.y;
	return Vector(new_x, new_y);
}

float Vector::get_vector_length(void) const {
	return (sqrt(pow(this->x, 2) + pow(this->y, 2)));
}

Vector Vector::normalized(const float& length) const {
	float new_x = this->x / length;
	float new_y = this->y / length;
	return Vector(new_x, new_y);
}

float Vector::get_x(void) const {
	return (this->x);
}

float Vector::get_y(void) const {
	return (this->y);
}

float angle_between_vectors(const Vector& vector1_n, const Vector& vector2_n) {
	float angle = acos(vector1_n.get_x() * vector2_n.get_x() + vector1_n.get_y() * vector2_n.get_y());
	return angle * 180 / M_PI;
}

std::ostream& operator<<(std::ostream& out, const Vector& vector) {
	out << "(" << vector.get_x() << "," << vector.get_y() << ")";
	return (out);
}