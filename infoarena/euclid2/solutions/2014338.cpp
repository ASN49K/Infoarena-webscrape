#include<iostream>
#include <cstdio>
#include<fstream>
using namespace std;


int main()
{
int i,T;
long long x,y,r;
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%d",&T);
for(i=1;i<=T;i++)
{scanf("%d %d",&x,&y);
while(y)
{
r = x % y;
x = y;
y = r;
}
printf("%d\n",x);

}
}
