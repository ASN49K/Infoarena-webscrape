#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{int a,b,t,c;
fin>>t;
    for(t;t;t--)
    {


fin>>a>>b;
if(a==b) fout<<a<<endl;
else
  {while(b)
{
    c=a%b;
    a=b;
    b=c;
}
    fout<<a<<endl;}
    }
    fin.close();
    fout.close();
    return 0;
}
