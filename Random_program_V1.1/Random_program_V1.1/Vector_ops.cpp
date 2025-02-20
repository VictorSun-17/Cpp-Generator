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
#include "Vector_ops.h"

// Function to generate a random integer within a range
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

std::string random_vec_op(int n) {
    std::string op;
    int operation_numbers = randomInt(30, 100);
    int current = 0;
    int current_2 = 0;

    for (int m = 1; m <= operation_numbers; m++) {
        current = randomInt(1, n);
        current_2 = randomInt(1, n);
        switch (randomInt(1, 34)) {
        case 1:
            op += "vec_" + std::to_string(current) + ".push_back(" + std::to_string(randomInt(1, 100)) + "); \n";//Adds an element to the end of the vector.
            break;
        case 2:
            op += "vec_" + std::to_string(current) + ".insert(" + "vec_" + std::to_string(current) + ".begin() + 1," + std::to_string(randomInt(1, 100)) + "); \n"; //insert at certain place
            break;
        case 3:
            op += "vec_" + std::to_string(current) + ".erase(" + "vec_" + std::to_string(current) + ".begin() + " + std::to_string(randomInt(1, 100)) + "); \n"; //
            break;
        case 4:
            op += "vec_" + std::to_string(current) + ".pop_back();\n";
            break;
        case 5:
            op += "vec_" + std::to_string(current) + ".resize(" + std::to_string(randomInt(5, 20)) + ");\n";
            break;
        case 6:
            op += "std::reverse(vec_" + std::to_string(current) + ".begin(), vec_" + std::to_string(current) + ".end());\n";
            break;
        case 7:
            op += "std::sort(vec_" + std::to_string(current) + ".begin(), vec_" + std::to_string(current) + ".end());\n";
            break;
        case 8:
            op += "vec_" + std::to_string(current) + ".clear();\n";
            break;
        case 9:
            op += "vec_" + std::to_string(current) + ".assign(" + std::to_string(randomInt(3, 7)) +
                ", " + std::to_string(randomInt(1, 50)) + ");\n"; // Assign a new set of values
            break;
        case 10:
            op += "vec_" + std::to_string(current) + ".shrink_to_fit();\n"; // Reduce capacity to fit size
            break;
        case 11:
            op += "vec_" + std::to_string(current) + ".swap(vec_" + std::to_string(randomInt(1, n)) + ");\n"; // Swap two vectors
            break;
        case 12:
            op += "vec_" + std::to_string(current) + ".emplace_back(" + std::to_string(randomInt(1, 100)) + ");\n"; // Efficient push_back
            break;
        case 13:
            op += "vec_" + std::to_string(current) + ".capacity();\n"; // Print capacity
            break;
        case 14:
            op += "vec_" + std::to_string(current) + ".size();\n"; //Returns the number of elements in the vector.
            break;
        case 15:
            op += "vec_" + std::to_string(current) + ".max_size();\n"; //Returns the maximum number of elements that the vector can hold.
            break;
        case 16:
            op += "vec_" + std::to_string(current) + ".empty();\n"; //Checks if the vector is empty.
            break;
        case 17:
            op += "vec_" + std::to_string(current) + ".at(" + std::to_string(randomInt(1, 100)) + "); \n"; //Accesses the element at a specific position, with bounds checking.
            break;
        case 18:
            op += "vec_" + std::to_string(current) + ".front();\n"; //Accesses the first element of the vector
            break;
        case 19:
            op += "vec_" + std::to_string(current) + ".back();\n"; //Accesses the last element of the vector
            break;
        case 20:
            op += "vec_" + std::to_string(current) + ".begin();\n"; //Returns an iterator pointing to the first element of the vector
            break;
        case 21:
            op += "vec_" + std::to_string(current) + ".end();\n"; // Returns an iterator pointing to the past-the-end element of the vector
            break;
        case 22:
            op += "vec_" + std::to_string(current) + ".rbegin();\n"; //Returns a reverse iterator pointing to the last element of the vector
            break;
        case 23:
            op += "vec_" + std::to_string(current) + ".rend();\n"; // Returns a reverse iterator pointing to the element preceding the first element of the vector
            break;
        case 24:
            op += "vec_" + std::to_string(current) + ".cbegin();\n"; //Returns const_iterator to beginning
            break;
        case 25:
            op += "vec_" + std::to_string(current) + ".cend();\n"; // Returns const_iterator to end
            break;
        case 26:
            op +=  "vec_" + std::to_string(current) + ".crbegin();\n"; //Returns const_reverse_iterator to reverse beginning
            break;
        case 27:
            op += "vec_" + std::to_string(current) + ".crend();\n"; // Returns const_reverse_iterator to reverse end
            break;
        case 28:
            op += "vec_" + std::to_string(current) + ".swap(" + std::to_string(current_2) + "); \n"; // Swaps the contents of the vector with those of another vector.
            break;

        case 29:
            op += "vec_" + std::to_string(current) + ".clear();\n"; // Removes all elements from the vector.
            break;
        case 30:
            op += "vec_" + std::to_string(current) + ".emplace("+ "vec_" + std::to_string(current) + ".begin() + " + std::to_string(randomInt(1, 100)) +","+ std::to_string(randomInt(1, 100)) + "); \n"; // Constructs and inserts an element in the vector.
            break;
        case 31:
            op += "vec_" + std::to_string(current) + ".assign(" + std::to_string(randomInt(1, 100)) + "," + std::to_string(randomInt(1, 100)) + ");\n"; // Assigns new values to the vector elements by replacing old ones.
            break;
        case 32:
            op += "vec_" + std::to_string(current) + ".reserve("+ std::to_string(randomInt(1, 10000)) +"); \n"; // Requests that the vector capacity be at least enough to contain a specified number of elements.
            break;
        case 33:
            op += "vec_" + std::to_string(current) + ".shrink_to_fit();\n"; // Reduces memory usage by freeing unused space.
            break;
        case 34:
            op += "using ElementType = decltype(vec_" + std::to_string(current) + ")::value_type;\n";
            op += "const char* type = typeid(ElementType).name();\n";
            op += "std::string current_type = std::string(type);\n";
            break;



        }

    }




    return op;
}