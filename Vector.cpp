#include "Vector.hpp"

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
}

Vector Vector::operator-(const Vector& deducted) {
	float new_x = this->x - deducted.x;
	float new_y = this->y - deducted.y;
	return Vector(new_x, new_y);
}

float Vector::get_vector_length(void) {
	return (sqrt(pow(this->x, 2) - pow(this->y, 2)));
}
