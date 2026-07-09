#include<iostream>
#include<fstream>
using namespace std;
int main()
{int a,b,t,r,i;
ifstream f("euclid2.int");
ofstream g("euclid2.out");
f>>t;
for(i=1;i<=t;i++)
{f>>a>>b;
while(a%b!=0)
{r=a%b;
a=b;
b=r;
}
g<<b<<endl;
}

}
