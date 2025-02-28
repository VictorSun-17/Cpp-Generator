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
std::vector<char> vec_0 = {114, 119, 106, 73, 112};
for (char num : vec_0) { 
	std::cout << num << ' ';
	std::cout << std::endl;
}
std::vector<float> vec_1 = {1.000000, -44.212162, 82.000000, 1.000000, -10.000000};
for (float num : vec_1) { 
	std::cout << num << ' ';
	std::cout << std::endl;
}
std::vector<float> vec_2 = {0.000000, 1.000000, -6.000000, -2.000000, -64.323868};
for (float num : vec_2) { 
	std::cout << num << ' ';
	std::cout << std::endl;
}
std::vector<double> vec_3 = {0.000000, 0.000000, 0.000000, 77.819147, -82.348094};
for (double num : vec_3) { 
	std::cout << num << ' ';
	std::cout << std::endl;
}
std::vector<float> vec_4 = {-86.000000, -57.000000, 84.000000, 13.730278, -31.000000};
for (float num : vec_4) { 
	std::cout << num << ' ';
	std::cout << std::endl;
}
std::vector<char> vec_5 = {49, 99, 100, 53, 53};
for (char num : vec_5) { 
	std::cout << num << ' ';
	std::cout << std::endl;
}
vec_3.end();
vec_5.rbegin();
vec_3.emplace(vec_3.begin() + RdmInt(0, vec_3.size()-1) ,34); 
vec_4.size();
vec_3.cbegin();
vec_1.shrink_to_fit();
vec_0.shrink_to_fit();
std::sort(vec_5.begin(), vec_5.end());
vec_2.max_size();
std::sort(vec_1.begin(), vec_1.end());
vec_2.begin();
vec_5.insert(vec_5.begin() + RdmInt(0, vec_5.size()-1),38); 
vec_0.clear();
vec_0.crend();
vec_5.back();
vec_4.crbegin();
std::reverse(vec_0.begin(), vec_0.end());
vec_1.cend();
vec_0.shrink_to_fit();
vec_4.back();
vec_5.cbegin();
vec_5.emplace_back(64);
vec_4.emplace_back(64);
vec_3.reserve(9069); 
std::sort(vec_5.begin(), vec_5.end());
vec_5.back();
vec_3.insert(vec_3.begin() + RdmInt(0, vec_3.size()-1),30); 
vec_4.empty();
vec_3.crend();
vec_0.empty();
vec_4.assign(4, 7);
vec_2.push_back(76); 
vec_4.clear();
vec_0.push_back(78); 
vec_3.reserve(7942); 
std::reverse(vec_2.begin(), vec_2.end());
vec_2.resize(8);
vec_3.rend();
vec_1.size();
vec_4.reserve(1585); 
std::reverse(vec_5.begin(), vec_5.end());
vec_0.crend();
std::sort(vec_2.begin(), vec_2.end());
vec_4.emplace_back(53);
vec_4.assign(7, 5);
vec_0.shrink_to_fit();
vec_2.clear();
vec_0.clear();
vec_3.clear();
vec_5.rend();
vec_2.swap(vec_1);
    return 0;
}
