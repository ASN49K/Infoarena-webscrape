#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
void Euclid(int *a,int *b)
{
    while(*a!=*b)
        if(*a>=*b)
            *a-=*b;
        else
            *b-=*a;
}
void citire()
{
    int n,a,b;
    f >> n;
    for(int i=1;i<=n;i++)
    {
        f >> a >> b;
        Euclid(&a,&b);
        g << b << "\n";
    }

}

int main()
{
    citire();
    return 0;
}
