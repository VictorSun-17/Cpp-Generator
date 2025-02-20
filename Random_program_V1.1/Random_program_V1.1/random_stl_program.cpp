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
std::vector<bool> vec_1 = {1, 0, 1, 0, 0, 0};
for (bool num : vec_1) { 
	std::cout << num << ' ';
	std::cout << std::endl;
}
std::vector<float> vec_2 = {43.000000, 0.000000, -1.034576, -44.000000, 19.000000, 1.000000};
for (float num : vec_2) { 
	std::cout << num << ' ';
	std::cout << std::endl;
}
std::vector<float> vec_3 = {0.000000, 3.000000, 20.517601, 42.387161, 0.000000, 50.584427, 1.000000, 1.000000};
for (float num : vec_3) { 
	std::cout << num << ' ';
	std::cout << std::endl;
}
std::vector<char> vec_4 = {71, 102, 52, 65, 88, 81, 104, 80, 97, 76};
for (char num : vec_4) { 
	std::cout << num << ' ';
	std::cout << std::endl;
}
std::vector<int> vec_5 = {-54, 0, 1, 0, -59, 1, 1, -80, -80, 76};
for (int num : vec_5) { 
	std::cout << num << ' ';
	std::cout << std::endl;
}
vec_2.clear();
vec_2.assign(63,6);
vec_1.cbegin();
vec_2.swap(2); 
vec_1.reserve(8926); 
vec_4.cend();
vec_5.assign(4, 21);
vec_1.crbegin();
vec_2.push_back(7); 
vec_1.emplace(vec_1.begin() + 15,82); 
vec_1.shrink_to_fit();
vec_4.at(16); 
vec_3.assign(85,72);
vec_3.max_size();
vec_3.erase(vec_3.begin() + 9); 
vec_5.rend();
vec_1.clear();
vec_2.rend();
vec_2.cend();
vec_1.insert(vec_1.begin() + 1,47); 
vec_4.emplace_back(18);
vec_3.push_back(38); 
vec_4.rbegin();
using ElementType = decltype(vec_5)::value_type;
const char* type = typeid(ElementType).name();
std::string current_type = std::string(type);
vec_1.cend();
vec_5.assign(23,69);
vec_1.size();
vec_1.front();
vec_3.resize(15);
vec_1.cend();
vec_5.assign(6, 23);
vec_1.back();
vec_1.end();
vec_4.rbegin();
vec_5.clear();
vec_1.emplace_back(55);
vec_5.rend();
vec_1.end();
vec_3.front();
vec_5.push_back(74); 
vec_1.rend();
using ElementType = decltype(vec_2)::value_type;
const char* type = typeid(ElementType).name();
std::string current_type = std::string(type);
vec_5.rend();
vec_3.clear();
vec_3.clear();
vec_3.cend();
vec_5.clear();
vec_5.erase(vec_5.begin() + 58); 
vec_5.front();
vec_4.emplace_back(15);
vec_1.reserve(5649); 
vec_2.assign(1,62);
vec_4.size();
using ElementType = decltype(vec_1)::value_type;
const char* type = typeid(ElementType).name();
std::string current_type = std::string(type);
vec_2.rbegin();
vec_5.capacity();
vec_1.rend();
vec_4.resize(20);
vec_3.front();
vec_5.size();
    return 0;
}
