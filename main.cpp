#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main() {
    std::ifstream in_file{"../romeoandjuliet.txt"};
    std::ofstream out_file{"../romeoandjulietOut.txt"};

    if (!in_file) {
        std::cerr << "Error opening input file" << std::endl;
        std::exit(1);
    }
    if (!out_file) {
        std::cerr << "Error opening output file" << std::endl;
        std::exit(1);
    }

    std::string line{};
    int line_count{0};
    while (std::getline(in_file, line)) {
        if (line.empty()) {
            out_file << std::endl;
        } else {
            ++line_count;
            out_file << std::setw(10) << std::left << line_count << line << std::endl;
        }
    }

    std::cout << "File copied successfully" << std::endl;
    in_file.close();
    out_file.close();
    return 0;
}
