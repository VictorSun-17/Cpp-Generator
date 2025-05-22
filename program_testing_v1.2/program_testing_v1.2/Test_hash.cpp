#include <iostream>
#include <vector>
#include <cstdint>
#include <cstring>

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

int main1() {
    std::vector<float> vec_0 = { -97.930847, -5.355995, 0.000000, 81.000000, -95.281837 };
    std::vector<int> vec_1 = { 37, 56, -7, 44, -27 };
    std::vector<char> vec_2 = { 101, 97, 53, 115, 70 };
    std::vector<char> vec_3 = { 78, 116, 97, 104, 115 };
    std::vector<int> vec_4 = { -62, 1, 0, -91, 1 };
    std::vector<int> vec_5 = { 21, 34, -35, 31, 1 };
    std::vector<char> vec_6 = { 99, 112, 103, 112, 73 };

    std::vector<uint8_t> buffer;
    append_data(buffer, vec_0);
    append_data(buffer, vec_1);
    append_data(buffer, vec_2);
    append_data(buffer, vec_3);
    append_data(buffer, vec_4);
    append_data(buffer, vec_5);
    append_data(buffer, vec_6);

    uint32_t hash_result = simple_hash(buffer.data(), buffer.size());
    std::cout << "32-bit hash: 0x" << std::hex << hash_result << std::dec << std::endl;

    return 0;
}