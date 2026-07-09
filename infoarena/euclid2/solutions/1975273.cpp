#include <fstream>
#include<iostream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int  T,a,b;
int euc(int a, int b)
{
   int r=0;
   while(b)
   {
       r=a%b;
       a=b;
       b=r;
   }
   return a;
}
int main()
{
    fin>>T;
    for(int i=1;i<=T;i++)
    {
        fin>>a>>b;
        fout<<euc(a,b);
        fout<<endl;
    }
    return 0;
}
