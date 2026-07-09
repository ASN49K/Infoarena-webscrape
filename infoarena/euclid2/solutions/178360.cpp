#include<iostream.h>
#include<stdio.h>
using namespace std;
int main ()
{int a, b, cmmdc, i, t;
freopen ("euclid2.in", "r", stdin);
freopen ("euclid2.out", "w", stdout);
cin>>t;
for (i=1; i<=t; i++) {cin>>a>>b;
while (a!=b)
if (a>b) a=a-b;
else b=b-a;
cmmdc=a;
cout<<a<<'\n';}
return 0;}