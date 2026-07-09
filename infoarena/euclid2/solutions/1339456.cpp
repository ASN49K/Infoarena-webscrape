#include<iostream>
using namespace std;
int main ()
{int a,b;
do
{cin>>a>>b;}
while (a==b);
while (a!=b)
{if (a>b) a=a-b;
else b=b-a;}
cout<<a<<endl;
system ("pause");
}
