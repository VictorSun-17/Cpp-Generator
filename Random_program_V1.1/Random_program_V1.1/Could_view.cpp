#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>

// Function to generate a random integer within a range
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to generate a random STL container operation
std::string generateRandomSTLCode() {
    std::string code;
    int choice = randomInt(1, 5);

    switch (choice) {
    case 1: // Vector operations
        code += "#include <vector>\n";
        code += "std::vector<int> vec = {1, 2, 3, 4, 5};\n";
        code += "vec.push_back(6);\n";
        code += "for (int x : vec) std::cout << x << ' ';\n";
        code += "std::cout << std::endl;\n";
        break;

    case 2: // Set operations
        code += "#include <set>\n";
        code += "std::set<int> s = {1, 2, 3, 4, 5};\n";
        code += "s.insert(6);\n";
        code += "for (int x : s) std::cout << x << ' ';\n";
        code += "std::cout << std::endl;\n";
        break;

    case 3: // Map operations
        code += "#include <map>\n";
        code += "std::map<int, std::string> m;\n";
        code += "m[1] = \"one\";\n";
        code += "m[2] = \"two\";\n";
        code += "for (const auto& p : m) std::cout << p.first << : << p.second << '\\n';\n";
        break;

    case 4: // Queue operations
        code += "#include <queue>\n";
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
        code += "#include <algorithm>\n#include <vector>\n";
        code += "std::vector<int> vec = {5, 3, 4, 1, 2};\n";
        code += "std::sort(vec.begin(), vec.end());\n";
        code += "for (int x : vec) std::cout << x << ' ';\n";
        code += "std::cout << std::endl;\n";
        break;
    }

    return code;
}

int source() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate random C++ code
    std::string randomCode = generateRandomSTLCode();

    // Write the random code to a file
    std::ofstream outFile("random_stl_program.cpp");
    if (outFile.is_open()) {
        outFile << "#include <iostream>\n\n";
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