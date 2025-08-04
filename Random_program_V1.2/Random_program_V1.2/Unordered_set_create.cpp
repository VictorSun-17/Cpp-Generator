#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <initializer_list>
#include <string>
#include "Random_program.h"
#include <unordered_set>

std::unordered_set<int> create_unordered_set_int(int length = 1) {
	std::unordered_set<int> temp;
	for (int n = 1; n <= length; n++) {
		switch (random_Int(1, 2)) {
		case 1:
			temp.emplace(random_Int(-100, 100));
			break;

		case 2:
			temp.emplace(random_Bool());
			break;
		}
	}
	return temp;
}

std::unordered_set<float> create_unordered_set_float(int length = 1) {
	std::unordered_set<float> temp;
	for (int n = 1; n <= length; n++) {
		switch (random_Int(1, 2)) {
		case 1:
			temp.emplace(random_Int(-100, 100));
			break;

		case 2:
			temp.emplace(random_Bool());
			break;

		case 3:
			temp.emplace(random_Float(-100, 100));
			break;
		}
	}
	return temp;
}

std::unordered_set<double> create_unordered_set_double(int length = 1) {
	std::unordered_set<double> temp;
	for (int n = 1; n <= length; n++) {
		switch (random_Int(1, 4)) {
		case 1:
			temp.emplace(random_Int(-100, 100));
			break;

		case 2:
			temp.emplace(random_Bool());
			break;

		case 3:
			temp.emplace(random_Float(-100, 100));
			break;

		case 4:
			temp.emplace(random_Double(-100, 100));
			break;
		}
	}
	return temp;
}

std::unordered_set<char> create_unordered_set_char(int length = 1) {
	std::unordered_set<char> temp;
	for (int n = 1; n <= length; n++) {
		temp.emplace(random_Char());
	}
	return temp;
}

std::unordered_set<bool> create_unordered_set_bool(int length = 1) {
	std::unordered_set<bool> temp;
	for (int n = 1; n <= length; n++) {
		temp.emplace(random_Bool());
	}
	return temp;
}

struct unordered_set_records {
	int length;
	std::string type;
	int bucket_size;
};


std::string generate_unordered_set_element(std::string type) {
	std::string op;
	int vec_elements_num = random_Int(5, 10);
	if (type == "int")
		return std::to_string(random_Int(-100, 100));
	else if (type == "float")
		return std::to_string(random_Float(-100, 100));
	else if (type == "double")
		return std::to_string(random_Double(-100, 100));
	else if (type == "char")
		return std::to_string(random_Char());
	else if (type == "bool")
		return std::to_string(random_Bool());
	else if (type == "std::unordered_set<int>") {
		std::unordered_set<int> temp_int = create_unordered_set_int(vec_elements_num);
		op += "{";
		int temp_size = temp_int.size();
		for (int k = 1; k <= temp_size; k++) {
			auto it = temp_int.begin();
			std::advance(it, k - 1);
			auto value = *it;
			op += std::to_string(value);
			if (k != temp_size) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		temp_int.clear();
		return op;
	}
	else if (type == "std::unordered_set<float>") {
		std::unordered_set<float> temp_float = create_unordered_set_float(vec_elements_num);
		op += "{";
		int temp_size = temp_float.size();
		for (int k = 1; k <= temp_size; k++) {
			auto it = temp_float.begin();
			std::advance(it, k - 1);
			auto value = *it;
			op += std::to_string(value);
			if (k != temp_size) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		temp_float.clear();
		return op;
	}
	else if (type == "std::unordered_set<double>") {
		std::unordered_set<double> temp_double = create_unordered_set_double(vec_elements_num);
		op += "{";
		int temp_size = temp_double.size();
		for (int k = 1; k <= temp_size; k++) {
			auto it = temp_double.begin();
			std::advance(it, k - 1);
			auto value = *it;
			op += std::to_string(value);
			if (k != temp_size) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		temp_double.clear();
		return op;
	}
	else if (type == "std::unordered_set<char>") {
		std::unordered_set<char> temp_char = create_unordered_set_char(vec_elements_num);
		op += "{";
		int temp_size = temp_char.size();
		for (int k = 1; k <= temp_size; k++) {
			auto it = temp_char.begin();
			std::advance(it, k - 1);
			auto value = *it;
			op += std::to_string(value);
			if (k != temp_size) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		temp_char.clear();
		return op;
	}
	else if (type == "std::unordered_set<bool>") {
		std::unordered_set<bool> temp_bool = create_unordered_set_bool(vec_elements_num);
		op += "{";
		int temp_size = temp_bool.size();
		for (int k = 1; k <= temp_size; k++) {
			auto it = temp_bool.begin();
			std::advance(it, k - 1);
			auto value = *it;
			op += std::to_string(value);
			if (k != temp_size) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		temp_bool.clear();
		return op;
	}

}



std::string random_unordered_set_op(int n, std::vector<unordered_set_records> records) {
	std::string op;
	int operation_numbers = random_Int(5, 5);
	int current = 0;
	int current_2 = 0;
	std::vector<unordered_set_records> local_records = records;
	int random_size = random_Int(5, 100);
	for (int m = 1; m <= operation_numbers; m++) {
		current = random_Int(0, n - 1);
		current_2 = random_Int(0, n - 1);
		auto record_1 = local_records.at(current);
		auto record_2 = local_records.at(current_2);
		int tmp_length;
		int tmp_length_2;
		switch (random_Int(1, 24)) {
		case 1:
			if (record_1.length != 0) {
				op += "	unordered_set_" + std::to_string(current) + ".begin(); \n";//An iterator to the first element in the container.
			}
			break;
		case 2:
			if (record_1.length != 0) {
				op += "	unordered_set_" + std::to_string(current) + ".cbegin(); \n";//A const_iterator to the beginning of the sequence.
			}
			break;
		case 3:
			if (record_1.length != 0) {
				op += "	unordered_set_" + std::to_string(current) + ".cend(); \n";//A const_iterator to the element past the end of the sequence.
			}
			break;
		case 4:
			op += "	unordered_set_" + std::to_string(current) + ".clear(); \n";//clean all
			local_records[current].length = 0;
			break;
		case 5:
			op += "	unordered_set_" + std::to_string(current) + ".count(" + generate_unordered_set_element(record_1.type) + "); \n";//A const_iterator to the element past the end of the sequence.
			break;
		case 6:
			op += "	unordered_set_" + std::to_string(current) + ".bucket_size(" + std::to_string(random_Int(0, record_1.bucket_size - 1)) + "); \n";//A const_iterator to the element past the end of the sequence.
			break;
		case 7:
			op += "	unordered_set_" + std::to_string(current) + ".hash_function(); \n";
		case 8:
			if (record_1.type == "int" or record_1.type == "double" or record_1.type == "char" or record_1.type == "float" or record_1.type == "bool") {
				op += "	unordered_set_" + std::to_string(current) + ".emplace(" + generate_unordered_set_element(record_1.type) + "); \n";
			}
			else if (record_1.type == "std::unordered_set<int>")
				op += "	unordered_set_" + std::to_string(current) + ".emplace(std::unordered_set<int>" + generate_unordered_set_element(record_1.type) + "); \n";
			else if (record_1.type == "std::unordered_set<float>")
				op += "	unordered_set_" + std::to_string(current) + ".emplace(std::unordered_set<float>" + generate_unordered_set_element(record_1.type) + "); \n";
			else if (record_1.type == "std::unordered_set<double>")
				op += "	unordered_set_" + std::to_string(current) + ".emplace(std::unordered_set<double>" + generate_unordered_set_element(record_1.type) + "); \n";
			else if (record_1.type == "std::unordered_set<char>")
				op += "	unordered_set_" + std::to_string(current) + ".emplace(std::unordered_set<char>" + generate_unordered_set_element(record_1.type) + "); \n";
			else if (record_1.type == "std::unordered_set<bool>")
				op += "	unordered_set_" + std::to_string(current) + ".emplace(std::unordered_set<bool>" + generate_unordered_set_element(record_1.type) + "); \n";
			// If the function successfully inserts the element(because no equivalent element existed already in the set), 
			// the function returns a pair of an iterator to the newly inserted element and a value of true.
			if (record_1.type != "bool") {
				local_records[current].length += 1;
			}
			break;
		case 9:
			//TODO: need optimization
			//op += "set_" + std::to_string(current) + ".emplace_hint(set_" + std::to_string(current) + ".find(" + std::to_string(random_Int(1, 100)) + ")," + std::to_string(random_Int(1, 100)) + "); \n";
			break;
		case 10:
			op += "	unordered_set_" + std::to_string(current) + ".empty(); \n";//true if the container size is 0, false otherwise.
			break;
		case 11:
			if (record_1.length != 0) {
				op += "	unordered_set_" + std::to_string(current) + ".end(); \n";//An iterator to the past-the-end element in the container.
			}
			break;
		case 12:
			op += "	auto range_" + std::to_string(m) + " = unordered_set_" + std::to_string(current) + ".equal_range(" + generate_unordered_set_element(record_1.type) + "); \n";
			//The function returns a pair, whose member pair::first is the lower bound of the range (the same as lower_bound), and pair::second is the upper bound (the same as upper_bound).
			break;
		case 13:
			if (record_1.length != 0) {
				op += "	auto it_" + std::to_string(m) + " = next(unordered_set_" + std::to_string(current) + ".begin(), " + std::to_string(random_Int(0, record_1.length - 1)) + "); \n";
				op += "	unordered_set_" + std::to_string(current) + ".erase(it_" + std::to_string(m) + "); \n";//For the value-based version (2), the function returns the number of elements erased.
				local_records[current].length -= 1;
			}
			break;
		case 14:
			op += "	auto it_" + std::to_string(m) + " = unordered_set_" + std::to_string(current) + ".find(" + generate_unordered_set_element(record_1.type) + ");\n"; //An iterator to the element, if val is found, or set::end otherwise.
			break;
		case 15:
			op += "	unordered_set_" + std::to_string(current) + ".max_load_factor();\n";//Member type allocator_type is the type of the allocator used by the container, defined in set as an alias of its third template parameter
			break;
		case 16:
			op += "	unordered_set_" + std::to_string(current) + ".insert(" + generate_unordered_set_element(record_1.type) + "); \n";//For the value-based version (2), the function returns the number of elements erased.
			if (record_1.type != "std::unordered_set<bool>" or record_1.type != "bool") {
				local_records[current].length += 1;
			}
			break;
		case 17:
			op += "	unordered_set_" + std::to_string(current) + ".load_factor();\n";
			break;
		case 18:
			op += "	unordered_set_" + std::to_string(current) + ".bucket_count();\n";
			break;
		case 19:
			op += "	unordered_set_" + std::to_string(current) + ".max_size();\n"; //The maximum number of elements a set container can hold as content.
			break;
		case 20:
			op += "	unordered_set_" + std::to_string(current) + ".reserve("+ std::to_string(random_Int(0, 19)) +");\n";
		case 21:
			op += "	unordered_set_" + std::to_string(current) + ".bucket(" + generate_unordered_set_element(record_1.type) + ");\n";
		case 22:
			op += "	unordered_set_" + std::to_string(current) + ".size();\n"; //The number of elements in the container.
			break;
		case 23:
			if (record_1.type == record_2.type && current != current_2) {
				op += "	unordered_set_" + std::to_string(current) + ".swap(unordered_set_" + std::to_string(current_2) + ");\n"; // Swap two vectors
				tmp_length = local_records[current].length;
				tmp_length_2 = local_records[current_2].length;
				local_records[current].length = tmp_length_2;
				local_records[current_2].length = tmp_length;
			}
			break;
		case 24:
			op += "	unordered_set_" + std::to_string(current) + ".rehash(" + std::to_string(random_Int(0, 19)) + ");\n";
			//An iterator to the the first element in the container which is considered to go after val, or set::end if no elements are considered to go after val.
			break;
		case 25:
			op += "	auto eq_" + std::to_string(m) + " = unordered_set_" + std::to_string(current) + ".key_eq()(" + generate_unordered_set_element(record_1.type) + "," + generate_unordered_set_element(record_1.type) + ");\n";
			break;



		case 26:
			op += "	unordered_set_" + std::to_string(current) + ".max_bucket_count();\n";
			break;
		}


	}
	return op;
}






std::string create_unordered_set(int index) {
	std::string code;
	std::string oss;
	std::string type;
	int times = random_Int(1, 10);
	int unordered_set_elements_num = random_Int(5, 10);
	int unordered_set_rows = 2;// 1 for 1D vector
	std::unordered_set<int> temp_int = {};
	std::unordered_set<float> temp_float = {};
	std::unordered_set<double> temp_double = {};
	std::unordered_set<char> temp_char = {};
	std::unordered_set<bool> temp_bool = {};


	//temp 2D sets
	//std::unordered_set<std::unordered_set<int>> temp_2d_int;
	//std::unordered_set<std::unordered_set<double>> temp_2d_double;
	//std::unordered_set<std::unordered_set<char>> temp_2d_char;
	//std::unordered_set<std::unordered_set<bool>> temp_2d_bool;

	std::vector<unordered_set_records> unordered_set_records;

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

		case 6:
			type = "std::unordered_set<int>";
			data_type = INT_2D;

			break;
		case 7:
			type = "std::unordered_set<float>";
			data_type = FLOAT_2D;

			break;
		case 8:
			type = "std::unordered_set<double>";
			data_type = DOUBLE_2D;

			break;
		case 9:
			type = "std::unordered_set<char>";
			data_type = CHAR_2D;

			break;
		case 10:
			type = "std::unordered_set<bool>";
			data_type = BOOL_2D;

			break;

		}

		//if (data_type == INT_2D or data_type == DOUBLE_2D or data_type == CHAR_2D or data_type == FLOAT_2D or data_type == BOOL_2D) {


		//	for (int m = 1; m <= unordered_set_rows; m++) {

		//		switch (data_type) {
		//		case INT_2D: //int
		//			temp_int = create_unordered_set_int(unordered_set_elements_num);

		//			break;
		//		case FLOAT_2D: //float
		//			temp_float = create_unordered_set_float(unordered_set_elements_num);
		//			break;
		//		case DOUBLE_2D: //double
		//			temp_double = create_unordered_set_double(unordered_set_elements_num);
		//			break;
		//		case CHAR_2D: //char
		//			temp_char = create_unordered_set_char(unordered_set_elements_num);
		//			break;
		//		case BOOL_2D: //bool
		//			temp_bool = create_unordered_set_bool(unordered_set_elements_num);
		//			break;
		//		}
		//		if (data_type == INT_2D) {
		//			int temp_size = temp_int.size();
		//			temp_2d_int.insert(temp_int);
		//			for (int i = 1; i <= temp_size; i++) {
		//				auto it = temp_int.begin();
		//				advance(it, i - 1);
		//				auto value = *it;
		//				oss += std::to_string(value);
		//				if (i != temp_size) {
		//					oss += ", "; // Add a separator between numbers
		//				}
		//			}
		//			if (m < unordered_set_rows) {
		//				oss += "}, {";
		//			}
		//			else {
		//				oss += "}";
		//			}
		//			temp_int = {};
		//		}
		//		else if (data_type == FLOAT_2D) {
		//			int temp_size = temp_float.size();
		//			temp_2d_float.insert(temp_float);
		//			for (int i = 1; i <= temp_size; i++) {
		//				auto it = temp_float.begin();
		//				advance(it, i - 1);
		//				auto value = *it;
		//				oss += std::to_string(value);
		//				if (i != temp_size) {
		//					oss += ", "; // Add a separator between numbers
		//				}
		//			}
		//			if (m < unordered_set_rows) {
		//				oss += "}, {";
		//			}
		//			else {
		//				oss += "}";
		//			}
		//			temp_float = {};
		//		}


		//		else if (data_type == DOUBLE_2D) {
		//			int temp_size = temp_double.size();
		//			temp_2d_double.insert(temp_double);
		//			for (int i = 1; i <= temp_size; i++) {
		//				auto it = temp_double.begin();
		//				advance(it, i - 1);
		//				auto value = *it;
		//				oss += std::to_string(value);
		//				if (i != temp_size) {
		//					oss += ", "; // Add a separator between numbers
		//				}
		//			}
		//			if (m < unordered_set_rows) {
		//				oss += "}, {";
		//			}
		//			else {
		//				oss += "}";
		//			}

		//			temp_double = {};
		//		}

		//		else if (data_type == CHAR_2D) {
		//			int temp_size = temp_char.size();
		//			temp_2d_char.insert(temp_char);
		//			for (int i = 1; i <= temp_size; i++) {
		//				auto it = temp_char.begin();
		//				advance(it, i - 1);
		//				auto value = *it;
		//				oss += std::to_string(value);
		//				if (i != temp_size) {
		//					oss += ", "; // Add a separator between numbers
		//				}
		//			}
		//			if (m < unordered_set_rows) {
		//				oss += "}, {";
		//			}
		//			else {
		//				oss += "}";
		//			}
		//			temp_char = {};
		//		}

		//		else {
		//			int temp_size = temp_bool.size();
		//			temp_2d_bool.insert(temp_bool);
		//			for (int i = 1; i <= temp_size; i++) {
		//				auto it = temp_bool.begin();
		//				advance(it, i - 1);
		//				auto value = *it;
		//				oss += std::to_string(value);
		//				if (i != temp_size) {
		//					oss += ", "; // Add a separator between numbers
		//				}
		//			}
		//			if (m < unordered_set_rows) {
		//				oss += "}, {";
		//			}
		//			else {
		//				oss += "}";
		//			}
		//			temp_bool = {};
		//		}


		//	}


		//	if (data_type == INT_2D) {
		//		unordered_set_records.push_back({ unordered_set_rows, type, int(temp_2d_int.bucket_count()) });
		//		temp_2d_int.clear();
		//	}
		//	else if (data_type == DOUBLE_2D) {
		//		unordered_set_records.push_back({ unordered_set_rows, type, int(temp_2d_double.bucket_count()) });
		//		temp_2d_double.clear();
		//	}
		//	else if (data_type == CHAR_2D) {
		//		unordered_set_records.push_back({ unordered_set_rows, type, int(temp_2d_char.bucket_count()) });
		//		temp_2d_char.clear();
		//	}
		//	else if (data_type == FLOAT_2D) {
		//		unordered_set_records.push_back({ unordered_set_rows, type, int(temp_2d_float.bucket_count()) });
		//		temp_2d_float.clear();
		//	}

		//	else {
		//		unordered_set_records.push_back({ 1, type, int(temp_2d_bool.bucket_count())});
		//		temp_2d_bool.clear();
		//	}

		//	code += "	std::unordered_set<" + type + "> unordered_set_" + std::to_string(n) + " = { {" + oss + " };\n";
		//	oss = {};

		//}



			switch (data_type) {
			case INT:
				temp_int = create_unordered_set_int(unordered_set_elements_num);
				break;

			case FLOAT:
				temp_float = create_unordered_set_float(unordered_set_elements_num);
				break;

			case DOUBLE:
				temp_double = create_unordered_set_double(unordered_set_elements_num);
				break;

			case CHAR:
				temp_char = create_unordered_set_char(unordered_set_elements_num);
				break;

			case BOOL:
				temp_bool = create_unordered_set_bool(unordered_set_elements_num);
				break;

			}



			if (data_type == INT) {
				int temp_size = temp_int.size();
				unordered_set_records.push_back({ temp_size, type,int(temp_int.bucket_count())});
				for (int i = 1; i <= temp_size; i++) {
					auto it = temp_int.begin();
					std::advance(it, i - 1);
					auto value = *it;
					oss += std::to_string(value);
					if (i != temp_size) {
						oss += ", "; // Add a separator between numbers
					}
				}

				temp_int = {};
			}
			else if (data_type == FLOAT) {
				int temp_size = temp_float.size();
				unordered_set_records.push_back({ temp_size, type, int(temp_float.bucket_count())});
				for (int i = 1; i <= temp_size; i++) {
					auto it = temp_float.begin();
					std::advance(it, i - 1);
					auto value = *it;
					oss += std::to_string(value);
					if (i != temp_size) {
						oss += ", "; // Add a separator between numbers
					}
				}

				temp_float = {};
			}


			else if (data_type == DOUBLE) {
				int temp_size = temp_double.size();
				unordered_set_records.push_back({ temp_size, type, int(temp_double.bucket_count())});
				for (int i = 1; i <= temp_size; i++) {
					auto it = temp_double.begin();
					std::advance(it, i - 1);
					auto value = *it;
					oss += std::to_string(value);
					if (i != temp_size) {
						oss += ", "; // Add a separator between numbers
					}
				}

				temp_double = {};
			}

			else if (data_type == CHAR) {
				int temp_size = temp_char.size();
				unordered_set_records.push_back({ temp_size, type, int(temp_char.bucket_count())});
				for (int i = 1; i <= temp_size; i++) {
					auto it = temp_char.begin();
					std::advance(it, i - 1);
					auto value = *it;
					oss += std::to_string(value);
					if (i != temp_size) {
						oss += ", "; // Add a separator between numbers
					}
				}

				temp_char = {};
			}

			else {
				int temp_size = temp_bool.size();
				unordered_set_records.push_back({ 2, type,int(temp_bool.bucket_count())});
				for (int i = 1; i <= temp_size; i++) {
					auto it = temp_bool.begin();
					std::advance(it, i - 1);
					auto value = *it;
					oss += std::to_string(value);
					if (i != temp_size) {
						oss += ", "; // Add a separator between numbers
					}
				}
				temp_bool = {};
			}


			//print out secton

			code += "	std::unordered_set<" + type + "> unordered_set_" + std::to_string(n) + " = {" + oss + "};\n";
			oss = {};

		

	}

	//random operations generated
	code += random_unordered_set_op(index, unordered_set_records);

	//code += "	std::vector<uint8_t> buffer;\n";
	for (int m = 0; m < index; m++) {
		code += "	std::vector<" + unordered_set_records[m].type + "> newunordered_set_" + std::to_string(m) + ";\n";
		code += "   for (auto& elem_"+std::to_string(m) + " : unordered_set_0) {\n";
		code += "   		newunordered_set_" + std::to_string(m) + ".push_back(elem_" + std::to_string(m)+ ");\n";
		code += "    }\n";
		code += "	append_data(buffer, newunordered_set_" + std::to_string(m) + ");\n";

	}


	code += "\n";

	return code;


}
