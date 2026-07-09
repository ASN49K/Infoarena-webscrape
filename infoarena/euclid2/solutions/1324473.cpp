#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
void Euclid(int *a,int *b,int *r)
{
    while(*b!=0)
        {
            *r=*a%*b;
            *a=*b;
            *b=*r;
        }
}
void citire()
{
    int n,a,b,r;
    f >> n;
    for(int i=1;i<=n;i++)
    {
        f >> a >> b;
        Euclid(&a,&b,&r);
        g << a << "\n";
    }

}

int main()
{
    citire();
    return 0;
}
