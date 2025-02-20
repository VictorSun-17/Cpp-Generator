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
#include "Vector_create.h"


int random_Int(int min, int max) {
	return min + rand() % (max - min + 1);
}

// Function to generate a random float in a given range
float random_Float(float min, float max) {
	return min + static_cast<float>(rand()) / RAND_MAX * (max - min);
}

// Function to generate a random double in a given range
double random_Double(double min, double max) {
	return min + static_cast<double>(rand()) / RAND_MAX * (max - min);
}

// Function to generate a random character (A-Z, a-z, 0-9)
char random_Char() {
	const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	int index = rand() % (sizeof(charset) - 1); // Exclude null terminator
	return charset[index];
}

// Function to generate a random boolean value
bool random_Bool() {
	return rand() % 2; // Returns either 0 (false) or 1 (true)
}






std::string create_vec(int index) {
	std::string code;
	std::string oss;
	std::string type;
	int times = random_Int(1, 10);
	int vec_elements_num = random_Int(5, 10);
	std::vector<int> temp_int = {};
	std::vector<float> temp_float = {};
	std::vector<double> temp_double = {};
	std::vector<char> temp_char = {};
	std::vector<bool> temp_bool = {};


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
				temp_int.push_back(random_Int(-100, 100));
				break;

			case 2:
				temp_int.push_back(random_Bool());
				break;
			}
			break;


		case FLOAT: //float
			switch (random_Int(1, 3)) {

			case 1:
				temp_float.push_back(random_Int(-100, 100));
				break;

			case 2:
				temp_float.push_back(random_Bool());
				break;

			case 3:
				temp_float.push_back(random_Float(-100, 100));
				break;

			}
			break;


		case DOUBLE: //double
			switch (random_Int(1, 4)) {
			case 1:
				temp_double.push_back(random_Int(-100, 100));
				break;

			case 2:
				temp_double.push_back(random_Bool());
				break;

			case 3:
				temp_double.push_back(random_Float(-100, 100));
				break;

			case 4:
				temp_double.push_back(random_Double(-100, 100));
				break;

			}
			break;
		case CHAR: //char

			temp_char.push_back(random_Char());



			break;
		case BOOL: //bool
			temp_bool.push_back(random_Bool());
			break;


		}




	}

	if (data_type == INT) {

		for (int i = 1; i <= vec_elements_num; i++) {
			oss += std::to_string(temp_int[i - 1]);
			if (i != vec_elements_num) {
				oss += ", "; // Add a separator between numbers
			}
		}
	}
	else if (data_type == FLOAT) {
		for (int i = 1; i <= vec_elements_num; i++) {
			oss += std::to_string(temp_float[i - 1]);
			if (i != vec_elements_num) {
				oss += ", "; // Add a separator between numbers
			}
		}
	}


	else if (data_type == DOUBLE) {
		for (int i = 1; i <= vec_elements_num; i++) {
			oss += std::to_string(temp_double[i - 1]);
			if (i != vec_elements_num) {
				oss += ", "; // Add a separator between numbers
			}
		}
	}

	else if (data_type == CHAR) {
		for (int i = 1; i <= vec_elements_num; i++) {
			oss += std::to_string(temp_char[i - 1]);
			if (i != vec_elements_num) {
				oss += ", "; // Add a separator between numbers
			}
		}
	}

	else {
		for (int i = 1; i <= vec_elements_num; i++) {
			oss += std::to_string(temp_bool[i - 1]);
			if (i != vec_elements_num) {
				oss += ", "; // Add a separator between numbers
			}
		}
	}


	//print out secton

	code += "std::vector<" + type + "> vec_" + std::to_string(index) + " = {" + oss + "};\n";


	if (data_type == INT) {

		code += "for (int num : vec_" + std::to_string(index) +  ") { \n";

		code += "	std::cout << num << ' ';\n";
		
		code += "	std::cout << std::endl;\n";
		code += "}\n";
	}

	else if (data_type == FLOAT) {
		code += "for (float num : vec_" + std::to_string(index) + ") { \n";

		code += "	std::cout << num << ' ';\n";

		code += "	std::cout << std::endl;\n";
		code += "}\n";
	}


	else if (data_type == DOUBLE) {
		code += "for (double num : vec_" + std::to_string(index) + ") { \n";

		code += "	std::cout << num << ' ';\n";

		code += "	std::cout << std::endl;\n";
		code += "}\n";
	}

	else if (data_type == CHAR) {
		code += "for (char num : vec_" + std::to_string(index) + ") { \n";

		code += "	std::cout << num << ' ';\n";

		code += "	std::cout << std::endl;\n";
		code += "}\n";
	}

	else {
		code += "for (bool num : vec_" + std::to_string(index) + ") { \n";

		code += "	std::cout << num << ' ';\n";

		code += "	std::cout << std::endl;\n";
		code += "}\n";
	}


	return code;


}