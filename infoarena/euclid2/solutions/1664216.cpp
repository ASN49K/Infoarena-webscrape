#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int a,b,n,i,t;
    f>>n;
    for(i=1; i<=n; i++)
    {
        f>>a;
        f>>b;
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
        out<<a<<'\n';



    }
    return 0;
}
