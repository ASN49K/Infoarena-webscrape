#include<iostream.h>
void main()
{
int n,m,rest;
cin>>n>>m;
while(m)
{rest=n%m;
n=m;
m=rest;}
cout<<n;}