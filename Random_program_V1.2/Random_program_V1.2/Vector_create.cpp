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


int randomInt(int min, int max) {
	return min + rand() % (max - min + 1);
}

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
	int generated_char = rand() % (sizeof(charset) - 1); // Exclude null terminator
	return charset[generated_char];
}

// Function to generate a random boolean value
bool random_Bool() {
	return rand() % 2; // Returns either 0 (false) or 1 (true)
}

std::string random_vec_op(int n, std::vector<std::pair<int, std::string>> vec_records) {
	std::string op;
	int operation_numbers = randomInt(30, 100);
	int current = 0;
	int current_2 = 0;

	for (int m = 1; m <= operation_numbers; m++) {
		current = randomInt(0, n - 1);
		current_2 = randomInt(0, n - 1);
		auto record_1 = vec_records.at(current);
		auto record_2 = vec_records.at(current_2);
		switch (randomInt(1, 32)) {
		case 1:
			op += "	vec_" + std::to_string(current) + ".push_back(" + std::to_string(randomInt(1, 100)) + "); \n";//Adds an element to the end of the vector.
			break;
		case 2:
			op += "	vec_" + std::to_string(current) + ".insert(vec_" + std::to_string(current) + ".begin() + RdmInt(0, vec_" + std::to_string(current) + ".size()-1)," + std::to_string(randomInt(1, 100)) + "); \n"; //insert at certain place
			break;
		case 3:

			op += "	vec_" + std::to_string(current) + ".erase(vec_" + std::to_string(current) + ".begin() + RdmInt(0, vec_" + std::to_string(current) + ".size()-1)); \n";
			break;
		case 4:
			op += "	vec_" + std::to_string(current) + ".pop_back();\n";
			break;
		case 5:
			op += "	vec_" + std::to_string(current) + ".resize(" + std::to_string(randomInt(5, 20)) + ");\n";
			break;
		case 6:
			op += "	std::reverse(vec_" + std::to_string(current) + ".begin(), vec_" + std::to_string(current) + ".end());\n";
			break;
		case 7:
			op += "	std::sort(vec_" + std::to_string(current) + ".begin(), vec_" + std::to_string(current) + ".end());\n";
			break;
		case 8:
			op += "	vec_" + std::to_string(current) + ".clear();\n";
			break;
		case 9:
			if (record_1.second == "int" or record_1.second == "double" or record_1.second == "char" or record_1.second == "float" or record_1.second == "bool") {
				op += "	vec_" + std::to_string(current) + ".assign(" + std::to_string(randomInt(3, 7)) +
					", " + std::to_string(randomInt(1, 50)) + ");\n"; // Assign a new set of values
			}
			else{
				op += "	vec_" + std::to_string(current) + ".assign(" + std::to_string(randomInt(3, 7)) +
					", " + "{" + std::to_string(randomInt(1, 50)) + ", " + std::to_string(randomInt(1, 50)) + ", " + std::to_string(randomInt(1, 50)) + ", " + std::to_string(randomInt(1, 50)) + "}" + ");\n";
			}
			break;
		case 10:
			op += "	vec_" + std::to_string(current) + ".shrink_to_fit();\n"; // Reduce capacity to fit size
			break;
		case 11:
			if (record_1.second == record_2.second && record_1.first != record_2.first) {
				op += "	vec_" + std::to_string(current) + ".swap(vec_" + std::to_string(current_2) + ");\n"; // Swap two vectors
			}
			break;
		case 12:
			op += "	vec_" + std::to_string(current) + ".emplace_back(" + std::to_string(randomInt(1, 100)) + ");\n"; // Efficient push_back
			break;
		case 13:
			op += "	vec_" + std::to_string(current) + ".capacity();\n"; // Print capacity
			break;
		case 14:
			op += "	vec_" + std::to_string(current) + ".size();\n"; //Returns the number of elements in the vector.
			break;
		case 15:
			op += "	vec_" + std::to_string(current) + ".max_size();\n"; //Returns the maximum number of elements that the vector can hold.
			break;
		case 16:
			op += "	vec_" + std::to_string(current) + ".empty();\n"; //Checks if the vector is empty.
			break;
		case 17:
			op += "	vec_" + std::to_string(current) + ".at(RdmInt(0, vec_" + std::to_string(current) + ".size()-1)); \n"; //Accesses the element at a specific position, with bounds checking.
			break;
		case 18:
			op += "	vec_" + std::to_string(current) + ".front();\n"; //Accesses the first element of the vector
			break;
		case 19:
			op += "	vec_" + std::to_string(current) + ".back();\n"; //Accesses the last element of the vector
			break;
		case 20:
			op += "	vec_" + std::to_string(current) + ".begin();\n"; //Returns an iterator pointing to the first element of the vector
			break;
		case 21:
			op += "	vec_" + std::to_string(current) + ".end();\n"; // Returns an iterator pointing to the past-the-end element of the vector
			break;
		case 22:
			op += "	vec_" + std::to_string(current) + ".rbegin();\n"; //Returns a reverse iterator pointing to the last element of the vector
			break;
		case 23:
			op += "	vec_" + std::to_string(current) + ".rend();\n"; // Returns a reverse iterator pointing to the element preceding the first element of the vector
			break;
		case 24:
			op += "	vec_" + std::to_string(current) + ".cbegin();\n"; //Returns const_iterator to beginning
			break;
		case 25:
			op += "	vec_" + std::to_string(current) + ".cend();\n"; // Returns const_iterator to end
			break;
		case 26:
			op += "	vec_" + std::to_string(current) + ".crbegin();\n"; //Returns const_reverse_iterator to reverse beginning
			break;
		case 27:
			op += "	vec_" + std::to_string(current) + ".crend();\n"; // Returns const_reverse_iterator to reverse end
			break;
		case 28:
			op += "	vec_" + std::to_string(current) + ".shrink_to_fit();\n"; // Reduces memory usage by freeing unused space.
			break;

		case 29:
			op += "	vec_" + std::to_string(current) + ".clear();\n"; // Removes all elements from the vector.
			break;
		case 30:
			op += "	vec_" + std::to_string(current) + ".emplace(vec_" + std::to_string(current) + ".begin() + RdmInt(0, vec_" + std::to_string(current) + ".size()-1) ," + std::to_string(randomInt(1, 100)) + "); \n"; // Constructs and inserts an element in the vector.
			break;
		case 31:
			op += "	vec_" + std::to_string(current) + ".reserve(" + std::to_string(randomInt(1, 10000)) + "); \n"; // Requests that the vector capacity be at least enough to contain a specified number of elements.
			break;



		}

	}




	return op;
}



std::string create_vec(int index) {
	std::string code;
	std::string oss;
	std::string type;
	int times = random_Int(1, 10);
	int vec_elements_num = random_Int(5, 10);
	/*int vec_rows = random_Int(1, 2);*/
	int vec_rows = 4;// 1 for 1D vector
	//temp vectors
	std::vector<int> temp_int = {};
	std::vector<float> temp_float = {};
	std::vector<double> temp_double = {};
	std::vector<char> temp_char = {};
	std::vector<bool> temp_bool = {};

	//temp 2D vectors
	std::vector<std::vector<int>> temp_2d_int;
	std::vector<std::vector<double>> temp_2d_double;
	std::vector<std::vector<char>> temp_2d_char;
	std::vector<std::vector<bool>> temp_2d_bool;
	std::vector<std::vector<float>> temp_2d_float;
	std::vector<std::pair<int, std::string>> vec_records = {};






	enum aval_Type {
		INT,
		DOUBLE,
		CHAR,
		BOOL,
		FLOAT,
		INT_2D,
		DOUBLE_2D,
		CHAR_2D,
		BOOL_2D,
		FLOAT_2D,
		NONE
	};

	aval_Type data_type = NONE;


	for (int n = 0; n < index; n++) {

		switch (random_Int(1, 10))
			/*switch (1)*/ {
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

		case 6:
			type = "std::vector<int>";
			data_type = INT_2D;
			break;
		case 7:
			type = "std::vector<float>";
			data_type = FLOAT_2D;
			break;
		case 8:
			type = "std::vector<double>";
			data_type = DOUBLE_2D;
			break;
		case 9:
			type = "std::vector<char>";
			data_type = CHAR_2D;
			break;
		case 10:
			type = "std::vector<bool>";
			data_type = BOOL_2D;
			break;
		}

		vec_records.push_back(std::make_pair(n, type));


		if (data_type == INT_2D or data_type == DOUBLE_2D or data_type == CHAR_2D or data_type == FLOAT_2D or data_type == BOOL_2D) {
			for (int m = 1; m <= vec_rows; m++) {
				for (int i = 1; i <= vec_elements_num; i++)
				{

					switch (data_type) {
					case INT_2D: //int
						switch (random_Int(1, 2)) {
						case 1:
							temp_int.push_back(random_Int(-100, 100));
							break;

						case 2:
							temp_int.push_back(random_Bool());
							break;
						}
						break;


					case FLOAT_2D: //float
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


					case DOUBLE_2D: //double
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
					case CHAR_2D: //char

						temp_char.push_back(random_Char());



						break;
					case BOOL_2D: //bool
						temp_bool.push_back(random_Bool());
						break;


					}

				}

				if (data_type == INT_2D) {
					temp_2d_int.push_back(temp_int);
					for (int k = 1; k <= vec_elements_num; k++) {
						oss += std::to_string(temp_int[k - 1]);
						if (k != vec_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < vec_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_int.clear();
				}
				else if (data_type == FLOAT_2D) {
					temp_2d_float.push_back(temp_float);
					for (int k = 1; k <= vec_elements_num; k++) {
						oss += std::to_string(temp_float[k - 1]);
						if (k != vec_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < vec_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_float.clear();
				}
				else if (data_type == DOUBLE_2D) {
					temp_2d_double.push_back(temp_double);
					for (int k = 1; k <= vec_elements_num; k++) {
						oss += std::to_string(temp_double[k - 1]);
						if (k != vec_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < vec_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_double.clear();
				}
				else if (data_type == CHAR_2D) {
					temp_2d_char.push_back(temp_char);
					for (int k = 1; k <= vec_elements_num; k++) {
						oss += std::to_string(temp_char[k - 1]);
						if (k != vec_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < vec_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_char.clear();
				}
				else if (data_type == BOOL_2D) {
					temp_2d_bool.push_back(temp_bool);
					for (int k = 1; k <= vec_elements_num; k++) {
						oss += std::to_string(temp_bool[k - 1]);
						if (k != vec_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < vec_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_bool.clear();
				}


			}
			//for (const auto& row : temp_2d_int) {
			//	for (const auto& val : row) {
			//		std::cout << val << " ";
			//	}
			//	std::cout << std::endl;
			//}

			code += "	std::vector<" + type + "> vec_" + std::to_string(n) + " = { {" + oss + " };\n";
			oss = {};


			//if (data_type == INT) {

			//	code += "for (const auto& row : vec_" + std::to_string(n) + ") { \n";
			//	code += "	for (const auto& val : row) {\n";
			//	code += "		std::cout << val << \"\"; \n";
			//	code += "	}\n";
			//	code += "	std::cout << std::endl;\n";
			//	code += "}\n";
			//}
		}

		else {
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

				temp_int = {};
			}
			else if (data_type == FLOAT) {
				for (int i = 1; i <= vec_elements_num; i++) {
					oss += std::to_string(temp_float[i - 1]);
					if (i != vec_elements_num) {
						oss += ", "; // Add a separator between numbers
					}
				}

				temp_float = {};
			}


			else if (data_type == DOUBLE) {
				for (int i = 1; i <= vec_elements_num; i++) {
					oss += std::to_string(temp_double[i - 1]);
					if (i != vec_elements_num) {
						oss += ", "; // Add a separator between numbers
					}
				}

				temp_double = {};
			}

			else if (data_type == CHAR) {
				for (int i = 1; i <= vec_elements_num; i++) {
					oss += std::to_string(temp_char[i - 1]);
					if (i != vec_elements_num) {
						oss += ", "; // Add a separator between numbers
					}
				}

				temp_char = {};
			}

			else {
				for (int i = 1; i <= vec_elements_num; i++) {
					oss += std::to_string(temp_bool[i - 1]);
					if (i != vec_elements_num) {
						oss += ", "; // Add a separator between numbers
					}
				}
				temp_bool = {};
			}


			//print out secton

			code += "	std::vector<" + type + "> vec_" + std::to_string(n) + " = {" + oss + "};\n";
			oss = {};

			//This is about print out each vector
			/*if (data_type == INT) {

				code += "for (int num : vec_" + std::to_string(n) + ") { \n";

				code += "	std::cout << num << ' ';\n";

				code += "	std::cout << std::endl;\n";
				code += "}\n";
			}

			else if (data_type == FLOAT) {
				code += "for (float num : vec_" + std::to_string(n) + ") { \n";

				code += "	std::cout << num << ' ';\n";

				code += "	std::cout << std::endl;\n";
				code += "}\n";
			}


			else if (data_type == DOUBLE) {
				code += "for (double num : vec_" + std::to_string(n) + ") { \n";

				code += "	std::cout << num << ' ';\n";

				code += "	std::cout << std::endl;\n";
				code += "}\n";
			}

			else if (data_type == CHAR) {
				code += "for (char num : vec_" + std::to_string(n) + ") { \n";

				code += "	std::cout << num << ' ';\n";

				code += "	std::cout << std::endl;\n";
				code += "}\n";
			}

			else {
				code += "for (bool num : vec_" + std::to_string(n) + ") { \n";

				code += "	std::cout << num << ' ';\n";

				code += "	std::cout << std::endl;\n";
				code += "}\n";
			}*/

		}

	}

	//random operations generated
	code += random_vec_op(index, vec_records);

	code += "	std::vector<uint8_t> buffer;\n";
	for (int m = 0; m < index; m++) {
		code += "	append_data(buffer, vec_" + std::to_string(m) + ");\n";

	}
	code += "	uint32_t hash_result = simple_hash(buffer.data(), buffer.size());\n";
	code += "	std::cout << \"32 - bit hash : 0x\" << std::hex << hash_result << std::dec << std::endl;\n";





	code += "\n";
	return code;
}