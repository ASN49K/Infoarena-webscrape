#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{int a,b,T,c;
fin>>T;
    for(T;T;--T)
    {
fin>>a>>b;
  while(b)
{
    c=a%b;
    a=b;
    b=c;
}
    fout<<a<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
