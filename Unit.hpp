#ifndef UNIT_HPP
# define UNIT_HPP

#include "Vector.hpp"
#include <iostream>

class Unit
{
	private:
		std::string name;
		Vector position;
		Vector view_direction;
		int units_in_FOV_counter;
		static float FOV;
		static float view_distance;
		Unit();
	public:
		Unit(const Vector& position, const Vector& view_direction);
		Unit(const Unit& origin);
		Unit& operator=(const Unit& origin);
		static void set_FOV(const float& new_FOV);
		static const float& get_FOV(void);
		static void set_view_distance(const float& new_view_distance);
		static const float& get_view_distance(void);
};

std::ostream& operator<<(std::ostream& out, const Unit& Unit);

#endif