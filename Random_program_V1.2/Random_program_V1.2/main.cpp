#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cstdio>
//#include <format>
#include <initializer_list>
#include <string>
#include "Random_program.h"



std::string random_transition(int vec_numbers, int set_numbers) {
	std::string code;
	int n = random_Int(1, 2);


	for (int i = 1; i <= n; i++)
	{
		int index_set = random_Int(1, set_numbers);
		int index_vec = random_Int(1, vec_numbers);
		switch (random_Int(1, 2)) {
		case 1:

			code += "std::set <int> set_" + std::to_string(set_numbers + i) + "(vec_" + std::to_string(index_vec) + ".begin(), vec_" + std::to_string(index_vec) + ".end()); \n";
		case 2:
			code += "std::vector<int> vec_" + std::to_string(vec_numbers + i) + "(set_" + std::to_string(index_set) + ".begin(), set_" + std::to_string(index_set) + ".end()); \n";
		}
	}



	return code;
}



// Function to generate a random STL container operation
std::string generateRandomSTLCode() {
	std::string code;
	int choice = random_Int(1, 5);
	int times = random_Int(1, 10);
	int random_value = random_Int(1, 100);
	int number_of_vecs = random_Int(1, 3);
	int number_of_sets = random_Int(1, 3);
	int number_of_lists = random_Int(1, 3);
	int number_of_deques = random_Int(1, 3);
	int number_of_arrays = random_Int(1, 3);
	int number_of_queues = random_Int(1, 3);
	int number_of_unordered_sets = random_Int(1, 3);
	int number_of_maps = random_Int(1, 3);
	int number_of_unordered_maps = random_Int(3, 3);
	int number_of_multimaps = random_Int(1, 3);
	int number_of_stack = random_Int(1, 3);
	int number_of_bitset = random_Int(1, 3);
	int i = 0;
	int n = 0;
	code += create_vec(number_of_vecs);
	code += create_array(number_of_arrays);
	code += create_deque(number_of_deques);
	code += create_queue(number_of_queues);
	code += create_set(number_of_sets);
	code += create_list(number_of_lists);
	//code += create_unordered_set(number_of_unordered_sets);
	code += create_map(number_of_maps);
	//code += create_unoredered_map(number_of_unordered_maps);
	code += create_multimap(number_of_multimaps);
	code += create_stack(number_of_stack);
	code += create_bitset(number_of_bitset);

	code += "	uint32_t hash_result = simple_hash(buffer.data(), buffer.size());\n";
	code += "	unsigned int out = hash_result;\n";

	return code;
}

enum mode {
	Jasper,
	VC_Formal,
};

int main() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	mode active_mode = VC_Formal;
	// Generate random C++ code
	std::string randomCode = generateRandomSTLCode();

	if (active_mode == VC_Formal) {
		// Write the random code to a file
		std::ofstream outFile("random_stl_program.cpp");
		if (outFile.is_open()) {
			outFile << "#include <iostream>\n";
			outFile << "#include <vector>\n";
			outFile << "#include <set>\n";
			outFile << "#include <map>\n";
			outFile << "#include <queue>\n";
			outFile << "#include <algorithm>\n";
			outFile << "#include <initializer_list>\n";
			outFile << "#include <list>\n";
			outFile << "#include <array>\n";
			outFile << "#include <string>\n";
			outFile << "#include <unordered_set>\n";
			outFile << "#include <stack>\n";
			outFile << "#include <bitset>\n";
			outFile << "#include <unordered_map>\n";
			outFile << "#include <fstream>\n\n";
			outFile << "#ifdef JASPER_C\n";
			outFile << "#include <jasperc.h>\n";
			outFile << "#endif\n\n";
			outFile << "uint32_t simple_hash(const void* data, size_t len) {\n";
			outFile << "    const uint8_t* bytes = static_cast<const uint8_t*>(data);\n";
			outFile << "    uint32_t hash = 2166136261u; // FNV offset basis\n";
			outFile << "    for (size_t i = 0; i < len; ++i) {\n";
			outFile << "        hash ^= bytes[i];\n";
			outFile << "        hash *= 16777619u; // FNV prime\n";
			outFile << "    }\n";
			outFile << "    return hash;\n";
			outFile << "}\n\n";
			outFile << "template <typename T>\n";
			outFile << "void append_data(std::vector<uint8_t>& buffer, const std::vector<T>& vec) {\n";
			outFile << "    const uint8_t* raw = reinterpret_cast<const uint8_t*>(vec.data());\n";
			outFile << "    buffer.insert(buffer.end(), raw, raw + vec.size() * sizeof(T));\n";
			outFile << "}\n\n";


			outFile << "void append_data(std::vector<uint8_t>& buffer, const std::vector<bool>& vec) {\n";
			outFile << "	for (bool b : vec) {\n";
			outFile << "		buffer.push_back(b ? 1 : 0);\n";
			outFile << "	}\n";
			outFile << "}\n\n";
			outFile << "template<typename K, typename V>\n";
			outFile << "std::pair<std::vector<K>, std::vector<V>> map_to_vectors(const std::map<K, V>& m) {\n";
			outFile << "	std::vector<K> keys;\n";
			outFile << "	std::vector<V> values;\n";
			outFile << "	keys.reserve(m.size());\n";
			outFile << "	values.reserve(m.size());\n";
			outFile << "	for (const auto& p : m) {\n";
			outFile << "		keys.push_back(p.first);\n";
			outFile << "		values.push_back(p.second);\n";
			outFile << "	}\n";
			outFile << "	return { keys, values };\n";
			outFile << "}\n";
			outFile << "template<typename K, typename V>\n";
			outFile << "std::pair<std::vector<K>, std::vector<V>> map_to_vectors(const std::unordered_map<K, V>& m) {\n";
			outFile << "	std::vector<K> keys;\n";
			outFile << "	std::vector<V> values;\n";
			outFile << "	keys.reserve(m.size());\n";
			outFile << "	values.reserve(m.size());\n";
			outFile << "	for (const auto& p : m) {\n";
			outFile << "		keys.push_back(p.first);\n";
			outFile << "		values.push_back(p.second);\n";
			outFile << "	}\n";
			outFile << "	return { keys, values };\n";
			outFile << "}\n";
			outFile << "template<typename K, typename V>\n";
			outFile << "std::pair<std::vector<K>, std::vector<V>> map_to_vectors(const std::multimap<K, V>& m) {\n";
			outFile << "	std::vector<K> keys;\n";
			outFile << "	std::vector<V> values;\n";
			outFile << "	keys.reserve(m.size());\n";
			outFile << "	values.reserve(m.size());\n";
			outFile << "	for (const auto& p : m) {\n";
			outFile << "		keys.push_back(p.first);\n";
			outFile << "		values.push_back(p.second);\n";
			outFile << "	}\n";
			outFile << "	return { keys, values };\n";
			outFile << "}\n";

			outFile << "int main() {\n";

			outFile << randomCode;
			outFile << "    uint32_t result = hash_result;\n";
			outFile << "	std::ofstream outFile(\"rtl_program.sv\");\n";
			outFile << "	if (outFile.is_open()) {\n";
			outFile << "	outFile << \"module add(\\n\";\n";
			outFile << "	outFile << \"  input logic      clock,\\n\";\n";
			outFile << "	outFile << \"  input logic      resetN,\\n\";\n";
			outFile << "	outFile << \"  output logic [31:0] result\\n\";\n";
			outFile << "	outFile << \"  );\\n\";\n";
			outFile << "	outFile << \"  assign result = 32'd\" + std::to_string(result) +\";\\n\";\n";
			outFile << "	outFile << \"endmodule\\n\";\n";
			outFile << "	}\n";
			outFile << "	else {\n";
			outFile << "		std::cerr << \"Error: Unable to create the file.\" << std::endl;\n";
			outFile << "	}\n";
			outFile << "#ifdef JASPER_C\n";
			outFile << "	JASPER_OUTPUT(out);\n";
			outFile << "#endif\n";
			outFile << "    return 0;\n";
			outFile << "}\n";
			outFile.close();
			std::cout << "Random STL program has been written to 'random_stl_program.cpp'." << std::endl;
		}
		else {
			std::cerr << "Error: Unable to create the file." << std::endl;
		}


		std::ofstream outFile2("random_stl_program.cc");
		if (outFile2.is_open()) {
			outFile2 << "#include <iostream>\n";
			outFile2 << "#include <vector>\n";
			outFile2 << "#include <set>\n";
			outFile2 << "#include <map>\n";
			outFile2 << "#include <queue>\n";
			outFile2 << "#include <algorithm>\n";
			outFile2 << "#include <initializer_list>\n";
			outFile2 << "#include <list>\n";
			outFile2 << "#include <array>\n";
			outFile2 << "#include <string>\n";
			outFile2 << "#include <fstream>\n";
			outFile2 << "#include <unordered_set>\n";
			outFile2 << "#include <stack>\n";
			outFile2 << "#include <bitset>\n";
			outFile2 << "#include <unordered_map>\n";
			outFile2 << "#include \"Hector.h\"\n";
			outFile2 << "#include <stdint.h>\n\n";
			outFile2 << "uint32_t simple_hash(const void* data, size_t len) {\n";
			outFile2 << "    const uint8_t* bytes = static_cast<const uint8_t*>(data);\n";
			outFile2 << "    uint32_t hash = 2166136261u; // FNV offset basis\n";
			outFile2 << "    for (size_t i = 0; i < len; ++i) {\n";
			outFile2 << "        hash ^= bytes[i];\n";
			outFile2 << "        hash *= 16777619u; // FNV prime\n";
			outFile2 << "    }\n";
			outFile2 << "    return hash;\n";
			outFile2 << "}\n\n";

			outFile2 << "template <typename T>\n";
			outFile2 << "void append_data(std::vector<uint8_t>& buffer, const std::vector<T>& vec) {\n";
			outFile2 << "    if (vec.empty()) return;\n";
			outFile2 << "    size_t old_size = buffer.size();\n";
			outFile2 << "    size_t append_size = vec.size() * sizeof(T);\n";
			outFile2 << "    buffer.resize(old_size + append_size);\n";
			outFile2 << "    std::memcpy(buffer.data() + old_size, vec.data(), append_size);\n";
			outFile2 << "}\n\n";

			outFile2 << "template<typename K, typename V>\n";
			outFile2 << "std::pair<std::vector<K>, std::vector<V>> map_to_vectors(const std::map<K, V>& m) {\n";
			outFile2 << "	std::vector<K> keys;\n";
			outFile2 << "	std::vector<V> values;\n";
			outFile2 << "	keys.reserve(m.size());\n";
			outFile2 << "	values.reserve(m.size());\n";
			outFile2 << "	for (const auto& p : m) {\n";
			outFile2 << "		keys.push_back(p.first);\n";
			outFile2 << "		values.push_back(p.second);\n";
			outFile2 << "	}\n";
			outFile2 << "	return { keys, values };\n";
			outFile2 << "}\n";
			outFile2 << "template<typename K, typename V>\n";
			outFile2 << "std::pair<std::vector<K>, std::vector<V>> map_to_vectors(const std::unordered_map<K, V>& m) {\n";
			outFile2 << "	std::vector<K> keys;\n";
			outFile2 << "	std::vector<V> values;\n";
			outFile2 << "	keys.reserve(m.size());\n";
			outFile2 << "	values.reserve(m.size());\n";
			outFile2 << "	for (const auto& p : m) {\n";
			outFile2 << "		keys.push_back(p.first);\n";
			outFile2 << "		values.push_back(p.second);\n";
			outFile2 << "	}\n";
			outFile2 << "	return { keys, values };\n";
			outFile2 << "}\n";
			outFile2 << "template<typename K, typename V>\n";
			outFile2 << "std::pair<std::vector<K>, std::vector<V>> map_to_vectors(const std::multimap<K, V>& m) {\n";
			outFile2 << "	std::vector<K> keys;\n";
			outFile2 << "	std::vector<V> values;\n";
			outFile2 << "	keys.reserve(m.size());\n";
			outFile2 << "	values.reserve(m.size());\n";
			outFile2 << "	for (const auto& p : m) {\n";
			outFile2 << "		keys.push_back(p.first);\n";
			outFile2 << "		values.push_back(p.second);\n";
			outFile2 << "	}\n";
			outFile2 << "	return { keys, values };\n";
			outFile2 << "}\n";

			outFile2 << "void hector_wrapper() {\n";
			outFile2 << "   uint32_t result;\n";
			outFile2 << "   Hector::registerOutput(\"result\", &result, 8 * sizeof(result));\n";
			outFile2 << "   Hector::beginCapture();\n";
			outFile2 << randomCode;
			outFile2 << "   result = hash_result;\n";
			outFile2 << "   Hector::endCapture();\n";
			outFile2 << "}\n";

			outFile2.close();
			std::cout << "Random STL program has been written to 'random_stl_program.cc'." << std::endl;


		}
		else {
			std::cerr << "Error: Unable to create the file." << std::endl;
		}
	}

	else if (active_mode == Jasper) {
		// Write the random code to a file
		std::ofstream outFile("random_stl_program.cpp");
		if (outFile.is_open()) {
			outFile << "#include <iostream>\n";
			outFile << "#include <vector>\n";
			outFile << "#include <set>\n";
			outFile << "#include <map>\n";
			outFile << "#include <queue>\n";
			outFile << "#include <algorithm>\n";
			outFile << "#include <initializer_list>\n";
			outFile << "#include <list>\n";
			outFile << "#include <array>\n";
			outFile << "#include <string>\n";
			outFile << "#include <unordered_set>\n";
			outFile << "#include <stack>\n";
			outFile << "#include <bitset>\n";
			outFile << "#include <unordered_map>\n";
			outFile << "#include <fstream>\n\n";
			//outFile << "#ifdef JASPER_C\n";
			//outFile << "#include <jasperc.h>\n";
			//outFile << "#endif\n\n";
			outFile << "uint32_t simple_hash(const void* data, size_t len) {\n";
			outFile << "    const uint8_t* bytes = static_cast<const uint8_t*>(data);\n";
			outFile << "    uint32_t hash = 2166136261u; // FNV offset basis\n";
			outFile << "    for (size_t i = 0; i < len; ++i) {\n";
			outFile << "        hash ^= bytes[i];\n";
			outFile << "        hash *= 16777619u; // FNV prime\n";
			outFile << "    }\n";
			outFile << "    return hash;\n";
			outFile << "}\n\n";
			outFile << "template <typename T>\n";
			outFile << "void append_data(std::vector<uint8_t>& buffer, const std::vector<T>& vec) {\n";
			outFile << "    const uint8_t* raw = reinterpret_cast<const uint8_t*>(vec.data());\n";
			outFile << "    buffer.insert(buffer.end(), raw, raw + vec.size() * sizeof(T));\n";
			outFile << "}\n\n";


			outFile << "void append_data(std::vector<uint8_t>& buffer, const std::vector<bool>& vec) {\n";
			outFile << "	for (bool b : vec) {\n";
			outFile << "		buffer.push_back(b ? 1 : 0);\n";
			outFile << "	}\n";
			outFile << "}\n\n";
			outFile << "template<typename K, typename V>\n";
			outFile << "std::pair<std::vector<K>, std::vector<V>> map_to_vectors(const std::map<K, V>& m) {\n";
			outFile << "	std::vector<K> keys;\n";
			outFile << "	std::vector<V> values;\n";
			outFile << "	keys.reserve(m.size());\n";
			outFile << "	values.reserve(m.size());\n";
			outFile << "	for (const auto& p : m) {\n";
			outFile << "		keys.push_back(p.first);\n";
			outFile << "		values.push_back(p.second);\n";
			outFile << "	}\n";
			outFile << "	return { keys, values };\n";
			outFile << "}\n";
			outFile << "template<typename K, typename V>\n";
			outFile << "std::pair<std::vector<K>, std::vector<V>> map_to_vectors(const std::unordered_map<K, V>& m) {\n";
			outFile << "	std::vector<K> keys;\n";
			outFile << "	std::vector<V> values;\n";
			outFile << "	keys.reserve(m.size());\n";
			outFile << "	values.reserve(m.size());\n";
			outFile << "	for (const auto& p : m) {\n";
			outFile << "		keys.push_back(p.first);\n";
			outFile << "		values.push_back(p.second);\n";
			outFile << "	}\n";
			outFile << "	return { keys, values };\n";
			outFile << "}\n";
			outFile << "int main() {\n";

			outFile << randomCode;
			outFile << "    uint32_t result = hash_result;\n";
			outFile << "	std::ofstream outFile(\"rtl_program.sv\");\n";
			outFile << "	if (outFile.is_open()) {\n";
			outFile << "	outFile << \"module add(\\n\";\n";
			//outFile << "	outFile << \"  input logic      clock,\\n\";\n";
			//outFile << "	outFile << \"  input logic      resetN,\\n\";\n";
			outFile << "	outFile << \"  output logic [31:0] result\\n\";\n";
			outFile << "	outFile << \"  );\\n\";\n";
			outFile << "	outFile << \"  assign result = 32'd\" + std::to_string(result) +\";\\n\";\n";
			outFile << "	outFile << \"endmodule\\n\";\n";
			outFile << "	}\n";
			outFile << "	else {\n";
			outFile << "		std::cerr << \"Error: Unable to create the file.\" << std::endl;\n";
			outFile << "	}\n";
			//outFile << "#ifdef JASPER_C\n";
			//outFile << "	JASPER_OUTPUT(out);\n";
			//outFile << "#endif\n";
			outFile << "    return 0;\n";
			outFile << "}\n";
			outFile.close();
			std::cout << "Random STL program has been written to 'random_stl_program.cpp'." << std::endl;
		}
		else {
			std::cerr << "Error: Unable to create the file." << std::endl;
		}


		std::ofstream outFile2("run_program.cpp");
		if (outFile2.is_open()) {
			outFile2 << "#include <iostream>\n";
			outFile2 << "#include <vector>\n";
			outFile2 << "#include <set>\n";
			outFile2 << "#include <map>\n";
			outFile2 << "#include <queue>\n";
			outFile2 << "#include <algorithm>\n";
			outFile2 << "#include <initializer_list>\n";
			outFile2 << "#include <list>\n";
			outFile2 << "#include <array>\n";
			outFile2 << "#include <string>\n";
			outFile2 << "#include <unordered_set>\n";
			outFile2 << "#include <stack>\n";
			outFile2 << "#include <bitset>\n";
			outFile2 << "#include <unordered_map>\n";
			outFile2 << "#include <fstream>\n\n";
			outFile2 << "#ifdef JASPER_C\n";
			outFile2 << "#include <jasperc.h>\n";
			outFile2 << "#endif\n\n";
			outFile2 << "uint32_t simple_hash(const void* data, size_t len) {\n";
			outFile2 << "    const uint8_t* bytes = static_cast<const uint8_t*>(data);\n";
			outFile2 << "    uint32_t hash = 2166136261u; // FNV offset basis\n";
			outFile2 << "    for (size_t i = 0; i < len; ++i) {\n";
			outFile2 << "        hash ^= bytes[i];\n";
			outFile2 << "        hash *= 16777619u; // FNV prime\n";
			outFile2 << "    }\n";
			outFile2 << "    return hash;\n";
			outFile2 << "}\n\n";
			outFile2 << "template <typename T>\n";
			outFile2 << "void append_data(std::vector<uint8_t>& buffer, const std::vector<T>& vec) {\n";
			outFile2 << "    const uint8_t* raw = reinterpret_cast<const uint8_t*>(vec.data());\n";
			outFile2 << "    buffer.insert(buffer.end(), raw, raw + vec.size() * sizeof(T));\n";
			outFile2 << "}\n\n";


			outFile2 << "void append_data(std::vector<uint8_t>& buffer, const std::vector<bool>& vec) {\n";
			outFile2 << "	for (bool b : vec) {\n";
			outFile2 << "		buffer.push_back(b ? 1 : 0);\n";
			outFile2 << "	}\n";
			outFile2 << "}\n\n";
			outFile2 << "template<typename K, typename V>\n";
			outFile2 << "std::pair<std::vector<K>, std::vector<V>> map_to_vectors(const std::map<K, V>& m) {\n";
			outFile2 << "	std::vector<K> keys;\n";
			outFile2 << "	std::vector<V> values;\n";
			outFile2 << "	keys.reserve(m.size());\n";
			outFile2 << "	values.reserve(m.size());\n";
			outFile2 << "	for (const auto& p : m) {\n";
			outFile2 << "		keys.push_back(p.first);\n";
			outFile2 << "		values.push_back(p.second);\n";
			outFile2 << "	}\n";
			outFile2 << "	return { keys, values };\n";
			outFile2 << "}\n";
			outFile2 << "template<typename K, typename V>\n";
			outFile2 << "std::pair<std::vector<K>, std::vector<V>> map_to_vectors(const std::unordered_map<K, V>& m) {\n";
			outFile2 << "	std::vector<K> keys;\n";
			outFile2 << "	std::vector<V> values;\n";
			outFile2 << "	keys.reserve(m.size());\n";
			outFile2 << "	values.reserve(m.size());\n";
			outFile2 << "	for (const auto& p : m) {\n";
			outFile2 << "		keys.push_back(p.first);\n";
			outFile2 << "		values.push_back(p.second);\n";
			outFile2 << "	}\n";
			outFile2 << "	return { keys, values };\n";
			outFile2 << "}\n";
			outFile2 << "int main() {\n";

			outFile2 << randomCode;
			outFile2 << "    unsigned int result = hash_result;\n";
			outFile2 << "#ifdef JASPER_C\n";
			outFile2 << "	JASPER_OUTPUT(result);\n";
			outFile2 << "#endif\n";
			outFile2 << "    return 0;\n";
			outFile2 << "}\n";
			outFile2.close();
			std::cout << "Random STL program has been written to 'run_profram.cpp'." << std::endl;


		}
		else {
			std::cerr << "Error: Unable to create the file." << std::endl;
		}



	}



	return 0;
}