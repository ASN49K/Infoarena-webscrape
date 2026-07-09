#include <iostream>
#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(long long int a, long long int b)
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
    long long int a,b;

    in >> T;
    for(int i=0; i<T; i++)
    {
        in >> a >> b;

        if(a == b)
            out << a;
        else
            out << cmmdc(a,b) << endl;
    }

    return 0;
}
