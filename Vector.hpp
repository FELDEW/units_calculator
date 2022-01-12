#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <cmath>

class Vector
{
	private:
		float x;
		float y;
		Vector();
	public:
		Vector(const float& x, const float& y);
		Vector(const Vector& origin);
		Vector& operator=(const Vector& origin);
		Vector operator-(const Vector& deducted);
		float get_vector_length(void);
};


#endif