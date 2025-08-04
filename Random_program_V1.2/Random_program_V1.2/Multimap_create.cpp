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
#include <any>
#include <variant>


std::vector<int> create_multimap_int(int length = 1) {
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

std::vector<float> create_multimap_float(int length = 1) {
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

std::vector<double> create_multimap_double(int length = 1) {
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

std::vector<char> create_multimap_char(int length = 1) {
	std::vector<char> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_Char());
	}
	return temp;
}

std::vector<bool> create_multimap_bool(int length = 1) {
	std::vector<bool> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_Bool());
	}
	return temp;
}


using VariantType = std::variant<int, float, double, char, bool>;

std::pair<VariantType, VariantType>
create_key_value_pair(const std::string& type_1, const std::string& type_2) {
	VariantType temp_1, temp_2;

	if (type_1 == "int")
		temp_1 = random_Int(-100, 100);
	else if (type_1 == "float")
		temp_1 = random_Float(-100, 100);
	else if (type_1 == "double")
		temp_1 = random_Double(-100, 100);
	else if (type_1 == "char")
		temp_1 = random_Char();
	else if (type_1 == "bool")
		temp_1 = random_Bool();

	if (type_2 == "int")
		temp_2 = random_Int(-100, 100);
	else if (type_2 == "float")
		temp_2 = random_Float(-100, 100);
	else if (type_2 == "double")
		temp_2 = random_Double(-100, 100);
	else if (type_2 == "char")
		temp_2 = random_Char();
	else if (type_2 == "bool")
		temp_2 = random_Bool();

	return std::make_pair(temp_1, temp_2);
}


std::string generate_multimap_element(std::string type_1, std::string type_2) {
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

std::string generate_multi_key_element(std::string type) {
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

std::string generate_multi_value_element(std::string type) {
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

struct multimap_records {
	int length;
	std::string type_1;
	std::string type_2;
};

std::vector<multimap_records> merge_records_min_length(
	const std::vector<multimap_records>& records1,
	const std::vector<multimap_records>& records2
) {
	std::vector<multimap_records> merged;
	size_t size = std::min(records1.size(), records2.size());
	merged.reserve(size);

	for (size_t i = 0; i < size; ++i) {
		multimap_records merged_record;
		merged_record.type_1 = records1[i].type_1; // 你也可以选择 records2[i].type 或做一致性判断
		merged_record.type_2 = records1[i].type_2;
		merged_record.length = std::min(records1[i].length, records2[i].length);
		merged.push_back(merged_record);
	}

	return merged;
}
template<typename K, typename V>
std::string multimap_to_string(const std::multimap<K, V>& mm) {
	std::ostringstream oss;
	oss << "{";
	for (auto it = mm.begin(); it != mm.end(); ++it) {
		oss << "{";
		oss << std::to_string(it->first) << "," << std::to_string(it->second);
		oss << "}";
		auto next_it = it;
		++next_it;
		if (next_it != mm.end()) {
			oss << ", ";
		}
	}
	oss << "}";
	return oss.str();
}
std::string all_op(int n, std::vector<multimap_records> records) {
	int current = 0;
	int current_2 = 0;
	std::vector<multimap_records> local_records = records;
	int operation_numbers = random_Int(1, 1);
	std::string op = {};

	for (int m = 1; m <= operation_numbers; m++) {
		current = random_Int(0, n - 1);
		current_2 = random_Int(0, n - 1);
		auto record_1 = local_records.at(current);
		auto record_2 = local_records.at(current_2);
		int tmp_length;
		int tmp_length_2;
		if (record_1.type_1 == record_2.type_1 && record_1.type_2 == record_2.type_2 && current != current_2) {
		op += "	multimap_" + std::to_string(current) + ".swap(multimap_" + std::to_string(current_2) + ");\n"; // Swap two vectors
		tmp_length = local_records[current].length;
		tmp_length_2 = local_records[current_2].length;
		local_records[current].length = tmp_length_2;
		local_records[current_2].length = tmp_length;
	}
	}
	return op;
}

template<typename K, typename V>
std::tuple<std::string, std::vector<multimap_records>, std::multimap<K, V>> random_multimap_op(int n, std::vector<multimap_records> records,std::multimap<K, V> mm, int operation_numbers = 3, int loop_index = 1, int loop_mode =0) {
	auto temp_mm = mm;
	std::string op;
	int current_length = 0;
	int current = n;
	//int current_2 = 0;
	std::vector<multimap_records> local_records = records;

	//移出所有已生成函数的rdm

	for (int m = 1; m <= operation_numbers; m++) {
		//current = random_Int(0, n - 1);
		//current_2 = random_Int(0, n - 1);
		auto record_1 = local_records.at(n);
		//auto record_2 = local_records.at(current_2);
		//int tmp_length;
		//int tmp_length_2;
		current_length = temp_mm.size();
		auto [v1, v2] = create_key_value_pair(record_1.type_1, record_1.type_2);
		int random_index_erase = random_Int(0, current_length - 1);

		// 提取 v2

		//std::string temp_key_value_string = std::to_string(temp_key_value);
		switch (random_Int(1, 23)) {

		case 1:
			
			if (record_1.type_1 == "int") {
				int key = std::get<int>(v1);
				if (record_1.type_2 == "int") {
					int value = std::get<int>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key)+"," +std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
				else if (record_1.type_2 == "float") {
					float value = std::get<float>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
				else if (record_1.type_2 == "double") {
					double value = std::get<double>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
				else if (record_1.type_2 == "char") {
					char value = std::get<char>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
				else if (record_1.type_2 == "bool") {
					bool value = std::get<bool>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
			}
			else if (record_1.type_1 == "float") {
				float key = std::get<float>(v1);
				if (record_1.type_2 == "int") {
					int value = std::get<int>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
				else if (record_1.type_2 == "float") {
					float value = std::get<float>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
				else if (record_1.type_2 == "double") {
					double value = std::get<double>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
				else if (record_1.type_2 == "char") {
					char value = std::get<char>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
				else if (record_1.type_2 == "bool") {
					bool value = std::get<bool>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
			}
			else if (record_1.type_1 == "double") {
				double key = std::get<double>(v1);
				if (record_1.type_2 == "int") {
					int value = std::get<int>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
				else if (record_1.type_2 == "float") {
					float value = std::get<float>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
				else if (record_1.type_2 == "double") {
					double value = std::get<double>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
				else if (record_1.type_2 == "char") {
					char value = std::get<char>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
				else if (record_1.type_2 == "bool") {
					bool value = std::get<bool>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
			}
			else if (record_1.type_1 == "char") {
				char key = std::get<char>(v1);
				if (record_1.type_2 == "int") {
					int value = std::get<int>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
				else if (record_1.type_2 == "float") {
					float value = std::get<float>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
				else if (record_1.type_2 == "double") {
					double value = std::get<double>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
				else if (record_1.type_2 == "char") {
					char value = std::get<char>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
				else if (record_1.type_2 == "bool") {
					bool value = std::get<bool>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
			}
			else if (record_1.type_1 == "bool") {
				bool key = std::get<bool>(v1);
				if (record_1.type_2 == "int") {
					int value = std::get<int>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
				else if (record_1.type_2 == "float") {
					float value = std::get<float>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
				else if (record_1.type_2 == "double") {
					double value = std::get<double>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
				else if (record_1.type_2 == "char") {
					char value = std::get<char>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
				else if (record_1.type_2 == "bool") {
					bool value = std::get<bool>(v2);
					op += "	multimap_" + std::to_string(current) + ".insert({" + std::to_string(key) + "," + std::to_string(value) + "}); \n"; //insert at certain place
					temp_mm.insert(std::make_pair(key, value));
				}
			}
			local_records[current].length += 1* loop_index;
			break;
		case 2:
			op += "	multimap_" + std::to_string(current) + ".count(" + generate_multi_key_element(record_1.type_1) + "); \n";
		case 3:
			if (current_length != 0) {
				op += "	multimap_" + std::to_string(current) + ".equal_range(" + generate_multi_key_element(record_1.type_1) + "); \n";
			}
		case 4:
			if (current_length != 0) {
				auto multi_it = next(temp_mm.begin(), random_index_erase);
				temp_mm.erase(multi_it->first);
				op += "	auto multi_it_" + std::to_string(n) + std::to_string(m) + std::to_string(loop_mode) + " = next(multimap_" + std::to_string(current) + ".begin()," + std::to_string(random_index_erase) + "); \n";
				op += "	multimap_" + std::to_string(current) + ".erase(multi_it_" + std::to_string(n) + std::to_string(m) + std::to_string(loop_mode) + "->first); \n";
				local_records[current].length -= 1 * loop_index;
			}
			break;
		case 5:
			if (current_length != 0) {
				op += "	multimap_" + std::to_string(current) + ".begin();\n"; //Returns an iterator pointing to the first element of the vector
			}
			break;
		case 6:
			if (current_length != 0) {
				op += "	multimap_" + std::to_string(current) + ".end();\n"; // Returns an iterator pointing to the past-the-end element of the vector
			}
			break;
		case 7:
			op += "	multimap_" + std::to_string(current) + ".rbegin();\n"; //Returns a reverse iterator pointing to the last element of the vector
			break;
		case 8:
			op += "	multimap_" + std::to_string(current) + ".rend();\n"; // Returns a reverse iterator pointing to the element preceding the first element of the vector
			break;
		case 9:
			op += "	multimap_" + std::to_string(current) + ".find(" + generate_multi_key_element(record_1.type_1) + "); \n";
			break;
		case 10:
			op += "	multimap_" + std::to_string(current) + ".cbegin();\n"; //Returns const_iterator to beginning
			break;
		case 11:
			op += "	multimap_" + std::to_string(current) + ".cend();\n"; // Returns const_iterator to end
			break;
		case 12:
			op += "	multimap_" + std::to_string(current) + ".crbegin();\n"; //Returns const_reverse_iterator to reverse beginning
			break;
		case 13:
			op += "	multimap_" + std::to_string(current) + ".crend();\n"; // Returns const_reverse_iterator to reverse end
			break;

		case 14:
			if (record_1.type_1 == "int") {
				int key = std::get<int>(v1);
				if (record_1.type_2 == "int") {
					int value = std::get<int>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
				else if (record_1.type_2 == "float") {
					float value = std::get<float>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
				else if (record_1.type_2 == "double") {
					double value = std::get<double>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
				else if (record_1.type_2 == "char") {
					char value = std::get<char>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
				else if (record_1.type_2 == "bool") {
					bool value = std::get<bool>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
			}
			else if (record_1.type_1 == "float") {
				float key = std::get<float>(v1);
				if (record_1.type_2 == "int") {
					int value = std::get<int>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
				else if (record_1.type_2 == "float") {
					float value = std::get<float>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
				else if (record_1.type_2 == "double") {
					double value = std::get<double>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
				else if (record_1.type_2 == "char") {
					char value = std::get<char>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
				else if (record_1.type_2 == "bool") {
					bool value = std::get<bool>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
			}
			else if (record_1.type_1 == "double") {
				double key = std::get<double>(v1);
				if (record_1.type_2 == "int") {
					int value = std::get<int>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
				else if (record_1.type_2 == "float") {
					float value = std::get<float>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
				else if (record_1.type_2 == "double") {
					double value = std::get<double>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
				else if (record_1.type_2 == "char") {
					char value = std::get<char>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
				else if (record_1.type_2 == "bool") {
					bool value = std::get<bool>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
			}
			else if (record_1.type_1 == "char") {
				char key = std::get<char>(v1);
				if (record_1.type_2 == "int") {
					int value = std::get<int>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
				else if (record_1.type_2 == "float") {
					float value = std::get<float>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
				else if (record_1.type_2 == "double") {
					double value = std::get<double>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
				else if (record_1.type_2 == "char") {
					char value = std::get<char>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
				else if (record_1.type_2 == "bool") {
					bool value = std::get<bool>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
			}
			else if (record_1.type_1 == "bool") {
				bool key = std::get<bool>(v1);
				if (record_1.type_2 == "int") {
					int value = std::get<int>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
				else if (record_1.type_2 == "float") {
					float value = std::get<float>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
				else if (record_1.type_2 == "double") {
					double value = std::get<double>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
				else if (record_1.type_2 == "char") {
					char value = std::get<char>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
				else if (record_1.type_2 == "bool") {
					bool value = std::get<bool>(v2);
					op += "	multimap_" + std::to_string(current) + ".emplace(" + std::to_string(key) + "," + std::to_string(value) + "); \n"; //insert at certain place
					temp_mm.emplace(key, value);
				}
			}
			local_records[current].length += 1 * loop_index;
			break;

		case 15:
			op += "	multimap_" + std::to_string(current) + ".max_size();\n"; //Returns the maximum number of elements that the vector can hold.
			break;

		case 16:
			op += "	auto multi_ithigh_" + std::to_string(n) + std::to_string(m) + std::to_string(loop_mode) + " = multimap_" + std::to_string(current) + ".upper_bound(" + generate_multi_key_element(record_1.type_1) + ");\n";
			//An iterator to the the first element in the container which is considered to go after val, or set::end if no elements are considered to go after val.
			break;
		case 17:
			op += "	auto multi_itlow_" + std::to_string(n) + std::to_string(m) + std::to_string(loop_mode) + " = multimap_" + std::to_string(current) + ".lower_bound(" + generate_multi_key_element(record_1.type_1) + ");\n";
			//An iterator to the the first element in the container which is considered to go after val, or set::end if no elements are considered to go after val.
			break;
		case 18:

			//if (record_1.type_1 == "int" or record_1.type_1 == "double" or record_1.type_1 == "char" or record_1.type_1 == "float" or record_1.type_1 == "bool") {

			//	op += "	multimap_" + std::to_string(current) + ".emplace_hint(multimap_" + std::to_string(current) + ".begin() " + "," + generate_multi_key_element(record_1.type_1) + "," + generate_multi_value_element(record_1.type_2) + "); \n"; // Constructs and inserts an element in the vector.

			//}
			//if (record_1.type_1 == "int" or record_1.type_1 == "double" or record_1.type_1 == "char" or record_1.type_1 == "float" /*or record_1.type_1 == "bool"*/)
			//	local_records[current].length += 1;
			break;

		case 19:
			op += "	auto mymulti_comp_" + std::to_string(n) + std::to_string(m) + std::to_string(loop_mode) + " = multimap_" + std::to_string(current) + ".value_comp();\n"; //The comparison object.
			break;
		case 20:
			op += "	auto mymulti_comp_" + std::to_string(n) + std::to_string(m) + std::to_string(loop_mode) + " = multimap_" + std::to_string(current) + ".key_comp();\n"; //The comparison object.
			break;
		case 21:
			op += "	multimap_" + std::to_string(current) + ".size();\n"; //Returns the number of elements in the vector.
			break;
		case 22:
			op += "	multimap_" + std::to_string(current) + ".empty();\n"; //Checks if the vector is empty.
			break;
		case 23:
			op += "	multimap_" + std::to_string(current) + ".clear();\n";
			local_records[current].length = 0;
			temp_mm.clear();
			break;




		}
		local_records[current].length = temp_mm.size();
	}



	records = local_records;
	return { op,records, temp_mm};
}

template<typename K, typename V>
std::string random_multimap_loop(int number_of_index, std::vector<multimap_records> records, std::multimap<K, V> mn, int operation_loop_numbers = random_Int(1, 1)) {
	std::string op;
	int current = 0;
	for (int m = 1; m <= operation_loop_numbers; m++) {
		//current = random_Int(0, number_of_index - 1);
		auto record_1 = records.at(number_of_index);
		int for_loop_size = random_Int(0, 5);
		switch (random_Int(1, 8)) {
		case 1:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	auto index_multimap_" +std::to_string(number_of_index) + std::to_string(m) + " = multimap_" + std::to_string(number_of_index) + ".begin();\n";
				op += "	std::advance(index_multimap_" + std::to_string(number_of_index) + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( index_multimap_" + std::to_string(number_of_index) + std::to_string(m) + "->second > " + generate_multi_value_element(record_1.type_2) + ") {\n";
				auto [temp_string_1, temp_records_1, temp_map_1] = random_multimap_op(number_of_index, records, mn, random_Int(0, 5),1,1);
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2, temp_map_2] = random_multimap_op(number_of_index, records, mn, random_Int(0, 5), 1, 1);
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 2:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	auto index_multimap_" + std::to_string(number_of_index) + std::to_string(m) + " = multimap_" + std::to_string(number_of_index) + ".begin();\n";
				op += "	std::advance(index_multimap_" + std::to_string(number_of_index) + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( index_multimap_" + std::to_string(number_of_index) + std::to_string(m) + "->second < " + generate_multi_value_element(record_1.type_2) + ") {\n";
				auto [temp_string_1, temp_records_1, temp_map_1] = random_multimap_op(number_of_index, records, mn, random_Int(0, 5), 1, 1);
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2, temp_map_2] = random_multimap_op(number_of_index, records, mn, random_Int(0, 5), 1, 1);
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 3:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	auto index_multimap_" + std::to_string(number_of_index) + std::to_string(m) + " = multimap_" + std::to_string(number_of_index) + ".begin();\n";
				op += "	std::advance(index_multimap_" + std::to_string(number_of_index) + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( index_multimap_" + std::to_string(number_of_index) + std::to_string(m) + "->second <= " + generate_multi_value_element(record_1.type_2) + ") {\n";
				auto [temp_string_1, temp_records_1, temp_map_1] = random_multimap_op(number_of_index, records, mn, random_Int(0, 5), 1, 1);
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2, temp_map_2] = random_multimap_op(number_of_index, records, mn, random_Int(0, 5), 1, 1);
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 4:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	auto index_multimap_" + std::to_string(number_of_index) + std::to_string(m) + " = multimap_" + std::to_string(number_of_index) + ".begin();\n";
				op += "	std::advance(index_multimap_" + std::to_string(number_of_index) + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( index_multimap_" + std::to_string(number_of_index) + std::to_string(m) + "->second >= " + generate_multi_value_element(record_1.type_2) + ") {\n";
				auto [temp_string_1, temp_records_1, temp_map_1] = random_multimap_op(number_of_index, records, mn, random_Int(0, 5), 1, 1);
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2, temp_map_2] = random_multimap_op(number_of_index, records, mn, random_Int(0, 5), 1, 1);
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 5:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	auto index_multimap_" + std::to_string(number_of_index) + std::to_string(m) + " = multimap_" + std::to_string(number_of_index) + ".begin();\n";
				op += "	std::advance(index_multimap_" + std::to_string(number_of_index) + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( index_multimap_" + std::to_string(number_of_index) + std::to_string(m) + "->second == " + generate_multi_value_element(record_1.type_2) + ") {\n";
				auto [temp_string_1, temp_records_1, temp_map_1] = random_multimap_op(number_of_index, records, mn, random_Int(0, 5), 1, 1);
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2, temp_map_2] = random_multimap_op(number_of_index, records, mn, random_Int(0, 5), 1, 1);
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 6:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	auto index_multimap_" + std::to_string(number_of_index) + std::to_string(m) + " = multimap_" + std::to_string(number_of_index) + ".begin();\n";
				op += "	std::advance(index_multimap_" + std::to_string(number_of_index) + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( index_multimap_" + std::to_string(number_of_index) + std::to_string(m) + "->second != " + generate_multi_value_element(record_1.type_2) + ") {\n";
				auto [temp_string_1, temp_records_1, temp_map_1] = random_multimap_op(number_of_index, records, mn, random_Int(0, 5), 1, 1);
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2, temp_map_2] = random_multimap_op(number_of_index, records, mn, random_Int(0, 5), 1, 1);
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		//case 7:
		//	if (record_1.length > for_loop_size) {
		//		op += "	for (int index = 0; index < " + std::to_string(for_loop_size) + "; index ++) {\n";
		//		auto [temp_string, temp_records, temp_map] = random_multimap_op(number_of_index, records,mn, 1, for_loop_size);
		//		records = temp_records;
		//		op += temp_string;
		//		op += "	}\n";
		//	}
		//	break;

		//case 8:
		//	if (record_1.length > for_loop_size) {
		//		op += "	int index_multimap_" + std::to_string(number_of_index) + std::to_string(m) + "= 0;\n";
		//		op += "	while (index_multimap_" + std::to_string(number_of_index) + std::to_string(m) + " < " + std::to_string(for_loop_size) + ") {\n";
		//		auto [temp_string, temp_records, temp_map] = random_multimap_op(number_of_index, records,mn, 1, for_loop_size);
		//		records = temp_records;
		//		op += temp_string;
		//		op += "	index_multimap_" + std::to_string(number_of_index) + std::to_string(m) + "++;\n";
		//		op += "	}\n";
		//	}
		//	break;
		}
		//std::cout << op << std::endl;
	}
	return op;
}




std::string create_multimap(int index) {
	std::string code;
	std::string oss;
	std::string type_1;
	std::string type_2;
	int map_elements_num = random_Int(5, 10);
	/*int vec_rows = random_Int(1, 2);*/
	int map_rows = 2;// 1 for 1D vector
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

	std::set<int> temp_set_int = {};
	std::set<float> temp_set_float = {};
	std::set<double> temp_set_double = {};
	std::set<char> temp_set_char = {};
	std::set<bool> temp_set_bool = {};

	std::vector<multimap_records> map_records;


	std::multimap<int, int> multimap_int_int = {};
	std::multimap<int, float> multimap_int_float = {};
	std::multimap<int, double> multimap_int_double = {};
	std::multimap<int, char> multimap_int_char = {};
	std::multimap<int, bool> multimap_int_bool = {};
	std::multimap<float, int> multimap_float_int = {};
	std::multimap<float, float> multimap_float_float = {};
	std::multimap<float, double> multimap_float_double = {};
	std::multimap<float, char> multimap_float_char = {};
	std::multimap<float, bool> multimap_float_bool = {};
	std::multimap<double, int> multimap_double_int = {};
	std::multimap<double, float> multimap_double_float = {};
	std::multimap<double, double> multimap_double_double = {};
	std::multimap<double, char> multimap_double_char = {};
	std::multimap<double, bool> multimap_double_bool = {};
	std::multimap<char, int> multimap_char_int = {};
	std::multimap<char, float> multimap_char_float = {};
	std::multimap<char, double> multimap_char_double = {};
	std::multimap<char, char> multimap_char_char = {};
	std::multimap<char, bool> multimap_char_bool = {};
	std::multimap<bool, int> multimap_bool_int = {};
	std::multimap<bool, float> multimap_bool_float = {};
	std::multimap<bool, double> multimap_bool_double = {};
	std::multimap<bool, char> multimap_bool_char = {};
	std::multimap<bool, bool> multimap_bool_bool = {};



	std::vector<std::any> all_multimap = {};





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
			temp_int_1 = create_multimap_int(map_elements_num);
			temp_length = temp_int_1.size();
		}
		else if (type_1 == "float") {
			temp_float_1 = create_multimap_float(map_elements_num);
			temp_length = temp_float_1.size();
		}
		else if (type_1 == "double")
		{
			temp_double_1 = create_multimap_double(map_elements_num);
			temp_length = temp_double_1.size();
		}
		else if (type_1 == "char") {
			temp_char_1 = create_multimap_char(map_elements_num);
			temp_length = temp_char_1.size();
		}
		else if (type_1 == "bool") {
			temp_bool_1 = create_multimap_bool(map_elements_num);
			temp_length = temp_bool_1.size();
		}

		if (type_2 == "int") {
			temp_int_2 = create_multimap_int(map_elements_num);
		}
		else if (type_2 == "float") {
			temp_float_2 = create_multimap_float(map_elements_num);
		}
		else if (type_2 == "double")
		{
			temp_double_2 = create_multimap_double(map_elements_num);
		}
		else if (type_2 == "char") {
			temp_char_2 = create_multimap_char(map_elements_num);
		}
		else if (type_2 == "bool") {
			temp_bool_2 = create_multimap_bool(map_elements_num);
		}



		map_records.push_back({ temp_length, type_1,type_2 });



		//for (int i = 1; i <= temp_length; i++) {
		//	oss += "{";
		//	if (type_1 == "int")
		//		oss += std::to_string(temp_int_1[i - 1]);
		//	else if (type_1 == "float")
		//		oss += std::to_string(temp_float_1[i - 1]);
		//	else if (type_1 == "double")
		//		oss += std::to_string(temp_double_1[i - 1]);
		//	else if (type_1 == "char")
		//		oss += std::to_string(temp_char_1[i - 1]);
		//	else if (type_1 == "bool")
		//		oss += std::to_string(temp_bool_1[i - 1]);
		//	oss += ",";
		//	if (type_2 == "int")
		//		oss += std::to_string(temp_int_2[i - 1]);
		//	else if (type_2 == "float")
		//		oss += std::to_string(temp_float_2[i - 1]);
		//	else if (type_2 == "double")
		//		oss += std::to_string(temp_double_2[i - 1]);
		//	else if (type_2 == "char")
		//		oss += std::to_string(temp_char_2[i - 1]);
		//	else if (type_2 == "bool")
		//		oss += std::to_string(temp_bool_2[i - 1]);
		//	oss += "}";
		//	if (i != temp_length) {
		//		oss += ", "; // Add a separator between numbers
		//	}
		//}

		for (int i = 1; i <= temp_length; i++) {
			if (type_1 == "int") {
				if (type_2 == "int")
					multimap_int_int.insert({ temp_int_1[i - 1],temp_int_2[i - 1] });
				else if (type_2 == "float")
					multimap_int_float.insert({ temp_int_1[i - 1],temp_float_2[i - 1] });
				else if (type_2 == "double")
					multimap_int_double.insert({ temp_int_1[i - 1],temp_double_2[i - 1] });
				else if (type_2 == "char")
					multimap_int_char.insert({ temp_int_1[i - 1],temp_char_2[i - 1] });
				else if (type_2 == "bool")
					multimap_int_bool.insert({ temp_int_1[i - 1],temp_bool_2[i - 1] });
			}
			else if (type_1 == "float") {
				if (type_2 == "int")
					multimap_float_int.insert({ temp_float_1[i - 1],temp_int_2[i - 1] });
				else if (type_2 == "float")
					multimap_float_float.insert({ temp_float_1[i - 1],temp_float_2[i - 1] });
				else if (type_2 == "double")
					multimap_float_double.insert({ temp_float_1[i - 1],temp_double_2[i - 1] });
				else if (type_2 == "char")
					multimap_float_char.insert({ temp_float_1[i - 1],temp_char_2[i - 1] });
				else if (type_2 == "bool")
					multimap_float_bool.insert({ temp_float_1[i - 1],temp_bool_2[i - 1] });
			}
			else if (type_1 == "double") {
				if (type_2 == "int")
					multimap_double_int.insert({ temp_double_1[i - 1],temp_int_2[i - 1] });
				else if (type_2 == "float")
					multimap_double_float.insert({ temp_double_1[i - 1],temp_float_2[i - 1] });
				else if (type_2 == "double")
					multimap_double_double.insert({ temp_double_1[i - 1],temp_double_2[i - 1] });
				else if (type_2 == "char")
					multimap_double_char.insert({ temp_double_1[i - 1],temp_char_2[i - 1] });
				else if (type_2 == "bool")
					multimap_double_bool.insert({ temp_double_1[i - 1],temp_bool_2[i - 1] });
			}
			else if (type_1 == "char") {
				if (type_2 == "int")
					multimap_char_int.insert({ temp_char_1[i - 1],temp_int_2[i - 1] });
				else if (type_2 == "float")
					multimap_char_float.insert({ temp_char_1[i - 1],temp_float_2[i - 1] });
				else if (type_2 == "double")
					multimap_char_double.insert({ temp_char_1[i - 1],temp_double_2[i - 1] });
				else if (type_2 == "char")
					multimap_char_char.insert({ temp_char_1[i - 1],temp_char_2[i - 1] });
				else if (type_2 == "bool")
					multimap_char_bool.insert({ temp_char_1[i - 1],temp_bool_2[i - 1] });
			}

			else if (type_1 == "bool")
			{
				if (type_2 == "int")
					multimap_bool_int.insert({ temp_bool_1[i - 1],temp_int_2[i - 1] });
				else if (type_2 == "float")
					multimap_bool_float.insert({ temp_bool_1[i - 1],temp_float_2[i - 1] });
				else if (type_2 == "double")
					multimap_bool_double.insert({ temp_bool_1[i - 1],temp_double_2[i - 1] });
				else if (type_2 == "char")
					multimap_bool_char.insert({ temp_bool_1[i - 1],temp_char_2[i - 1] });
				else if (type_2 == "bool")
					multimap_bool_bool.insert({ temp_bool_1[i - 1],temp_bool_2[i - 1] });
			}

		}

		//insert to all_multimap container
		if (type_1 == "int") {
			if (type_2 == "int") {
				//all_multimap.push_back(multimap_int_int);
				oss += multimap_to_string(multimap_int_int);
			}
			else if (type_2 == "float") {
				//all_multimap.push_back(multimap_int_float);
				oss += multimap_to_string(multimap_int_float);
			}
			else if (type_2 == "double") {
				//all_multimap.push_back(multimap_int_double);
				oss += multimap_to_string(multimap_int_double);
			}
			else if (type_2 == "char") {
				//all_multimap.push_back(multimap_int_char);
				oss += multimap_to_string(multimap_int_char);
			}
			else if (type_2 == "bool") {
				//all_multimap.push_back(multimap_int_bool);
				oss += multimap_to_string(multimap_int_bool);
			}
		}
		else if (type_1 == "float") {
			if (type_2 == "int") {
				//all_multimap.push_back(multimap_float_int);
				oss += multimap_to_string(multimap_float_int);
			}
			else if (type_2 == "float") {
				//all_multimap.push_back(multimap_float_float);
				oss += multimap_to_string(multimap_float_float);
			}
			else if (type_2 == "double") {
				//all_multimap.push_back(multimap_float_double);
				oss += multimap_to_string(multimap_float_double);
			}
			else if (type_2 == "char") {
				//all_multimap.push_back(multimap_float_char);
				oss += multimap_to_string(multimap_float_char);
			}
			else if (type_2 == "bool") {
				//all_multimap.push_back(multimap_float_bool);
				oss += multimap_to_string(multimap_float_bool);
			}
		}
		else if (type_1 == "double") {
			if (type_2 == "int") {
				//all_multimap.push_back(multimap_double_int);
				oss += multimap_to_string(multimap_double_int);
			}
			else if (type_2 == "float") {
				//all_multimap.push_back(multimap_double_float);
				oss += multimap_to_string(multimap_double_float);
			}
			else if (type_2 == "double") {
				//all_multimap.push_back(multimap_double_double);
				oss += multimap_to_string(multimap_double_double);
			}
			else if (type_2 == "char") {
				//all_multimap.push_back(multimap_double_char);
				oss += multimap_to_string(multimap_double_char);
			}
			else if (type_2 == "bool") {
				//all_multimap.push_back(multimap_double_bool);
				oss += multimap_to_string(multimap_double_bool);
			}
		}
		else if (type_1 == "char") {
			if (type_2 == "int") {
				//all_multimap.push_back(multimap_char_int);
				oss += multimap_to_string(multimap_char_int);
			}
			else if (type_2 == "float") {
				//all_multimap.push_back(multimap_char_float);
				oss += multimap_to_string(multimap_char_float);
			}
			else if (type_2 == "double") {
				//all_multimap.push_back(multimap_char_double);
				oss += multimap_to_string(multimap_char_double);
			}
			else if (type_2 == "char") {
				//all_multimap.push_back(multimap_char_char);
				oss += multimap_to_string(multimap_char_char);
			}
			else if (type_2 == "bool") {
				//all_multimap.push_back(multimap_char_bool);
				oss += multimap_to_string(multimap_char_bool);
			}
		}

		else if (type_1 == "bool")
		{
			if (type_2 == "int") {
				//all_multimap.push_back(multimap_bool_int);
				oss += multimap_to_string(multimap_bool_int);
			}
			else if (type_2 == "float") {
				//all_multimap.push_back(multimap_bool_float);
				oss += multimap_to_string(multimap_bool_float);
			}
			else if (type_2 == "double") {
				//all_multimap.push_back(multimap_bool_double);
				oss += multimap_to_string(multimap_bool_double);
			}
			else if (type_2 == "char") {
				//all_multimap.push_back(multimap_bool_char);
				oss += multimap_to_string(multimap_bool_char);
			}
			else if (type_2 == "bool") {
				//all_multimap.push_back(multimap_bool_bool);
				oss += multimap_to_string(multimap_bool_bool);
			}
		}

		code += "	std::multimap<" + type_1 + "," + type_2 + "> multimap_" + std::to_string(n) + " = " + oss + ";\n";
		oss = {};


		if (type_1 == "int") {
			if (type_2 == "int") {
				//code += random_multimap_op(n, map_records, multimap_int_int);
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_int_int);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
			else if (type_2 == "float") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_int_float);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
			else if (type_2 == "double") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_int_double);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
			else if (type_2 == "char") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_int_char);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
			else if (type_2 == "bool") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_int_bool);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
		}
		else if (type_1 == "float") {
			if (type_2 == "int") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_float_int);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
			else if (type_2 == "float") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_float_float);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
			else if (type_2 == "double") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_float_double);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
			else if (type_2 == "char") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_float_char);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
			else if (type_2 == "bool") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_float_bool);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
		}
		else if (type_1 == "double") {
			if (type_2 == "int") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_double_int);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
			else if (type_2 == "float") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_double_float);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
			else if (type_2 == "double") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_double_double);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
			else if (type_2 == "char") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_double_char);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
			else if (type_2 == "bool") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_double_bool);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
		}
		else if (type_1 == "char") {
			if (type_2 == "int") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_char_int);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
			else if (type_2 == "float") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_char_float);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
			else if (type_2 == "double") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_char_double);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
			else if (type_2 == "char") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_char_char);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
			else if (type_2 == "bool") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_char_bool);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
		}

		else if (type_1 == "bool")
		{
			if (type_2 == "int") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_bool_int);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
			else if (type_2 == "float") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_bool_float);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
			else if (type_2 == "double") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_bool_double);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
			else if (type_2 == "char") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_bool_char);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
			else if (type_2 == "bool") {
				auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, multimap_bool_bool);
				code += temp_string;
				map_records = temp_records;
				code += random_multimap_loop(n, map_records, temp_map);
			}
		}

		//clear all temporal containers
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
		temp_length = 0;

		multimap_int_int = {};
		multimap_int_float = {};
		multimap_int_double = {};
		multimap_int_char = {};
		multimap_int_bool = {};
		multimap_float_int = {};
		multimap_float_float = {};
		multimap_float_double = {};
		multimap_float_char = {};
		multimap_float_bool = {};
		multimap_double_int = {};
		multimap_double_float = {};
		multimap_double_double = {};
		multimap_double_char = {};
		multimap_double_bool = {};
		multimap_char_int = {};
		multimap_char_float = {};
		multimap_char_double = {};
		multimap_char_char = {};
		multimap_char_bool = {};
		multimap_bool_int = {};
		multimap_bool_float = {};
		multimap_bool_double = {};
		multimap_bool_char = {};
		multimap_bool_bool = {};


	}

	//random operations generated
	code += all_op(index, map_records);

	for (int m = 0; m < index; m++) {
		code += "	std::pair<std::vector<" + map_records[m].type_1 + ">,std::vector<" + map_records[m].type_2 + ">> newmultimap_" + std::to_string(m) + " = map_to_vectors(multimap_" + std::to_string(m) + ");\n";
		code += "	append_data(buffer, newmultimap_" + std::to_string(m) + ".first);\n";
		code += "	append_data(buffer, newmultimap_" + std::to_string(m) + ".second);\n";
	}




	code += "\n";
	return code;
}
