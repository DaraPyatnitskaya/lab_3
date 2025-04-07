#include <iostream>

void memoryLeak() {
    while (true) {
        int* leak = new int[1000];  // память не освобождается
        // delete[] leak
    }
}

int main() {
    memoryLeak();
    return 0;
}
