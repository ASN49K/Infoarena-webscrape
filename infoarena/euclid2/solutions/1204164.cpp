#include<iostream>
#include<fstream>
using namespace std;
int main()
{ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,i,a,b,r;
f>>t;
for(i=1;i<=t;i++)
{f>>a>>b;
while(a%b!=0)
{r=a%b;
a=b;
b=r;

}
    g<<b<<'/n';
}

}
