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
if((a==1)||(b==1))
g<<1;
else
{while(a%b!=0)
{r=a%b;
a=b;
b=r;

}
    g<<b<<endl;
}
}
f.close();
g.close();
}
