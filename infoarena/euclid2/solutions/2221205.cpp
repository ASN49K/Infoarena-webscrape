#include <iostream>
#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(long long unsigned a, long long unsigned b)
{
    while(a!=b)
    {
        if(a>b)
            a = a - b;
        else
            b = b - a;
    }

    return a;
}

int main()
{
    long T;
    long long unsigned a,b;

    in >> T;
    for(int i=0; i<T; i++)
    {
        in >> a >> b;
        out << cmmdc(a,b) << endl;
    }

    return 0;
}
