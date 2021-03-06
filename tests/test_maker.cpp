#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "../Vector.hpp"

Vector vector_generator(int flag, int randomaizer) {
	float x = rand() % (randomaizer);
	float y = rand() % (randomaizer);
	if (x == 0 && y == 0)
		x = 1;
	Vector vector(x, y);
	if (flag == 1) {
		float length = vector.get_vector_length();
		return (vector.normalized(length));
	}
	else
		return (vector);
}

int main () {
	int number_of_units;
	std::cout << "Enter number of units: ";
	std::cin >> number_of_units;
	std::string test_name = std::to_string(number_of_units) + "units_test";
	std::ofstream out(test_name);
	if (!out.is_open())
		return (0);
	srand(time(0));
	out << "Sector " << rand() % 360 + 1 << " degrees, distance " << rand() % (number_of_units) + 1 << " units\n";
	for (int i = 1; i <= number_of_units; i++) {
		out << "Unit" << i << " : position " << vector_generator(0, number_of_units);
		out << ", direction " << vector_generator(1, number_of_units) << std::endl;
	}
	out.close();
}