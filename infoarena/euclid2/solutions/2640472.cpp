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
{ int x,y,n;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>n;
cin>>n;
for(int i=1;i<=n;i++)
{
    f>>x>>y;
    cin>>x>>y;
    g<<cmmdc(x,y);
    cout<<cmmdc(x,y);
}
cin.get();




    return 0;
}
