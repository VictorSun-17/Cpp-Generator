#include <iostream>
#include <vector>
#include <memory>

class MyClass {
public:
    MyClass(int v) : value(v) {}
    int value;
};

int main() {
    std::vector<std::shared_ptr<MyClass>> vec;

    vec.push_back(std::make_shared<MyClass>(1));
    vec.push_back(std::make_shared<MyClass>(2));
    vec.push_back(std::make_shared<MyClass>(3));

    for (const auto& ptr : vec) {
        std::cout << ptr->value << std::endl;
    }

    // 不需要手动释放内存，智能指针会自动清理
    return 0;
}