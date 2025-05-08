#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <initializer_list>
#include <format>
#include <string>

int RdmInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
std::vector<std::vector<int>> vec_0 = { {0, 1, -58, -9, 1}, {70, 1, -41, 59, -60}, {61, -83, -85, 0, 1}, {-6, -92, 1, -97, 0}, {1, -83, 40, 84, 0}, {1, -96, 6, 0, 89}, {1, 84, 1, 1, 1}, {-38, 1, 1, 0, 0}, {19, 1, 0, 1, -40}, {1, 81, 30, -99, 6} };
for (const auto& row : vec_0) { 
	for (const auto& val : row) {
		std::cout << val << ""; 
	}
	std::cout << std::endl;
}
std::vector<std::vector<int>> vec_1 = { {0, -11, 36, -56, 70}, {24, 1, -77, 0, -32}, {-96, 12, -13, 1, 1}, {0, 1, 1, 1, 1}, {1, 0, 37, 1, 92}, {1, 0, 80, 0, 37}, {0, -80, -53, 0, 0}, {0, -77, 83, 41, 0}, {-31, 1, 0, 7, 0}, {1, 0, -12, -91, 1} };
for (const auto& row : vec_1) { 
	for (const auto& val : row) {
		std::cout << val << ""; 
	}
	std::cout << std::endl;
}
std::vector<std::vector<int>> vec_2 = { {-74, 1, 0, 1, 8}, {28, 0, 1, 1, 17}, {1, 12, 10, -72, 0}, {38, -43, 0, 1, 0}, {-12, 1, -85, 1, 75}, {2, 83, 0, 10, 85}, {0, 1, 0, -38, 1}, {0, -73, 0, 39, 0}, {65, 0, -91, 51, 0}, {1, 56, 96, 27, 1} };
for (const auto& row : vec_2) { 
	for (const auto& val : row) {
		std::cout << val << ""; 
	}
	std::cout << std::endl;
}
std::vector<std::vector<int>> vec_3 = { {1, -72, 96, 58, 1}, {0, 0, 22, 0, 0}, {0, -91, 1, 0, -81}, {42, 1, 1, 1, -89}, {0, 0, 56, 1, 1}, {1, -21, 1, 1, 47}, {13, 99, 29, -37, 1}, {0, 1, 1, 1, 0}, {0, 1, 1, 1, 35}, {1, 29, 0, 28, 1} };
for (const auto& row : vec_3) { 
	for (const auto& val : row) {
		std::cout << val << ""; 
	}
	std::cout << std::endl;
}
std::vector<std::vector<int>> vec_4 = { {72, -38, 1, 0, -35}, {1, 1, 0, -77, 0}, {-67, -68, 0, 60, 1}, {3, 47, 0, 1, 0}, {0, -46, 1, -69, 1}, {0, 0, 0, 0, -21}, {17, 1, 1, 38, -38}, {1, 1, -16, 49, 9}, {-39, 1, 92, 91, 43}, {1, 0, 1, 74, 88} };
for (const auto& row : vec_4) { 
	for (const auto& val : row) {
		std::cout << val << ""; 
	}
	std::cout << std::endl;
}
std::vector<std::vector<int>> vec_5 = { {-60, -39, 1, 0, 67}, {8, -100, -64, 86, 0}, {1, -60, -50, 1, 16}, {80, 88, 0, 1, 1}, {85, 1, -36, 0, 0}, {0, -1, 8, -4, 1}, {31, -92, -85, 1, 0}, {24, 32, 92, 32, 1}, {1, 0, 1, 0, 0}, {1, 61, -69, -60, 64} };
for (const auto& row : vec_5) { 
	for (const auto& val : row) {
		std::cout << val << ""; 
	}
	std::cout << std::endl;
}
    return 0;
}
