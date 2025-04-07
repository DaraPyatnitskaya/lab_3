#include <iostream>
#include <memory>
#include <vector>

class Data {
public:
    int value;
    Data(int v) : value(v) {
        std::cout << "Data created\n";
    }
    ~Data() {
        std::cout << "Data destroyed\n";
    }
};

void sharedOwnership() {
    std::shared_ptr<Data> shared = std::make_shared<Data>(42);
    std::vector<std::shared_ptr<Data>> vec;
    vec.push_back(shared);
    vec.push_back(shared); // несколько владельцев
    std::cout << "Use count: " << shared.use_count() << "\n";
}

int main() {
    sharedOwnership();
    return 0;
}
