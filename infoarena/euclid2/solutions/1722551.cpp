#include<iostream>
#include<fstream>
using namespace std;

int cmmdc(int a, int b)
{
    int r;
    if(a < b)
    {
        r = a;
        a= b;
        b= r;
    }
    while(1)
    {
        r = a % b;
        if ( r == 0)
            break;
        a = b;
        b = r;
    }
    return b;
}

int main()
{

    ifstream f;
    f.open("euclid2.in");
    ofstream g;
    g.open("euclid2.out");
    int n, a, b, i,d;
    f >> n;
    for(i=0; i<n;i++)
    {
        f >> a>> b;
        d = cmmdc(a,b);
        g << d << "\n";
    }
}
