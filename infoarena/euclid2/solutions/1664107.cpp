#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int a,b,n,i;
    f>>n;
    for(i=1; i<=n; i++)
    {
        f>>a;
        f>>b;
        if(a == 0)
            return b;
        while(b != 0)
        {
            if(a > b) a -= b;
            else b -= a;
        }
        out<<a<<endl;



    }
    return 0;
}
