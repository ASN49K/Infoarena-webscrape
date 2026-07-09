#include <iostream>
#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int gcd(long long int a, long long int b)
{
    int c;
    while(b)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int main()
{
    long T;
    long long int a,b;

    in >> T;
    for(long long int i=0; i<T; i++)
    {
        in >> a >> b;

        out << gcd(a,b) << endl;
    }

    return 0;
}
