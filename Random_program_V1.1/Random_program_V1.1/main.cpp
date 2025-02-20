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
#include "Vector_ops.h"
#include "Vector_create.h"
#include "Set_create.h"
#include "Set_ops.h"


// Function to generate a random STL container operation
std::string generateRandomSTLCode() {
	std::string code;
	int choice = random_Int(1, 5);
	int times = random_Int(1, 10);
	int operation_numbers = random_Int(1, 10);
	int random_value = random_Int(1, 100);
	int number_of_vecs = random_Int(5, 10);
	int number_of_sets = random_Int(5, 10);
	int i = 0;
	int n = 0;
	//std::string random_ops = random_vec_op();

	switch (1) {
	case 1: // Vector operations

		for (n = 1; n <= number_of_vecs; n++) {

			code += create_vec(n);
		}

		
		code += random_vec_op(number_of_vecs);



		/*      code += random_ops;*/

		break;


		// Set 是 C++ 标准库中的一个关联容器，它存储唯一的元素，并按照特定顺序进行排序。
		// 它通常基于红黑树实现，因此查找、插入和删除操作的平均时间复杂度为 O(log n)
	case 2: 
		for (n = 1; n <= number_of_sets; n++) {

			code += create_set(n);
		}

		code += random_set_op(number_of_sets);

		break;

	case 3: // Map operations
		code += "std::map<int, std::string> m;\n";
		code += "m[1] = \"one\";\n";
		code += "m[2] = \"two\";\n";
		code += "for (const auto& p : m) std::cout << p.first << : << p.second << '\\n';\n";
		break;

	case 4: // Queue operations
		code += "std::queue<int> q;\n";
		code += "q.push(1);\n";
		code += "q.push(2);\n";
		code += "q.push(3);\n";
		code += "while (!q.empty()) {\n";
		code += "    std::cout << q.front() << ' ';\n";
		code += "    q.pop();\n";
		code += "}\n";
		code += "std::cout << std::endl;\n";
		break;

	case 5: // Random algorithm usage
		code += "std::vector<int> vec = {5, 3, 4, 1, 2};\n";
		code += "std::sort(vec.begin(), vec.end());\n";
		code += "for (int x : vec) std::cout << x << ' ';\n";
		code += "std::cout << std::endl;\n";
		break;
	}

	return code;
}



int main() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	// Generate random C++ code
	std::string randomCode = generateRandomSTLCode();

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
		outFile << "#include <format>\n";
		outFile << "#include <string>\n\n";
		outFile << "int RdmInt(int min, int max) {\n";
		outFile << "    return min + rand() % (max - min + 1);\n";
		outFile << "}\n\n";
		outFile << "int main() {\n";
		outFile << randomCode;
		outFile << "    return 0;\n";
		outFile << "}\n";
		outFile.close();
		std::cout << "Random STL program has been written to 'random_stl_program.cpp'." << std::endl;
	}
	else {
		std::cerr << "Error: Unable to create the file." << std::endl;
	}

	return 0;
}