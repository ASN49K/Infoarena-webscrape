#include<iostream>
#include<fstream>
#include<cstring>
#include<math.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int a,int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    g<<euclid(16,4);
}
