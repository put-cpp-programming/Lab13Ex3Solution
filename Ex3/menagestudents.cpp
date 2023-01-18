#include "menagestudents.h"

menagestudents::menagestudents()
{
	this->collection.clear();
}

void menagestudents::print_collection()
{
	for (int i = 0; i < this->collection.size(); i++) {
		std::cout << "Studetn number: " << i + 1 << "\n";
		this->collection[i].print_student();
		std::cout << "Avg grade: " << this->collection[i].avg() << "\n\n";
	}
}

void menagestudents::add_student(std::string name, std::string surname, std::vector<float> grades)
{
	this->collection.push_back(student(name, surname, grades));
}

void menagestudents::remove_student(int index)
{
	this->collection.erase(this->collection.begin() + index);
}
