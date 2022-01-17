#ifndef UNIT_HPP
# define UNIT_HPP

#include "Vector.hpp"
#include <iostream>
#include <thread>
#include <mutex>

class Unit
{
	private:
		std::string name;
		Vector position;
		Vector view_direction;
		std::mutex local_mutex;
		unsigned units_in_FOV_counter;
		static float _cos_FOV;
		static float _view_distance_pow2;
		Unit();
	public:
		Unit(const std::string& name, const Vector& position, const Vector& view_direction);
		Unit(const Unit& origin);
		Unit& operator=(const Unit& origin);
		void is_in_FOV(Unit& unit);
		const std::string& get_name(void) const;
		int get_units_in_FOV_counter(void) const;
		static void set_FOV(const float& new_FOV);
		static void set_view_distance(const float& new_view_distance);
};

std::ostream& operator<<(std::ostream& out, const Unit& Unit);

#endif