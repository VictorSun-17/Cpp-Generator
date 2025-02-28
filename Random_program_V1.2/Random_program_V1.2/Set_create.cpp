#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <format>
#include <initializer_list>
#include <string>
#include "Set_create.h"






std::string create_set(int index) {
	std::string code;
	std::string oss;
	std::string type;
	int times = random_Int(1, 10);
	int vec_elements_num = random_Int(5, 10);
	std::set<int> temp_int = {};
	std::set<float> temp_float = {};
	std::set<double> temp_double = {};
	std::set<char> temp_char = {};
	std::set<bool> temp_bool = {};


	enum aval_Type {
		INT,
		DOUBLE,
		CHAR,
		BOOL,
		FLOAT
	};

	aval_Type data_type;

	switch (random_Int(1, 5)) {
	case 1:
		type = "int";
		data_type = INT;

		break;
	case 2:
		type = "float";
		data_type = FLOAT;

		break;
	case 3:
		type = "double";
		data_type = DOUBLE;

		break;
	case 4:
		type = "char";
		data_type = CHAR;

		break;
	case 5:
		type = "bool";
		data_type = BOOL;

		break;
	}


	for (int i = 1; i <= vec_elements_num; i++)
	{

		switch (data_type) {
		case INT: //int
			switch (random_Int(1, 2)) {
			case 1:
				temp_int.insert(random_Int(-100, 100));
				break;

			case 2:
				temp_int.insert(random_Bool());
				break;
			}
			break;


		case FLOAT: //float
			switch (random_Int(1, 3)) {

			case 1:
				temp_float.insert(random_Int(-100, 100));
				break;

			case 2:
				temp_float.insert(random_Bool());
				break;

			case 3:
				temp_float.insert(random_Float(-100, 100));
				break;

			}
			break;


		case DOUBLE: //double
			switch (random_Int(1, 4)) {
			case 1:
				temp_double.insert(random_Int(-100, 100));
				break;

			case 2:
				temp_double.insert(random_Bool());
				break;

			case 3:
				temp_double.insert(random_Float(-100, 100));
				break;

			case 4:
				temp_double.insert(random_Double(-100, 100));
				break;

			}
			break;
		case CHAR: //char

			temp_char.insert(random_Char());



			break;
		case BOOL: //bool
			temp_bool.insert(random_Bool());
			break;


		}

	}

	if (data_type == INT) {
		bool first = true; // Flag to handle separator
		for (const auto& num : temp_int) {
			if (!first) {
				oss += ", "; // Add separator except for the first element
			}
			oss += std::to_string(num);
			first = false; // Update flag after the first element
		}
	}

	else if (data_type == FLOAT) {
		bool first = true; // Flag to handle separator
		for (const auto& num : temp_float) {
			if (!first) {
				oss += ", "; // Add separator except for the first element
			}
			oss += std::to_string(num);
			first = false; // Update flag after the first element
		}
	}

	else if (data_type == DOUBLE) {
		bool first = true; // Flag to handle separator
		for (const auto& num : temp_double) {
			if (!first) {
				oss += ", "; // Add separator except for the first element
			}
			oss += std::to_string(num);
			first = false; // Update flag after the first element
		}
	}

	else if (data_type == CHAR) {
		bool first = true; // Flag to handle separator
		for (const auto& num : temp_char) {
			if (!first) {
				oss += ", "; // Add separator except for the first element
			}
			oss += std::to_string(num);
			first = false; // Update flag after the first element
		}
	}

	else {
		bool first = true; // Flag to handle separator
		for (const auto& num : temp_bool) {
			if (!first) {
				oss += ", "; // Add separator except for the first element
			}
			oss += std::to_string(num);
			first = false; // Update flag after the first element
		}
	}

	code += "std::set<" + type + "> set_" + std::to_string(index) + " = {" + oss + "};\n";

	if (data_type == INT) {

		code += "for (int num : set_" + std::to_string(index) + ") { \n";

		code += "	std::cout << num << ' ';\n";

		code += "	std::cout << std::endl;\n";
		code += "}\n";
	}

	else if (data_type == FLOAT) {
		code += "for (float num : set_" + std::to_string(index) + ") { \n";

		code += "	std::cout << num << ' ';\n";

		code += "	std::cout << std::endl;\n";
		code += "}\n";
	}


	else if (data_type == DOUBLE) {
		code += "for (double num : set_" + std::to_string(index) + ") { \n";

		code += "	std::cout << num << ' ';\n";

		code += "	std::cout << std::endl;\n";
		code += "}\n";
	}

	else if (data_type == CHAR) {
		code += "for (char num : set_" + std::to_string(index) + ") { \n";

		code += "	std::cout << num << ' ';\n";

		code += "	std::cout << std::endl;\n";
		code += "}\n";
	}

	else {
		code += "for (bool num : set_" + std::to_string(index) + ") { \n";

		code += "	std::cout << num << ' ';\n";

		code += "	std::cout << std::endl;\n";
		code += "}\n";
	}





	return code;


}
