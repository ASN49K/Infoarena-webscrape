#include <iostream>
#include <fstream>

using namespace std;


int cmmdc(int a,int b)
{
    while(a!=b)//12 != 42  30
    {
        if(a>b)
        {
           a=a-b;
        }
        else
            b=b-a;
    }
    return a;
}


int main()
{ int a,b,T;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>T;
cin>>T;
for(int i=1;i<=n;i++)
{
    f>>a>>b;
    cin>>a>>b;
    g<<cmmdc(a,b);
    cout<<cmmdc(a,b);
}
g.close();





    return 0;
}
