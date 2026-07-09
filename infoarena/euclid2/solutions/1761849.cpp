#include <fstream>

int gcd(int a, int b)
{
    int tmp;
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main()
{
    std::ifstream input("euclid2.in");
    std::ofstream output("euclid2.out");
    int n_tests;

    input >> n_tests;
    for (int i = 0; i < n_tests; ++i) {
        int a, b;
        input >> a >> b;
        output << gcd(a, b) << '\n';
    }

}
