#include <iostream>
#include <fstream>
using namespace std;

int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,a,b,r;
f>>n;
do
{   f>>a; f>>b;
    do
    {   r=a%b;
        a=b;
        b=r;
    }while(b);
g<<a<<"\n";
n--;
}while(n);
}
