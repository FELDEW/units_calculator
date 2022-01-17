#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <cmath>
#include <iostream>

class Vector
{
	private:
		float x;
		float y;
	public:
		Vector();
		Vector(const float& x, const float& y);
		Vector(const Vector& origin);
		Vector normalized(const float& length) const;
		Vector& operator=(const Vector& origin);
		Vector operator-(const Vector& deducted) const;
		float get_vector_length(void) const;
		float get_x(void) const;
		float get_y(void) const;
};

float cos_angle_between_vectors(const Vector& vector1, const Vector& vector2);
std::ostream& operator<<(std::ostream& out, const Vector& vector);

#endif