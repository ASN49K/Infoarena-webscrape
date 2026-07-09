#include<iostream>
#include<stdio.h>
using namespace std;

int cmmdc (int a, int b)
{
while(a!=0 && b!=0)	
{  if(a>b) a=a%b;
  else b=b%a;}

return a+b; 
}

int main()
{ int a,b,t,i;

freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);

cin>>t;

for(i=1;i<=t;i++)
{    cin>>a>>b;
     cout<<cmmdc(a,b);
     cout<<endl;
}



}
