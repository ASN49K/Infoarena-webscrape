#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid.in");
ofstream out("euclid.out");

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
    int t;
    in>>t;
    for(int i=1;i<=t;i++)
    {
    int a,b;
    in>>a>>b;
    int cmmmdc = euclid(a,b);
    out<<cmmmdc<<'\n';
    }
}
