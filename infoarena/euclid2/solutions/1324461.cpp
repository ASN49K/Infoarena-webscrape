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
{int a,b,n;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
fin>>n;
while(n--)
{fin>>a>>b;
fout<<euclid(a,b)<<'\n';}
fin.close();
fout.close();
return 0;
}
