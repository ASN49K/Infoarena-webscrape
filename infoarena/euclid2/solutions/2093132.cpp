#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned long int cmmdc(int a, int b)
{
    while (b) {
        int aux = b;
        b = a % b;
        a = aux;
    }

    return a;
}
unsigned long int n,a,b,r,i;
int main()
{
    f>>n;
    for(i=0; i<n; i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
    }
    f.close();
    g.close();
    return 0;
}
