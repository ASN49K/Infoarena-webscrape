#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t;
long a,b;
int cmmdc(long  a,long b)
{
   if(a%b==0)
        return b;
   return cmmdc(b,a%b);
}
int main()
{
    fin>>t;
    for(int i=0;i<t;i++)
    {

        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }

    fin.close();
    fout.close();
    return 0;
}
