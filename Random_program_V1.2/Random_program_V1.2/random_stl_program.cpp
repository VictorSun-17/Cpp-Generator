#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <initializer_list>
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
	std::vector<std::vector<int>> vec_0 = { {1, 0, 1, -4, 1, 83}, {0, -60, 58, 0, 0, 20}, {6, 36, 66, 0, 0, 1}, {1, 1, 1, 7, -97, 3} };
	std::vector<int> vec_1 = {61, 11, -81, -15, 0, -45};
	std::vector<double> vec_2 = {0.000000, 76.201666, 0.000000, -7.925657, -2.053902, -79.000000};
	std::vector<std::vector<float>> vec_3 = { {26.000000, 1.000000, 51.000000, 97.650070, -45.000000, 44.987335}, {0.000000, 0.000000, -98.907440, 34.000000, -27.402565, -6.000000}, {0.000000, -17.581711, 0.000000, -2.639854, 0.000000, -41.776787}, {-19.388405, 3.744629, 13.000000, 90.000000, 33.951843, 29.337448} };
	std::vector<std::vector<double>> vec_4 = { {40.140991, 25.125889, -60.673847, 1.000000, 6.000000, 0.000000}, {-12.100589, 1.000000, 1.028481, 78.000000, 14.816734, 1.000000}, {-81.017487, 0.000000, 1.000000, 71.000000, 23.087252, 1.000000}, {0.000000, 46.733002, -85.467086, 23.258163, -17.227699, 1.000000} };
	std::vector<double> vec_5 = {0.000000, 1.000000, -23.000000, -29.221474, 57.000000, -71.000000};
	std::vector<bool> vec_6 = {1, 0, 1, 1, 0, 1};
	std::vector<char> vec_7 = {103, 99, 73, 81, 90, 99};
	std::vector<double> vec_8 = {-71.000000, 0.000000, 57.000000, -11.044649, 3.701895, 81.658376};
	std::vector<double> vec_9 = {25.000000, -48.735008, 52.000000, -43.253883, 0.000000, 1.000000};
	std::vector<std::vector<int>> vec_10 = { {1, 61, -52, -7, 1, 1}, {1, 25, 0, 59, 1, 1}, {0, 9, 0, 0, 0, -66}, {27, 1, -60, 31, 1, 0} };
	std::vector<bool> vec_11 = {0, 1, 1, 1, 1, 1};
	std::vector<std::vector<float>> vec_12 = { {0.000000, 1.000000, -82.000000, 1.000000, 66.000000, -59.801018}, {0.000000, 0.000000, 27.000000, 73.448898, 10.000000, -22.598961}, {1.000000, 1.000000, 1.000000, 40.000000, 1.000000, 33.664963}, {-32.499161, 19.000000, 7.000000, 0.000000, 0.000000, 86.907547} };
	vec_9.crend();
	vec_6.at(RdmInt(0, vec_6.size()-1)); 
	vec_10.pop_back();
	vec_0.back();
	vec_5.emplace_back(13);
	vec_2.size();
	vec_1.emplace_back(83);
	vec_2.rbegin();
	vec_8.capacity();
	vec_3.cbegin();
	vec_8.empty();
	vec_9.capacity();
	vec_9.emplace(vec_9.begin() + RdmInt(0, vec_9.size()-1) ,66); 
	vec_5.rend();
	vec_9.push_back(24); 
	vec_6.front();
	vec_5.assign(3, 44);
	vec_12.emplace_back(13);
	vec_12.insert(vec_12.begin() + RdmInt(0, vec_12.size()-1),48); 
	vec_11.reserve(5397); 
	vec_8.push_back(31); 
	vec_2.max_size();
	vec_7.clear();
	vec_9.front();
	vec_2.clear();
	vec_8.back();
	vec_10.emplace_back(93);
	vec_5.resize(9);
	vec_9.front();
	vec_0.resize(20);
	vec_5.rend();
	vec_9.rbegin();
	vec_4.erase(vec_4.begin() + RdmInt(0, vec_4.size()-1)); 
	vec_2.emplace_back(81);
	std::reverse(vec_2.begin(), vec_2.end());
	vec_7.crbegin();
	vec_8.cbegin();
	vec_11.emplace_back(23);
	vec_12.emplace(vec_12.begin() + RdmInt(0, vec_12.size()-1) ,21); 
	std::sort(vec_2.begin(), vec_2.end());
	vec_1.empty();
	std::sort(vec_5.begin(), vec_5.end());
	vec_12.push_back(92); 
	vec_1.shrink_to_fit();
	vec_6.at(RdmInt(0, vec_6.size()-1)); 
	vec_4.assign(7, {1, 23, 6, 1});
	vec_12.clear();
	vec_5.pop_back();
	vec_9.crend();
	vec_12.capacity();
	vec_6.clear();
	vec_6.crbegin();
	vec_2.emplace_back(74);
	vec_4.crend();
	vec_0.pop_back();
	vec_10.crend();
	vec_12.max_size();
	vec_0.clear();
	vec_2.emplace(vec_2.begin() + RdmInt(0, vec_2.size()-1) ,53); 
	vec_6.begin();
	vec_6.assign(7, 1);
	vec_9.resize(20);
	vec_2.pop_back();
	vec_0.front();
	vec_2.cbegin();
	vec_12.cend();
	vec_4.erase(vec_4.begin() + RdmInt(0, vec_4.size()-1)); 
	vec_6.shrink_to_fit();
	vec_7.insert(vec_7.begin() + RdmInt(0, vec_7.size()-1),88); 
	vec_0.erase(vec_0.begin() + RdmInt(0, vec_0.size()-1)); 
	vec_2.shrink_to_fit();
	vec_1.size();
	vec_1.rbegin();
	vec_4.at(RdmInt(0, vec_4.size()-1)); 
	vec_1.size();
	vec_10.size();
	vec_11.capacity();
	vec_3.cend();
	vec_12.crend();
	vec_10.at(RdmInt(0, vec_10.size()-1)); 
	vec_3.emplace(vec_3.begin() + RdmInt(0, vec_3.size()-1) ,39); 
	vec_9.shrink_to_fit();
	vec_1.pop_back();
	vec_1.rend();
	vec_5.capacity();
	vec_3.capacity();
	vec_0.empty();
	vec_0.clear();
	std::reverse(vec_0.begin(), vec_0.end());
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
	append_data(buffer, vec_10);
	append_data(buffer, vec_11);
	append_data(buffer, vec_12);
	uint32_t hash_result = simple_hash(buffer.data(), buffer.size());
	std::cout << "32 - bit hash : 0x" << std::hex << hash_result << std::dec << std::endl;

    return 0;
}
