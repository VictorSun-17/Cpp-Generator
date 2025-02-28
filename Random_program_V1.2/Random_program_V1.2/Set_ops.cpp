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
#include "Set_ops.h"

std::string random_set_op(int n) {
    std::string op;
    int operation_numbers = randomInt(30, 100);
    int current = 0;
    int current_2 = 0;
    for (int m = 1; m <= operation_numbers; m++) {
        current = randomInt(1, n);
        current_2 = randomInt(1, n);
        switch (randomInt(1, 34)) {
        case 1:
            op += "set_" + std::to_string(current) + ".begin(); \n";//An iterator to the first element in the container.
            break;
        case 2:
            op += "set_" + std::to_string(current) + ".cbegin(); \n";//A const_iterator to the beginning of the sequence.
            break;
        case 3:
            op += "set_" + std::to_string(current) + ".cend(); \n";//A const_iterator to the element past the end of the sequence.
            break;
        case 4:
            op += "set_" + std::to_string(current) + ".clear(); \n";//clean all
            break;
        case 5:
            op += "set_" + std::to_string(current) + ".count(" + std::to_string(randomInt(1, 100)) + "); \n";//A const_iterator to the element past the end of the sequence.
            break;
        case 6:
            op += "set_" + std::to_string(current) + ".crbegin(); \n";//A const_reverse_iterator to the reverse beginning of the sequence.
            break;
        case 7:
            op += "set_" + std::to_string(current) + ".crend(); \n";//A const_reverse_iterator to the reverse end of the sequence.
            break;
        case 8:
            //TODO:need optimization
            op += "set_" + std::to_string(current) + ".emplace(" + std::to_string(randomInt(1, 100)) + "); \n";
            // If the function successfully inserts the element(because no equivalent element existed already in the set), 
            // the function returns a pair of an iterator to the newly inserted element and a value of true.
            break;
        case 9:
            //TODO: need optimization
            op += "set_" + std::to_string(current) + ".emplace_hint(set_" + std::to_string(current) + ".find(" + std::to_string(randomInt(1, 100)) + ")," + std::to_string(randomInt(1, 100)) + "); \n";
            break;
        case 10:
            op += "set_" + std::to_string(current) + ".empty(); \n";//true if the container size is 0, false otherwise.
            break;
        case 11:
            op += "set_" + std::to_string(current) + ".end(); \n";//An iterator to the past-the-end element in the container.
            break;
        case 12:
            op += "auto range = set_" + std::to_string(current) + ".equal_range(" + std::to_string(randomInt(1, 100)) + "); \n";
            //The function returns a pair, whose member pair::first is the lower bound of the range (the same as lower_bound), and pair::second is the upper bound (the same as upper_bound).
            break;
        case 13:
            op += "set_" + std::to_string(current) + ".erase(" + std::to_string(randomInt(1, 100)) + "); \n";//For the value-based version (2), the function returns the number of elements erased.
            break;
        case 14:
            op += "auto it = set_" + std::to_string(current) + ".find(" + std::to_string(randomInt(1, 100)) + ");\n"; //An iterator to the element, if val is found, or set::end otherwise.
            break;
        case 15:
            op += "auto alloc = set_" + std::to_string(current) + ".get_allocator();\n";//Member type allocator_type is the type of the allocator used by the container, defined in set as an alias of its third template parameter
            break;
        case 16:
            op += "set_" + std::to_string(current) + ".insert(" + std::to_string(randomInt(1, 100)) + "); \n";//For the value-based version (2), the function returns the number of elements erased.
            break;
        case 17:
            op += "auto mycomp = set_" + std::to_string(current) + ".key_comp();\n"; //The comparison object.
            break;
        case 18:
            op += "auto itlow = set_" + std::to_string(current) + ".lower_bound(" + std::to_string(randomInt(1, 100)) + ");\n";
            //Returns an iterator pointing to the first element in the container which is not considered to go before val (i.e., either it is equivalent or goes after).
            break;
        case 19:
            op += "set_" + std::to_string(current) + ".max_size();\n"; //The maximum number of elements a set container can hold as content.
            break;
        case 20:
            op += "set_" + std::to_string(current) + ".rbegin();\n"; //A reverse iterator to the reverse beginning of the sequence container.
            break;
        case 21:
            op += "set_" + std::to_string(current) + ".rend();\n"; //A reverse iterator to the reverse end of the sequence container.
            break;
        case 22:
            op += "set_" + std::to_string(current) + ".size();\n"; //The number of elements in the container.
            break;
        case 23:
            op += "set_" + std::to_string(current) + ".swap(set_" + std::to_string(current_2) + ");\n"; // Swap two vectors
            break;
        case 24:
            op += "auto itlow = set_" + std::to_string(current) + ".lower_bound(" + std::to_string(randomInt(1, 100)) + ");\n";
            //An iterator to the the first element in the container which is considered to go after val, or set::end if no elements are considered to go after val.
            break;
        case 25:
            op += "set_" + std::to_string(current) + ".value_comp();\n"; //The comparison object.
        }
    }


    return op;
}