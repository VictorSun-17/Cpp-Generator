#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <string>
#include "Random_program.h"
#include <sstream>
#include <unordered_map>
#include <unordered_set>



std::vector<int> create_unordered_map_int(int length = 1) {
	std::vector<int> temp;
	for (int n = 1; n <= length; n++) {
		switch (random_Int(1, 2)) {
		case 1:
			temp.push_back(random_Int(-100, 100));
			break;

		case 2:
			temp.push_back(random_Bool());
			break;
		}
	}
	return temp;
}

std::vector<float> create_unordered_map_float(int length = 1) {
	std::vector<float> temp;
	for (int n = 1; n <= length; n++) {
		switch (random_Int(1, 2)) {
		case 1:
			temp.push_back(random_Int(-100, 100));
			break;

		case 2:
			temp.push_back(random_Bool());
			break;

		case 3:
			temp.push_back(random_Float(-100, 100));
			break;
		}
	}
	return temp;
}

std::vector<double> create_unordered_map_double(int length = 1) {
	std::vector<double> temp;
	for (int n = 1; n <= length; n++) {
		switch (random_Int(1, 4)) {
		case 1:
			temp.push_back(random_Int(-100, 100));
			break;

		case 2:
			temp.push_back(random_Bool());
			break;

		case 3:
			temp.push_back(random_Float(-100, 100));
			break;

		case 4:
			temp.push_back(random_Double(-100, 100));
			break;
		}
	}
	return temp;
}

std::vector<char> create_unordered_map_char(int length = 1) {
	std::vector<char> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_Char());
	}
	return temp;
}

std::vector<bool> create_unordered_map_bool(int length = 1) {
	std::vector<bool> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_Bool());
	}
	return temp;
}
std::string generate_unordered_map_element(std::string type_1, std::string type_2) {
	std::string op;
	int vec_elements_num = random_Int(5, 10);
	op += "{";
	if (type_1 == "int")
		op += std::to_string(random_Int(-100, 100));
	else if (type_1 == "float")
		op += std::to_string(random_Float(-100, 100));
	else if (type_1 == "double")
		op += std::to_string(random_Double(-100, 100));
	else if (type_1 == "char")
		op += std::to_string(random_Char());
	else if (type_1 == "bool")
		op += std::to_string(random_Bool());

	op += ",";

	if (type_2 == "int")
		op += std::to_string(random_Int(-100, 100));
	else if (type_2 == "float")
		op += std::to_string(random_Float(-100, 100));
	else if (type_2 == "double")
		op += std::to_string(random_Double(-100, 100));
	else if (type_2 == "char")
		op += std::to_string(random_Char());
	else if (type_2 == "bool")
		op += std::to_string(random_Bool());

	op += "}";

	return op;
}

std::string generate_unordered_key_element(std::string type) {
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
}

std::string generate_unordered_value_element(std::string type) {
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
}

struct unordered_map_records {
	int length;
	int bucket_number;
	std::string type_1;
	std::string type_2;
};



std::string random_unordered_map_op(int n, std::vector<unordered_map_records> records) {
	std::string op;
	int operation_numbers = random_Int(10, 10);
	int current = 0;
	int current_2 = 0;
	std::vector<unordered_map_records> local_records = records;
	int random_size = random_Int(0, 19);

	//移出所有已生成函数的rdm

	for (int m = 1; m <= operation_numbers; m++) {
		current = random_Int(0, n - 1);
		current_2 = random_Int(0, n - 1);
		auto record_1 = local_records.at(current);
		auto record_2 = local_records.at(current_2);
		int tmp_length;
		int tmp_length_2;
		switch (random_Int(1, 25)) {

		case 1:
			if (record_1.type_1 != "bool") {
				op += "	unordered_map_" + std::to_string(current) + ".insert(" + generate_unordered_map_element(record_1.type_1, record_1.type_2) + "); \n"; //insert at certain place
				local_records[current].length += 1;
			}
			break;
		case 2:
			op += "	unordered_map_" + std::to_string(current) + ".count(" + generate_unordered_key_element(record_1.type_1) + "); \n";
		case 3:
			if (record_1.length != 0) {
				op += "	unordered_map_" + std::to_string(current) + ".equal_range(" + generate_unordered_key_element(record_1.type_1) + "); \n";
			}
		case 4:
			if (record_1.length != 0) {
				op += "	auto unordered_map_it_" + std::to_string(m) + " = next(unordered_map_" + std::to_string(current) + ".begin()," + std::to_string(random_Int(0, record_1.length - 1)) + "); \n";
				op += "	unordered_map_" + std::to_string(current) + ".erase( unordered_map_it_" + std::to_string(m) + "->first); \n";
				local_records[current].length -= 1;
			}
			break;
		case 5:
			if (record_1.length != 0) {
				op += "	unordered_map_" + std::to_string(current) + ".begin();\n"; //Returns an iterator pointing to the first element of the vector
			}
			break;
		case 6:
			if (record_1.length != 0) {
				op += "	unordered_map_" + std::to_string(current) + ".end();\n"; // Returns an iterator pointing to the past-the-end element of the vector
			}
			break;
		case 7:
			op += "	unordered_map_" + std::to_string(current) + ".find(" + generate_unordered_key_element(record_1.type_1) + "); \n";
			break;
		case 8:
			op += "	unordered_map_" + std::to_string(current) + ".cbegin();\n"; //Returns const_iterator to beginning
			break;
		case 9:
			op += "	unordered_map_" + std::to_string(current) + ".cend();\n"; // Returns const_iterator to end
			break;
		case 10:
			if (record_1.length != 0) {
				op += "	auto  unordered_map_it_" + std::to_string(m) + " = next(unordered_map_" + std::to_string(current) + ".begin()," + std::to_string(random_Int(0, record_1.length - 1)) + "); \n";
				op += "	unordered_map_" + std::to_string(current) + ".bucket( unordered_map_it_" + std::to_string(m) + "->first);\n"; //Returns const_reverse_iterator to reverse beginning
			}
			break;
		case 11:
			op += "	unordered_map_" + std::to_string(current) + ".bucket_count();\n"; // Returns const_reverse_iterator to reverse end
			break;

		case 12:

			if (record_1.type_1 == "int" or record_1.type_1 == "double" or record_1.type_1 == "char" or record_1.type_1 == "float" or record_1.type_1 == "bool") {

				op += "	unordered_map_" + std::to_string(current) + ".emplace(" + generate_unordered_key_element(record_1.type_1) + "," + generate_unordered_value_element(record_1.type_2) + "); \n"; // Constructs and inserts an element in the vector.

			}
			if (record_1.type_1 == "int" or record_1.type_1 == "double" or record_1.type_1 == "char" or record_1.type_1 == "float" /*or record_1.type_1 == "bool"*/)
				local_records[current].length += 1;
			break;

		case 13:
			op += "	unordered_map_" + std::to_string(current) + ".max_size();\n"; //Returns the maximum number of elements that the vector can hold.
			break;

		case 14:
			op += "	unordered_map_" + std::to_string(current) + ".bucket_size(" + std::to_string(random_Int(0, record_1.bucket_number - 1)) + ");\n"; // Returns const_reverse_iterator to reverse end
			//An iterator to the the first element in the container which is considered to go after val, or set::end if no elements are considered to go after val.
			break;
		case 15:

			//if (record_1.type_1 == "int" or record_1.type_1 == "double" or record_1.type_1 == "char" or record_1.type_1 == "float" or record_1.type_1 == "bool") {

			//	op += "	unordered_map_" + std::to_string(current) + ".emplace_hint(unordered_map_" + std::to_string(current) + ".begin() " + "," + generate_unordered_key_element(record_1.type_1) + "," + generate_unordered_value_element(record_1.type_2) + "); \n"; // Constructs and inserts an element in the vector.

			//}
			//if (record_1.type_1 == "int" or record_1.type_1 == "double" or record_1.type_1 == "char" or record_1.type_1 == "float" /*or record_1.type_1 == "bool"*/)
			//	local_records[current].length += 1;
			break;

		case 16:
			op += "	auto mycomp_" + std::to_string(m) + " = unordered_map_" + std::to_string(current) + ".max_bucket_count();\n"; //The comparison object.
			break;
		case 17:
			op += "	unordered_map_" + std::to_string(current) + ".size();\n"; //Returns the number of elements in the vector.
			break;
		case 18:
			op += "	unordered_map_" + std::to_string(current) + ".empty();\n"; //Checks if the vector is empty.
			break;
		case 19:
			op += "	unordered_map_" + std::to_string(current) + ".clear();\n";
			local_records[current].length = 0;
			break;
		case 20:
			if (record_1.length != 0) {
				//op += "	map_" + std::to_string(current) + ".at(" + generate_key_element(record_1.type_1) + "); \n"; //Accesses the element at a specific position, with bounds checking.
			}
			break;
		case 21:
			if (record_1.type_1 == record_2.type_1 && record_1.type_2 == record_2.type_2 && current != current_2) {
				op += "	unordered_map_" + std::to_string(current) + ".swap(unordered_map_" + std::to_string(current_2) + ");\n"; // Swap two vectors
				tmp_length = local_records[current].length;
				tmp_length_2 = local_records[current_2].length;
				local_records[current].length = tmp_length_2;
				local_records[current_2].length = tmp_length;
			}
			break;





		}

	}




	return op;
}





std::string create_unoredered_map(int index) {
	std::string code;
	std::string oss;
	std::string type_1;
	std::string type_2;
	int unordered_map_elements_num = random_Int(5, 10);
	/*int vec_rows = random_Int(1, 2);*/
	//int unordered_map_rows = 2;// 1 for 1D vector
	int temp_length = 0;
	//temp vectors
	std::vector<int> temp_int_2 = {};
	std::vector<float> temp_float_2 = {};
	std::vector<double> temp_double_2 = {};
	std::vector<char> temp_char_2 = {};
	std::vector<bool> temp_bool_2 = {};

	std::vector<int> temp_int_1 = {};
	std::vector<float> temp_float_1 = {};
	std::vector<double> temp_double_1 = {};
	std::vector<char> temp_char_1 = {};
	std::vector<bool> temp_bool_1 = {};

	std::unordered_set<int> temp_set_int = {};
	std::unordered_set<float> temp_set_float = {};
	std::unordered_set<double> temp_set_double = {};
	std::unordered_set<char> temp_set_char = {};
	std::unordered_set<bool> temp_set_bool = {};

	std::unordered_map<int, int> unordered_int_int = {};
	std::unordered_map<int, float> unordered_int_float = {};
	std::unordered_map<int, double> unordered_int_double = {};
	std::unordered_map<int, char> unordered_int_char = {};
	std::unordered_map<int, bool> unordered_int_bool = {};
	std::unordered_map<float, int> unordered_float_int = {};
	std::unordered_map<float, float> unordered_float_float = {};
	std::unordered_map<float, double> unordered_float_double = {};
	std::unordered_map<float, char> unordered_float_char = {};
	std::unordered_map<float, bool> unordered_float_bool = {};
	std::unordered_map<double, int> unordered_double_int = {};
	std::unordered_map<double, float> unordered_double_float = {};
	std::unordered_map<double, double> unordered_double_double = {};
	std::unordered_map<double, char> unordered_double_char = {};
	std::unordered_map<double, bool> unordered_double_bool = {};
	std::unordered_map<char, int> unordered_char_int = {};
	std::unordered_map<char, float> unordered_char_float = {};
	std::unordered_map<char, double> unordered_char_double = {};
	std::unordered_map<char, char> unordered_char_char = {};
	std::unordered_map<char, bool> unordered_char_bool = {};
	std::unordered_map<bool, int> unordered_bool_int = {};
	std::unordered_map<bool, float> unordered_bool_float = {};
	std::unordered_map<bool, double> unordered_bool_double = {};
	std::unordered_map<bool, char> unordered_bool_char = {};
	std::unordered_map<bool, bool> unordered_bool_bool = {};

	std::vector<unordered_map_records> map_records;





	for (int n = 0; n < index; n++) {

		switch (random_Int(1, 5))
			/*switch (1)*/ {
		case 1:
			type_1 = "int";
			break;
		case 2:
			type_1 = "float";
			break;
		case 3:
			type_1 = "double";
			break;
		case 4:
			type_1 = "char";
			break;
		case 5:
			type_1 = "bool";
			break;
		}
		switch (random_Int(1, 5))
			/*switch (1)*/ {
		case 1:
			type_2 = "int";
			break;
		case 2:
			type_2 = "float";
			break;
		case 3:
			type_2 = "double";
			break;
		case 4:
			type_2 = "char";
			break;
		case 5:
			type_2 = "bool";
			break;
		}



		//vec_records.push_back({ vec_elements_num, type });





		if (type_1 == "int") {
			temp_int_1 = create_unordered_map_int(unordered_map_elements_num);
			temp_set_int.insert(temp_int_1.begin(), temp_int_1.end());
			temp_length = temp_set_int.size();
		}
		else if (type_1 == "float") {
			temp_float_1 = create_unordered_map_float(unordered_map_elements_num);
			temp_set_float.insert(temp_float_1.begin(), temp_float_1.end());
			temp_length = temp_set_float.size();
		}
		else if (type_1 == "double")
		{
			temp_double_1 = create_unordered_map_double(unordered_map_elements_num);
			temp_set_double.insert(temp_double_1.begin(), temp_double_1.end());
			temp_length = temp_set_double.size();
		}
		else if (type_1 == "char") {
			temp_char_1 = create_unordered_map_char(unordered_map_elements_num);
			temp_set_char.insert(temp_char_1.begin(), temp_char_1.end());
			temp_length = temp_set_char.size();
		}
		else if (type_1 == "bool") {
			temp_bool_1 = create_unordered_map_bool(unordered_map_elements_num);
			temp_set_bool.insert(temp_bool_1.begin(), temp_bool_1.end());
			temp_length = temp_set_bool.size();
		}

		if (type_2 == "int") {
			temp_int_2 = create_unordered_map_int(unordered_map_elements_num);
		}
		else if (type_2 == "float") {
			temp_float_2 = create_unordered_map_float(unordered_map_elements_num);
		}
		else if (type_2 == "double")
		{
			temp_double_2 = create_unordered_map_double(unordered_map_elements_num);
		}
		else if (type_2 == "char") {
			temp_char_2 = create_unordered_map_char(unordered_map_elements_num);
		}
		else if (type_2 == "bool") {
			temp_bool_2 = create_unordered_map_bool(unordered_map_elements_num);
		}

		//set up unordered map for latter bucket_size
		for (int i = 1; i <= temp_length; i++) {
			if (type_1 == "int") {
				auto it = temp_set_int.begin();
				std::advance(it, i - 1);
				auto value = *it;
				if (type_2 == "int")
					unordered_int_int.emplace(value, temp_int_2[i - 1]);
				else if (type_2 == "float")
					unordered_int_float.emplace(value, temp_float_2[i - 1]);
				else if (type_2 == "double")
					unordered_int_double.emplace(value, temp_double_2[i - 1]);
				else if (type_2 == "char")
					unordered_int_char.emplace(value, temp_char_2[i - 1]);
				else if (type_2 == "bool")
					unordered_int_bool.emplace(value, temp_bool_2[i - 1]);
			}
			else if (type_1 == "float") {
				auto it = temp_set_float.begin();
				std::advance(it, i - 1);
				auto value = *it;
				if (type_2 == "int")
					unordered_float_int.emplace(value, temp_int_2[i - 1]);
				else if (type_2 == "float")
					unordered_float_float.emplace(value, temp_float_2[i - 1]);
				else if (type_2 == "double")
					unordered_float_double.emplace(value, temp_double_2[i - 1]);
				else if (type_2 == "char")
					unordered_float_char.emplace(value, temp_char_2[i - 1]);
				else if (type_2 == "bool")
					unordered_float_bool.emplace(value, temp_bool_2[i - 1]);
			}
			else if (type_1 == "double") {
				auto it = temp_set_double.begin();
				std::advance(it, i - 1);
				auto value = *it;
				if (type_2 == "int")
					unordered_double_int.emplace(value, temp_int_2[i - 1]);
				else if (type_2 == "float")
					unordered_double_float.emplace(value, temp_float_2[i - 1]);
				else if (type_2 == "double")
					unordered_double_double.emplace(value, temp_double_2[i - 1]);
				else if (type_2 == "char")
					unordered_double_char.emplace(value, temp_char_2[i - 1]);
				else if (type_2 == "bool")
					unordered_double_bool.emplace(value, temp_bool_2[i - 1]);
			}
			else if (type_1 == "char") {
				auto it = temp_set_char.begin();
				std::advance(it, i - 1);
				auto value = *it;
				if (type_2 == "int")
					unordered_char_int.emplace(value, temp_int_2[i - 1]);
				else if (type_2 == "float")
					unordered_char_float.emplace(value, temp_float_2[i - 1]);
				else if (type_2 == "double")
					unordered_char_double.emplace(value, temp_double_2[i - 1]);
				else if (type_2 == "char")
					unordered_char_char.emplace(value, temp_char_2[i - 1]);
				else if (type_2 == "bool")
					unordered_char_bool.emplace(value, temp_bool_2[i - 1]);
			}
			else if (type_1 == "bool") {
				auto it = temp_set_bool.begin();
				std::advance(it, i - 1);
				auto value = *it;
				if (type_2 == "int")
					unordered_bool_int.emplace(value, temp_int_2[i - 1]);
				else if (type_2 == "float")
					unordered_bool_float.emplace(value, temp_float_2[i - 1]);
				else if (type_2 == "double")
					unordered_bool_double.emplace(value, temp_double_2[i - 1]);
				else if (type_2 == "char")
					unordered_bool_char.emplace(value, temp_char_2[i - 1]);
				else if (type_2 == "bool")
					unordered_bool_bool.emplace(value, temp_bool_2[i - 1]);
			}
		}

		if (type_1 == "int") {
			if (type_2 == "int")
				map_records.push_back({ temp_length,int(unordered_int_int.bucket_count()), type_1,type_2 });
			else if (type_2 == "float")
				map_records.push_back({ temp_length,int(unordered_int_float.bucket_count()), type_1,type_2 });
			else if (type_2 == "double")
				map_records.push_back({ temp_length,int(unordered_int_double.bucket_count()), type_1,type_2 });
			else if (type_2 == "char")
				map_records.push_back({ temp_length,int(unordered_int_char.bucket_count()), type_1,type_2 });
			else if (type_2 == "bool")
				map_records.push_back({ temp_length,int(unordered_int_bool.bucket_count()), type_1,type_2 });
		}
		else if (type_1 == "float") {
			if (type_2 == "int")
				map_records.push_back({ temp_length,int(unordered_float_int.bucket_count()), type_1,type_2 });
			else if (type_2 == "float")
				map_records.push_back({ temp_length,int(unordered_float_float.bucket_count()), type_1,type_2 });
			else if (type_2 == "double")
				map_records.push_back({ temp_length,int(unordered_float_double.bucket_count()), type_1,type_2 });
			else if (type_2 == "char")
				map_records.push_back({ temp_length,int(unordered_float_char.bucket_count()), type_1,type_2 });
			else if (type_2 == "bool")
				map_records.push_back({ temp_length,int(unordered_float_bool.bucket_count()), type_1,type_2 });
		}
		else if (type_1 == "double") {
			if (type_2 == "int")
				map_records.push_back({ temp_length,int(unordered_double_int.bucket_count()), type_1,type_2 });
			else if (type_2 == "float")
				map_records.push_back({ temp_length,int(unordered_double_float.bucket_count()), type_1,type_2 });
			else if (type_2 == "double")
				map_records.push_back({ temp_length,int(unordered_double_double.bucket_count()), type_1,type_2 });
			else if (type_2 == "char")
				map_records.push_back({ temp_length,int(unordered_double_char.bucket_count()), type_1,type_2 });
			else if (type_2 == "bool")
				map_records.push_back({ temp_length,int(unordered_double_bool.bucket_count()), type_1,type_2 });
		}
		else if (type_1 == "char") {
			if (type_2 == "int")
				map_records.push_back({ temp_length,int(unordered_char_int.bucket_count()), type_1,type_2 });
			else if (type_2 == "float")
				map_records.push_back({ temp_length,int(unordered_char_float.bucket_count()), type_1,type_2 });
			else if (type_2 == "double")
				map_records.push_back({ temp_length,int(unordered_char_double.bucket_count()), type_1,type_2 });
			else if (type_2 == "char")
				map_records.push_back({ temp_length,int(unordered_char_char.bucket_count()), type_1,type_2 });
			else if (type_2 == "bool")
				map_records.push_back({ temp_length,int(unordered_char_bool.bucket_count()), type_1,type_2 });
		}
		else if (type_1 == "bool") {
			if (type_2 == "int")
				map_records.push_back({ temp_length,int(unordered_bool_int.bucket_count()), type_1,type_2 });
			else if (type_2 == "float")
				map_records.push_back({ temp_length,int(unordered_bool_float.bucket_count()), type_1,type_2 });
			else if (type_2 == "double")
				map_records.push_back({ temp_length,int(unordered_bool_double.bucket_count()), type_1,type_2 });
			else if (type_2 == "char")
				map_records.push_back({ temp_length,int(unordered_bool_char.bucket_count()), type_1,type_2 });
			else if (type_2 == "bool")
				map_records.push_back({ temp_length,int(unordered_bool_bool.bucket_count()), type_1,type_2 });
		}





		for (int i = 1; i <= temp_length; i++) {
			oss += "{";
			if (type_1 == "int") {
				auto it = temp_set_int.begin();
				std::advance(it, i - 1);
				auto value = *it;
				oss += std::to_string(value);
			}
			else if (type_1 == "float") {
				auto it = temp_set_float.begin();
				std::advance(it, i - 1);
				auto value = *it;
				oss += std::to_string(value);
			}
			else if (type_1 == "double") {
				auto it = temp_set_double.begin();
				std::advance(it, i - 1);
				auto value = *it;
				oss += std::to_string(value);
			}
			else if (type_1 == "char") {
				auto it = temp_set_char.begin();
				std::advance(it, i - 1);
				auto value = *it;
				oss += std::to_string(value);
			}
			else if (type_1 == "bool")
			{
				auto it = temp_set_bool.begin();
				std::advance(it, i - 1);
				auto value = *it;
				oss += std::to_string(value);
			}
			oss += ",";
			if (type_2 == "int")
				oss += std::to_string(temp_int_2[i - 1]);
			else if (type_2 == "float")
				oss += std::to_string(temp_float_2[i - 1]);
			else if (type_2 == "double")
				oss += std::to_string(temp_double_2[i - 1]);
			else if (type_2 == "char")
				oss += std::to_string(temp_char_2[i - 1]);
			else if (type_2 == "bool")
				oss += std::to_string(temp_bool_2[i - 1]);
			oss += "}";
			if (i != temp_length) {
				oss += ", "; // Add a separator between numbers
			}
		}




		temp_bool_1 = {};
		temp_char_1 = {};
		temp_float_1 = {};
		temp_int_1 = {};
		temp_double_1 = {};
		temp_bool_2 = {};
		temp_char_2 = {};
		temp_float_2 = {};
		temp_int_2 = {};
		temp_double_2 = {};
		temp_set_int = {};
		temp_set_float = {};
		temp_set_double = {};
		temp_set_char = {};
		temp_set_bool = {};

		unordered_int_int = {};
		unordered_int_float = {};
		unordered_int_double = {};
		unordered_int_char = {};
		unordered_int_bool = {};
		unordered_float_int = {};
		unordered_float_float = {};
		unordered_float_double = {};
		unordered_float_char = {};
		unordered_float_bool = {};
		unordered_double_int = {};
		unordered_double_float = {};
		unordered_double_double = {};
		unordered_double_char = {};
		unordered_double_bool = {};
		unordered_char_int = {};
		unordered_char_float = {};
		unordered_char_double = {};
		unordered_char_char = {};
		unordered_char_bool = {};
		unordered_bool_int = {};
		unordered_bool_float = {};
		unordered_bool_double = {};
		unordered_bool_char = {};
		unordered_bool_bool = {};
		temp_length = 0;


		code += "	std::unordered_map<" + type_1 + "," + type_2 + "> unordered_map_" + std::to_string(n) + " = {" + oss + "};\n";
		oss = {};



	}
	//random operations generated
	code += random_unordered_map_op(index, map_records);

	for (int m = 0; m < index; m++) {
		code += "	std::pair<std::vector<" + map_records[m].type_1 + ">,std::vector<" + map_records[m].type_2 + ">> newunordered_map_" + std::to_string(m) + " = map_to_vectors(unordered_map_" + std::to_string(m) + ");\n";
		code += "	append_data(buffer, newunordered_map_" + std::to_string(m) + ".first);\n";
		code += "	append_data(buffer, newunordered_map_" + std::to_string(m) + ".second);\n";
	}




	code += "\n";
	return code;
}

