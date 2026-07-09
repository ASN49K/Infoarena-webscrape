#include<iostream>
#include<fstream>
using namespace std;

int cmmdc(int a,int b)
{if(a==b) return a;
if(a>b) return cmmdc(a-b,b);
else if(a<b) return cmmdc(a,b-a);
}


int main()
{int t,a,b,i,c;
ifstream f("euclid.txt");
ofstream g("euclid.out");
f>>t;
for(i=1; i<=t; i++)
{f>>a;
f>>b;

c=cmmdc(a,b);

cout<<c<<"\n";
}
system("pause");
return 0;

}



