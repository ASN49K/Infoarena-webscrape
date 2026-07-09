#include <bits/stdc++.h>

#define FILENAME    std::string("euclid2")
std::ifstream input (FILENAME+".in");
std::ofstream output(FILENAME+".out");

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
    int T;  input >> T;
    int a, b;
    while (T--) input >> a >> b, output << gcd(a, b) << '\n';

    return 0;
}
