#include<iostream>
#include<fstream>

using namespace std;
int a,b,n,i;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        while(a!=b)
            if(a>b)a=a-b;
        else b-=a;
        g<<a<<"\n";
    }
}
