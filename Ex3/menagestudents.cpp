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

void menagestudents::export_to_txt(std::string file_name)
{
	std::ofstream file;
	file.open(file_name, std::ios::out | std::ios::trunc);
	if (file.is_open()) {
		for (int i = 0; i < this->collection.size(); i++) {
			file << this->collection[i].name << "\n";
			file << this->collection[i].surname << "\n";
			for (int j = 0; j < this->collection[i].grades.size(); j++) {
				file << this->collection[i].grades[j] << " ";
			}
			file << "\n";
		}
		file.close();
	}
	else {
		file.close();
		std::cout << "Can not open file " << file_name << "!\n";
	}
}

void menagestudents::import_from_txt(std::string file_name)
{
	this->collection.clear();
	std::ifstream file;
	file.open(file_name, std::ios::in);
	if (file.is_open()) {
		this->collection.clear();
		std::string name;
		std::string surname;
		std::string grades;
		while (std::getline(file, name)) {
			std::getline(file, surname);
			std::getline(file, grades);
			std::vector<float> grades_vec = string_to_vec(grades);
			this->collection.push_back(student(name, surname, grades_vec));
		}
		file.close();
	}
	else {
		file.close();
		std::cout << "Can not open file " << file_name << "!\n";
	}
}

std::vector<float> menagestudents::string_to_vec(std::string grades)
{
	std::vector<float> grades_vec;
	std::stringstream ss(grades);
	std::string part;

	while (ss >> part)
		grades_vec.push_back(stof(part));

	return grades_vec;
}

void menagestudents::export_to_bin(std::string file_name)
{
	std::ofstream file;
	file.open(file_name, std::ios::binary);
	if (file.is_open()) {
		size_t size = this->collection.size();
		file.write((char*)&size, sizeof(size));

		for (int i = 0; i < this->collection.size(); i++) {
			std::string name = this->collection[i].name;
			std::string surname = this->collection[i].surname;
			std::vector<float> vec = this->collection[i].grades;

			size_t size = name.size();
			file.write((char*)&size, sizeof(size));
			file.write(&name[0], size);

			size = surname.size();
			file.write((char*)&size, sizeof(size));
			file.write(&surname[0], size);

			size = vec.size();
			file.write((char*)&size, sizeof(size));
			file.write((char*)&vec[0], vec.size() * sizeof(float));
		}
		file.close();
	}
	else {
		file.close();
		std::cout << "Can not open file " << file_name << "!\n";
	}
}

void menagestudents::import_from_bin(std::string file_name)
{
	this->collection.clear();
	std::ifstream file;
	file.open(file_name, std::ifstream::binary);
	if (file.is_open()) {
		size_t collection_size;
		file.read((char*)&collection_size, sizeof(collection_size));

		for (int i = 0; i < collection_size; i++) {
			size_t size;
			file.read((char*)&size, sizeof(size));
			std::string name;
			name.resize(size);
			file.read(&name[0], size);
			
			file.read((char*)&size, sizeof(size));
			std::string surname;
			surname.resize(size);
			file.read(&surname[0], size);


			file.read((char*)&size, sizeof(size));
			std::vector<float> vec;
			vec.resize(size);
			file.read((char*)&vec[0], size*sizeof(float));

			this->collection.push_back(student(name, surname, vec));
		}
		file.close();
	}
	else {
		file.close();
		std::cout << "Can not open file " << file_name << "!\n";
	}
}
