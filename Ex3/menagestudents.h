#include "student.h"

class menagestudents {
public:
	std::vector<student> collection;

	menagestudents();

	void print_collection();
	void add_student(std::string name, std::string surname, std::vector<float> grades);
	void remove_student(int index);
	void export_to_txt(std::string file_name);
	void import_from_txt(std::string file_name);
	void export_to_bin(std::string file_name);
	void import_from_bin(std::string file_name);
};