#include <iostream>
#include <vector>
#include <string>
class student {
public:
	std::string name;
	std::string surname;
	std::vector<float> grades;

	student(std::string name, std::string surname, std::vector<float> grades);
	float avg();
	void print_student();
};