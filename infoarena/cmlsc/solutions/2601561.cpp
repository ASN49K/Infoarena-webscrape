#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream in_file {"cmlsc.in"};
    std::ofstream out_file {"cmlsc.out"};
    if(!in_file || !out_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    int M, N, Q;
    std::vector<int> v;
    std::vector<int> v1;
    in_file >> M >> N;
    for (int i = 0; i < M; ++i) {
        in_file >> Q;
        v.push_back(Q);
    }
    for (int i = 0; i < N; ++i) {
        in_file >> Q;
        v1.push_back(Q);
    }
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = 0; j < v1.size(); ++j) {
            if(v.at(i) == v1.at(j))
                std::cout << v.at(i) << " ";
                std::cout.flush();
        }
    }
    return 0;
}