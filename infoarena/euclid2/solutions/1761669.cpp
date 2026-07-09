#include <fstream>

int gcd(int a, int b)
{
    int tmp;
    while (b != 0) {
        tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}

int main()
{
    std::ifstream inputStream("euclid2.in");
    std::ofstream outputStream("euclid2.out");
    int nTests;
    inputStream >> nTests;
    for(int i = 0; i < nTests; ++i) {
        int a, b;
        inputStream >> a >> b;
        outputStream << gcd(a, b) << '\n';
    }
    return 0;
}
