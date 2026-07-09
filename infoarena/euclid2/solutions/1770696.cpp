#include <fstream>
#include <iostream>

int gcd(int a, int b)
{
    while (b != 0) {
        int tmp;
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main()
{
    std::ifstream inputStream("euclid2.in");
    std::ofstream outputStream("euclid2.out");
    int t;
    inputStream >> t;
    for(int i = 0; i < t; ++i) {
        int a, b;
        inputStream >> a >> b;
        outputStream << gcd(a, b) << '\n';
    }

    return 0;
}
