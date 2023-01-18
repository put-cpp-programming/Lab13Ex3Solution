#include "ex3.h"
#include <iostream>

void ex3()
{
	menagestudents instance;
	unsigned short number_of_choices = 4;
	unsigned short choice = 0;
	do {
		std::cout << "0: Exit\n";
		std::cout << "1: Add student\n";
		std::cout << "2: Remove student\n";
		std::cout << "3: Print all\n";
		std::cout << "4: Export to txt file\n";
		std::cout << "5: Import from txt file\n";
		std::cout << "6: Export to bin file\n";
		std::cout << "7: Import from bin file\n";		
		std::cin >> choice;
		switch (choice)
		{
		case 1: {
			std::string name, surname;
			std::vector<float> vec;
			std::cout << "Enter name and surname: ";
			std::cin >> name >> surname;
			std::cout << "Enter grades (in one line):\n";
			do
			{
				float input;
				if (std::cin >> input)
					vec.push_back(input);
			} while (std::cin && std::cin.peek() != '\n');
			std::cout << "\n";
			instance.add_student(name, surname, vec);
			break;
		};
		case 2: {
			std::cout << "Enter student index to remove: ";
			int index;
			std::cin >> index;
			instance.remove_student(index);
			break;
		};
		case 3: {
			std::cout << "\n\n";
			instance.print_collection();
			std::cout << "\n\n";
			break;
		};
		case 4: {
			std::cout << "Enter file name: ";
			std::string file_name;
			std::cin >> file_name;
			instance.export_to_txt(file_name);
			break;
		};
		case 5: {
			std::cout << "Enter file name: ";
			std::string file_name;
			std::cin >> file_name;
			instance.import_from_txt(file_name);
			break;
		};
		case 6: {
			std::cout << "Enter file name: ";
			std::string file_name;
			std::cin >> file_name;
			instance.export_to_bin(file_name);
			break;
		};
		case 7: {
			std::cout << "Enter file name: ";
			std::string file_name;
			std::cin >> file_name;
			instance.import_from_bin(file_name);
		}
		case 0: {
			break;
		};
		default: {
			std::cout << "Invalid input\n";
			break;
		};
		}
	} while (choice != 0);
	return;
}
