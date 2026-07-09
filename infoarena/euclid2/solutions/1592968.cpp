#include <stdio.h>
#include <iostream>
#include <fstream>
int T, A, B;
using namespace std;
int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main(void)
{
    in>>T;
    for (; T; --T)
    {
        in>>A>>B;
        out<<gcd(A,B);
        out<<endl;
    }

    return 0;
}
