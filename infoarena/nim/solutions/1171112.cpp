#include<iostream>
#include<fstream>
using namespace std;
int main()
{ifstream f("nim.in");
ofstream g("nim.out");
int t,x,a,i,j,n;
f>>t;
for(i=1;i<=t;i++)
{f>>n;
x=0;
    for(j=1;j<=n;j++)
    {f>>a;
    x=x^a;

    }
if((x==0)||(x==1))
g<<"DA"<<'\n';
else
g<<"NU"<<'\n';
}

}
