#include <iostream>
#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(unsigned long int a, unsigned long int b)
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
    unsigned long int a,b;

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
