#include <iostream>
#include <fstream>

int euclid(int a, int b) {
    while(b != 0) {
        int aux = a;
        a = b;
        b = aux%b;
    }
    return a;
}

int main() {
    // Open file
    std::fstream input;
    std::fstream output;
    int numberOf = 0;
    int aux, aux1 = 0;

    input.open("files/euclid2.in", std::fstream::in);
    output.open("files/euclid2.out", std::fstream::out);

    input >> numberOf;
    for (int i = 0; i < numberOf; i++) {
        input >> aux >> aux1;
        output << euclid(aux, aux1) << std::endl;
    }

    input.close();
    output.close();

    return 0;
}
