#include <iostream>
#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int t,n,x,s;
void rez()
{
    f>>t;
    for(int j=1;j<=t;j++)
       {f>>n;
       s=0;
       for(int i=1;i<=n;i++)
       {f>>x;
           s=s^x;
       }
       if(s)g<<"DA";
       else g<<"NU";
       g<<'\n';
    }
}
int main()
{

    rez();
}
