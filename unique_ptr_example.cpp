#include <iostream>
#include <memory>

void noMemoryLeak() {
    while (true) {
        std::unique_ptr<int[]> safe(new int[1000]);
        // автоматическое освобождение памяти
    }
}

class FileManager {
    std::unique_ptr<FILE, decltype(&fclose)> file;
public:
    FileManager(const char* filename)
        : file(fopen(filename, "r"), &fclose) {
        if (!file) throw std::runtime_error("Failed to open file");
    }
    void read() {
        char buffer[256];
        if (fgets(buffer, sizeof(buffer), file.get())) {
            std::cout << buffer;
        }
    }
};

int main() {
    // noMemoryLeak();
    FileManager fm("main.cpp"); // пример файла
    fm.read();
    return 0;
}
