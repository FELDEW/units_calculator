#include "Unit.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

void calc_units_in_view(std::vector<Unit> &units, unsigned &current_unit_index, std::mutex &units_protection) {
	unsigned size = units.size();
	unsigned thread_unit_index = 0;
	while (thread_unit_index < size) {
		units_protection.lock();
		thread_unit_index = current_unit_index;
		current_unit_index++;
		units_protection.unlock();
			for (unsigned j = thread_unit_index + 1; j < size; j++)
					units[thread_unit_index].is_in_FOV(units[j]);
	}
}

int parse_line(std::vector<Unit> &units, std::string line) {
	int ret;
	char buf[50] = "";	
	float p_x, p_y, dir_x, dir_y;
	if (line.size() == 0)
		return (-1);
	ret = sscanf(line.c_str(), "%s : position (%f,%f), direction (%f,%f)", buf, &p_x, &p_y, &dir_x, &dir_y);
	std::string name(buf);
	Vector position(p_x, p_y);
	Vector view_direction(dir_x, dir_y);
	Unit unit(name, position, view_direction);
	units.push_back(unit);
	return ret;
}

void parser(std::vector<Unit>& units) {
	std::string line;
	getline(std::cin, line);
	int ret;
	float FOV, view_distance;
	ret = sscanf(line.c_str(), "Sector %f degrees, distance %f units", &FOV, &view_distance);
	Unit::set_FOV(FOV);
	Unit::set_view_distance(view_distance);
	while (ret != -1) {
		getline(std::cin, line);
		ret = parse_line(units, line);
	}
}

int main() {
	std::vector<Unit> units;
	std::vector<std::thread> threads;
	unsigned threads_number;
	parser(units);
	unsigned current_unit_index = 0;
	std::mutex units_protection;
	threads_number = std::thread::hardware_concurrency();
	if (threads_number < 1)
		threads_number = 1;
	for (unsigned i = 0; i < threads_number; i++)
		threads.push_back(std::thread(calc_units_in_view, std::ref(units), std::ref(current_unit_index), std::ref(units_protection)));
	for (auto &thread : threads)
		thread.join();
	for (auto unit : units)
		std::cout << unit;
	return (0);
}