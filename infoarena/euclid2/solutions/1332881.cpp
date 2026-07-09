#include <iostream>
#include <fstream>


using namespace std;


int T, A, B;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main(void)
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    in>>T;
    for (; T; --T)
    {
        in>>A>>B;
        out<<(gcd(A,B))<<endl;
    }

    return 0;
}
