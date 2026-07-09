#include <fstream>

int greatestCommonDivisor(int a, int b) {
    
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
   
    return a;
}

int main()
{
    int numPairs{};

    std::ifstream inFile{ "euclid2.in" };
    std::ofstream outFile{ "euclid2.out" };

    if (!outFile || !inFile) {
        return -1;
    }

    inFile >> numPairs;

    for (int x1, x2; inFile >> x1 >> x2;) {
        outFile << greatestCommonDivisor(x1, x2) << '\n';
    }

    return 0;
}
