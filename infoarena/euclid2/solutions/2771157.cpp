#include <iostream>
#include <fstream>

unsigned int euclid(unsigned int a, unsigned int b) {
    return (a == 0) ? b : euclid(b % a, a);
}
int main() {
    std::ifstream inFile;
    inFile.open("euclid2.in", std::ios::in);
    
    if (inFile.is_open()) {
        unsigned int numarDeLinii;
        inFile >> numarDeLinii;
        
        std::ofstream outFile;
        outFile.open("euclid2.out", std::ios::out);
        if (outFile.is_open()) {
            unsigned int a, b;
            for (size_t linie = 0; linie < numarDeLinii; linie++) {
                inFile >> a >> b;
                outFile << euclid(a, b) << std::endl;
            }
            outFile.close();
        }
        else std::cout << "Nu s-a putut scrie in fisier!" << std::endl;
        inFile.close();
    }
    else std::cout << "Nu am putut deschide fisierul!" << std::endl;
    return 0;
}