#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    if(a==b) return a;
    else
        if(a>b) return cmmdc(a-b, b);
        else return cmmdc(a, b-a);
}

main()
{
    int x, y, n;
    fin>>n;
    while(n!=0)
    {
        fin>>x>>y;
        fout<<cmmdc(x, y);
        n--;
    }
}
