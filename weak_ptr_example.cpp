#include <iostream>
#include <memory>

class Observer {
public:
    void observe(std::weak_ptr<int> wp) {
        if (auto sp = wp.lock()) {
            std::cout << "Observed value: " << *sp << "\n";
        } else {
            std::cout << "Object no longer exists\n";
        }
    }
};

int main() {
    std::shared_ptr<int> sp = std::make_shared<int>(10);
    std::weak_ptr<int> wp = sp;

    Observer o;
    o.observe(wp);  // Должен увидеть значение

    sp.reset();  // Уничтожение объекта

    o.observe(wp);  // Больше не существует
    return 0;
}
