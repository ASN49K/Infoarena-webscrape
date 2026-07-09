#include<iostream>
#include<fstream>
using namespace std;

/*int cmmdc(int a,int b)
{if(a==b) return a;
if(a>b) return cmmdc(a-b,b);
else if(a<b) return cmmdc(a,b-a);*/

long unsigned t,a,b,i,c;
int main()
{int t,a,b,i,c;
ifstream f("euclid.txt");
f>>t;
for(i=1; i<=t; i++)
f>>a;
f>>b;
while(b)
{c=a%b; a=b; b=c;}
cout<<a<<"\n";
system("pause");
return 0;

}



