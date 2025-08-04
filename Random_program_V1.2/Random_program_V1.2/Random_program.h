#ifndef Random_program_H
#define Random_program_H


int random_Int(int min, int max);

float random_Float(float min, float max);

double random_Double(double min, double max);

char random_Char();

bool random_Bool();

std::string create_array(int index);
std::string create_bitset(int index);
std::string create_deque(int index);
std::string create_list(int index);
std::string create_map(int index);
std::string create_multimap(int index);
std::string create_queue(int index);
std::string create_set(int index);
std::string create_stack(int index);
std::string create_unoredered_map(int index);
std::string create_unordered_set(int index);
std::string create_vec(int index);

#endif