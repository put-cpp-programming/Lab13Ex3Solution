#include "student.h"
#include <numeric>

student::student(std::string name, std::string surname, std::vector<float> grades)
{
	this->name = name;
	this->surname = surname;
	this->grades = grades;
}

float student::avg()
{
	return (std::accumulate(this->grades.begin(), this->grades.end(), 0) / static_cast<float>(this->grades.size()));
}

void student::print_student()
{
	std::cout << "Name: " << this->name << "\n";
	std::cout << "Surname: " << this->surname << "\n";
	std::cout << "Grades: ";
	for (int i = 0; i < this->grades.size(); i++) {
		std::cout << this->grades[i] << " ";
	}
	std::cout << "\n";
}
