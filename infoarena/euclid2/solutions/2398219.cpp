#include<iostream>
#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int euclid(int a,int b)
{
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;

    }
    return a;
}
int main()
{
    int n,f,p;
    in>>n;
    for(int i=0; i<n; i++)
    {
        in>>f>>p;
        out<<euclid(f,p)<<'\n';
    }
}
