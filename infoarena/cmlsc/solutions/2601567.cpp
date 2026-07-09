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
    int M, N, Q, num{0};
    std::vector<int> A;
    std::vector<int> B;
    std::vector<int> v1;
    in_file >> M >> N;
    for (int i = 0; i < M; ++i) {
        in_file >> Q;
        A.push_back(Q);
    }
    for (int i = 0; i < N; ++i) {
        in_file >> Q;
        B.push_back(Q);
    }
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < B.size(); ++j) {
            if(A.at(i) == B.at(j) && j >= i) {
                v1.push_back(A.at(i));
                ++num;
                break;
            }
        }
    }
    
    std::cout << num << std::endl;
    std::cout.flush();
    for (auto v: v1) {
        std::cout << v << " ";
        std::cout.flush();
    }
    return 0;
}