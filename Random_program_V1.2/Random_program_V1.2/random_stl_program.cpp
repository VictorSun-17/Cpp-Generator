#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <initializer_list>
#include <string>

#ifdef JASPER_C
#include <jasperc.h>
#endif
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
	std::vector<std::vector<int>> vec_0 = { {1, 96, -20, 0, -81, 0, 59, -79}, {5, 10, 91, 17, 1, 0, 0, 35} };
	std::vector<int> vec_1 = { -34, 0, 1, 0, 27, -41, 40, -86 };
	std::vector<double> vec_2 = { -78.624832, -17.000000, 1.000000, 28.318115, 31.467635, 1.000000, -32.334361, -65.874203 };
	std::vector<float> vec_3 = { 69.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 47.000000, 1.000000 };
	std::vector<float> vec_4 = { 0.000000, -32.000000, -24.000000, 8.000000, 0.000000, 1.000000, 66.000000, 1.000000 };
	std::vector<std::vector<char>> vec_5 = { {67, 99, 75, 73, 88, 80, 90, 50}, {101, 79, 79, 116, 105, 71, 72, 114} };
	std::vector<char> vec_6 = { 117, 120, 51, 51, 56, 110, 66, 90 };
	std::vector<std::vector<double>> vec_7 = { {0.000000, 29.331345, 0.000000, -98.736534, -48.045288, 60.000000, -16.989654, 1.000000}, {0.000000, 83.391827, 1.000000, 1.000000, 92.000000, -93.670464, 1.000000, -82.384720} };
	std::vector<double> vec_8 = { -99.047821, -45.000000, -35.087130, 28.354747, -25.000000, -27.359844, -19.000000, 57.304611 };
	std::vector<int> vec_9 = { 18, 76, -27, 0, 0, 1, -51, 31 };
	vec_7.pop_back();
	vec_5.push_back({ 69, 121, 48, 108, 54 });
	vec_3.begin();
	vec_1.at(RdmInt(0, vec_1.size() - 1));
	vec_7.rbegin();
	vec_5.reserve(1948);
	vec_5.cend();
	vec_7.push_back({ 64.000000, -99.072237, 3.311249, 4.342781, 0.000000, 0.000000, -47.318947, 33.829773 });
	vec_1.shrink_to_fit();
	std::sort(vec_8.begin(), vec_8.end());
	vec_6.shrink_to_fit();
	vec_5.end();
	vec_3.crend();
	vec_5.crend();
	vec_4.emplace(vec_4.begin() + RdmInt(0, vec_4.size() - 1), 97.344894);
	vec_8.resize(8, 55.870235);
	vec_6.crbegin();
	vec_9.emplace(vec_9.begin() + RdmInt(0, vec_9.size() - 1), 86);
	vec_5.clear();
	vec_3.cbegin();
	vec_0.rend();
	vec_7.push_back({ 18.472854, -50.000000, 1.000000, 6.000000, 1.000000 });
	vec_5.rbegin();
	vec_2.emplace(vec_2.begin() + RdmInt(0, vec_2.size() - 1), 20.993683);
	vec_4.emplace(vec_4.begin() + RdmInt(0, vec_4.size() - 1), 33.579514);
	vec_3.end();
	vec_3.at(RdmInt(0, vec_3.size() - 1));
	vec_6.emplace_back(111);
	vec_9.size();
	vec_4.shrink_to_fit();
	vec_9.assign(15, 7);
	vec_4.clear();
	vec_4.capacity();
	std::reverse(vec_4.begin(), vec_4.end());
	vec_2.emplace_back(89.190344);
	vec_1.begin();
	vec_7.max_size();
	vec_4.begin();
	vec_1.shrink_to_fit();
	vec_7.rbegin();
	vec_5.begin();
	vec_4.max_size();
	vec_1.rbegin();
	vec_9.end();
	vec_8.front();
	vec_9.cend();
	vec_4.end();
	std::sort(vec_0.begin(), vec_0.end());
	vec_9.shrink_to_fit();
	vec_1.crbegin();
	vec_3.capacity();
	vec_0.rbegin();
	vec_9.cend();
	vec_1.empty();
	std::reverse(vec_2.begin(), vec_2.end());
	vec_2.shrink_to_fit();
	vec_0.cbegin();
	vec_6.assign(25, 98);
	vec_3.capacity();
	vec_6.capacity();
	vec_3.assign(13, 4.550316);
	vec_9.insert(vec_9.begin() + 1, -32);
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

	std::set<std::set<bool>> set_0 = { {0, 1}, {0, 1} };
	std::set<std::set<double>> set_1 = { {-51.658680, -23.000000, 19.370098, 28.708755, 44.132812}, {-40.726951, -17.532883, 8.096561, 9.000000, 77.000000} };
	std::set<std::set<float>> set_2 = { {-77.000000, 0.000000, 1.000000, 44.000000, 96.000000}, {0.000000, 1.000000} };
	std::set<std::set<double>> set_3 = { {-38.000000, 0.000000, 1.000000, 55.000000, 79.631943}, {-63.000000, 0.000000, 19.919431, 32.407605, 55.000000} };
	std::set<std::set<bool>> set_4 = { {0, 1}, {0, 1} };
	std::set<std::set<float>> set_5 = { {-34.000000, 0.000000, 1.000000, 92.000000}, {0.000000, 19.000000, 40.000000, 72.000000, 93.000000} };
	std::set<char> set_6 = { 49, 67, 71, 81, 114 };
	std::set<std::set<float>> set_7 = { {-32.000000, 0.000000, 1.000000, 2.000000}, {-66.000000, 0.000000, 1.000000, 62.000000} };
	std::set<bool> set_8 = { 0, 1 };
	std::set<double> set_9 = { -39.000000, -34.000000, 0.000000, 1.000000 };
	set_4.crend();
	set_9.size();
	set_4.cbegin();
	set_8.crend();
	auto ithigh_11 = set_1.upper_bound({ -84.862819, -78.069397, 0.000000, 39.945679, 89.861751 });
	set_6.crend();
	auto it_13 = set_0.find({ 0, 1 });
	set_6.rbegin();
	set_6.end();
	set_1.max_size();
	set_1.rbegin();
	auto ithigh_18 = set_6.upper_bound(56);
	set_8.size();
	auto it_20 = next(set_9.begin(), 2);
	set_9.erase(it_20);
	set_8.max_size();
	set_3.clear();
	set_2.crbegin();
	set_7.count({ 0.000000, 1.000000, 20.000000, 68.000000 });
	set_1.max_size();
	set_6.cbegin();
	set_0.count({ 0, 1 });
	set_0.crend();
	set_1.empty();
	set_2.rbegin();
	set_8.clear();
	set_0.crend();
	set_5.crend();
	auto ithigh_34 = set_7.upper_bound({ -78.000000, -77.000000, -64.000000, 0.000000, 1.000000, 49.000000 });
	auto alloc_35 = set_9.get_allocator();
	set_1.cend();
	set_4.cbegin();
	auto ithigh_39 = set_7.upper_bound({ -10.000000, 0.000000, 1.000000, 19.000000, 24.000000, 51.000000 });
	set_8.size();
	set_2.cend();
	set_2.insert({ -88.000000, -77.000000, -31.000000, 0.000000, 1.000000, 23.000000, 69.000000 });
	set_0.max_size();
	set_8.clear();
	set_1.clear();
	set_6.rbegin();
	set_0.rbegin();
	set_2.begin();
	set_0.rbegin();
	set_6.emplace(85);
	set_8.rbegin();
	set_9.crend();
	set_4.rbegin();
	set_0.clear();
	set_2.begin();
	set_7.clear();
	auto ithigh_63 = set_7.upper_bound({ -35.000000, -9.000000, 0.000000, 1.000000, 14.000000, 88.000000 });
	set_6.cend();
	set_6.insert(75);
	set_8.clear();
	set_6.end();
	set_1.empty();
	set_0.empty();
	set_2.crend();
	set_0.insert({ 0, 1 });
	auto range_73 = set_6.equal_range(90);
	set_5.max_size();
	auto itlow_75 = set_9.lower_bound(-7.132176);
	auto it_76 = next(set_4.begin(), 0);
	set_4.erase(it_76);
	auto it_77 = set_8.find(0);
	auto alloc_80 = set_1.get_allocator();
	set_9.cbegin();
	set_2.clear();
	set_2.max_size();
	set_9.cbegin();
	auto alloc_92 = set_0.get_allocator();
	auto alloc_94 = set_4.get_allocator();
	set_2.rend();

	std::vector<std::set<bool>> newset_0(set_0.begin(), set_0.end());
	append_data(buffer, newset_0);
	std::vector<std::set<double>> newset_1(set_1.begin(), set_1.end());
	append_data(buffer, newset_1);
	std::vector<std::set<float>> newset_2(set_2.begin(), set_2.end());
	append_data(buffer, newset_2);
	std::vector<std::set<double>> newset_3(set_3.begin(), set_3.end());
	append_data(buffer, newset_3);
	std::vector<std::set<bool>> newset_4(set_4.begin(), set_4.end());
	append_data(buffer, newset_4);
	std::vector<std::set<float>> newset_5(set_5.begin(), set_5.end());
	append_data(buffer, newset_5);
	std::vector<char> newset_6(set_6.begin(), set_6.end());
	append_data(buffer, newset_6);
	std::vector<std::set<float>> newset_7(set_7.begin(), set_7.end());
	append_data(buffer, newset_7);
	std::vector<bool> newset_8(set_8.begin(), set_8.end());
	append_data(buffer, newset_8);
	std::vector<double> newset_9(set_9.begin(), set_9.end());
	append_data(buffer, newset_9);

	//std::set <int> set_11(vec_5.begin(), vec_5.end());
	//std::vector<int> vec_11(set_2.begin(), set_2.end());
	//std::vector<int> vec_12(set_2.begin(), set_2.end());
	uint32_t hash_result = simple_hash(buffer.data(), buffer.size());
	unsigned int out = hash_result;
#ifdef JASPER_C
	JASPER_OUTPUT(out);
#endif
	return 0;
}
