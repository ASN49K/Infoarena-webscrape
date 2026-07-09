#include<iostream>
#include<fstream>
using namespace std;
int euclid(int a,int b)
{int c;
while(b)
{c=a%b;
a=b;
b=c;
}
return a;
}
int main()
{int a,b,c,n;
ifstream fin("euclid.in");
ofstream fout("euclid.out");
fin>>n;
while(n--)
{fin>>a;
fin>>b;
fout<<euclid(a,b)<<endl;}
fin.close();
fout.close();
return 0;
}
