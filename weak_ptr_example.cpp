#include <iostream>
#include <memory>

class Observer {
public:
    void observe(std::weak_ptr<int> wp) {
        if (auto sp = wp.lock()) { // Преобразуем weak_ptr в shared_ptr
            std::cout << "Observed value: " << *sp << "\n";
        } else { //если не существует, то выбрасывает nullptr
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
