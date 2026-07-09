#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b)
{
    int nr=1;
    if(b>a)
    {
        int aux = a;
        a=b;
        b=aux;
    }
    for(int i=2; i<=a/2; i++)
        while(a%i==0 && b%i==0)
        {
            a /= i;
            b /= i;
            nr *= i;
        }
    return nr;
}
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int n,x,y;
    in>>n;

    for(int i=0; i<n; i++)
    {
        in>>x>>y;
        out<<cmmdc(x,y)<<'\n';
    }
    return 0;
}
