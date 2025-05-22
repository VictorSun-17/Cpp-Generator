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
	if (max - min + 1 != 0)
		return min + rand() % (max - min + 1);
	else
		return 0;
}

uint32_t simple_hash(const void* data, size_t len) {
    const uint8_t* bytes = static_cast<const uint8_t*>(data);
    uint32_t hash = 2166136261u; // FNV offset basis
    for (size_t i = 0; i < len; ++i) {
        hash ^= bytes[i];
        hash *= 16777619u; // FNV prime
    }
    return hash;
}

template <typename T>
void append_data(std::vector<uint8_t>& buffer, const std::vector<T>& vec) {
    const uint8_t* raw = reinterpret_cast<const uint8_t*>(vec.data());
    buffer.insert(buffer.end(), raw, raw + vec.size() * sizeof(T));
}

void append_data(std::vector<uint8_t>& buffer, const std::vector<bool>& vec) {
	for (bool b : vec) {
		buffer.push_back(b ? 1 : 0);
	}
}

int main() {
	std::vector<bool> vec_0 = {0, 1, 0, 0, 1, 1, 1, 1, 0};
	std::vector<int> vec_1 = {1, 1, 1, 0, 1, 0, 51, -91, -86};
	std::vector<int> vec_2 = {-20, 0, 11, 0, -58, 0, 84, 5, 86};
	std::vector<double> vec_3 = {49.235511, -22.000000, 31.241798, 14.774010, 46.928314, -30.668050, 1.000000, -1.443525, -41.319010};
	std::vector<bool> vec_4 = {1, 0, 1, 0, 1, 1, 0, 0, 1};
	std::vector<bool> vec_5 = {1, 0, 0, 0, 0, 0, 0, 1, 1};
	std::vector<bool> vec_6 = {1, 1, 0, 1, 1, 1, 1, 0, 1};
	std::vector<bool> vec_7 = {0, 1, 1, 1, 0, 0, 1, 1, 1};
	std::vector<char> vec_8 = {106, 116, 69, 48, 117, 119, 89, 76, 118};
	std::vector<char> vec_9 = {71, 73, 117, 105, 78, 121, 109, 106, 105};
	vec_2.at(RdmInt(0, vec_2.size()-1)); 
	vec_8.resize(15);
	vec_0.crbegin();
	vec_5.assign(5, 4);
	std::reverse(vec_1.begin(), vec_1.end());
	vec_0.insert(vec_0.begin() + RdmInt(0, vec_0.size()-1),87); 
	vec_1.empty();
	vec_5.crbegin();
	vec_3.begin();
	vec_9.assign(3, 48);
	vec_2.shrink_to_fit();
	vec_4.max_size();
	vec_4.rbegin();
	vec_4.size();
	vec_9.emplace(vec_9.begin() + RdmInt(0, vec_9.size()-1) ,53); 
	vec_7.cbegin();
	vec_8.assign(37,91);
	vec_5.insert(vec_5.begin() + RdmInt(0, vec_5.size()-1),42); 
	vec_6.crbegin();
	vec_5.front();
	vec_2.insert(vec_2.begin() + RdmInt(0, vec_2.size()-1),45); 
	vec_9.max_size();
	vec_3.reserve(7594); 
	vec_1.erase(vec_1.begin() + RdmInt(0, vec_1.size()-1)); 
	vec_7.cend();
	vec_2.shrink_to_fit();
	std::sort(vec_2.begin(), vec_2.end());
	vec_3.cend();
	vec_7.erase(vec_7.begin() + RdmInt(0, vec_7.size()-1)); 
	vec_9.front();
	vec_1.crend();
	vec_6.crbegin();
	vec_7.max_size();
	vec_8.rbegin();
	vec_0.clear();
	vec_4.assign(4,13);
	vec_4.size();
	vec_1.shrink_to_fit();
	vec_2.emplace_back(88);
	vec_3.pop_back();
	std::vector<uint8_t> buffer;
	append_data(buffer, vec_0);
	append_data(buffer, vec_1);
	append_data(buffer, vec_2);
	append_data(buffer, vec_3);
	append_data(buffer, vec_4);
	append_data(buffer, vec_5);
	append_data(buffer, vec_6);
	append_data(buffer, vec_7);
	append_data(buffer, vec_8);
	append_data(buffer, vec_9);
	uint32_t hash_result = simple_hash(buffer.data(), buffer.size());
	std::cout << "32 - bit hash : 0x" << std::hex << hash_result << std::dec << std::endl;

    return 0;
}
