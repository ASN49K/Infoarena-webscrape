#include <bits/stdc++.h>

std::ifstream InFile("euclid2.in");
std::ofstream OutFile("euclid2.out");

int Q;

int GCD(int a, int b) {
    if(!b) return a;
    return GCD(b, a%b);
}

void Citire() {
    InFile >> Q;
}

void Rezolvare() {
    int a, b;
    while(Q--)
        InFile >> a >> b,
        OutFile << GCD(a, b) << '\n';
}

int main()
{
    Citire();
    Rezolvare();

    return 0;
}
