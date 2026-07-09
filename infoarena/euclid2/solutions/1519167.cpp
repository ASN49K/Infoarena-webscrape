#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(long long a,long long b)
{
       long long r=a%b;
       while(r>0)
       {
              a=b;
              b=r;
              r=a%b;
       }
       return b;
}
int main()
{
       long long t,i,a,b;
       fin>>t;
       for(i=1;i<=t;i++)
       {
              fin>>a>>b;
              fout<<euclid(a,b)<<'\n';
       }
}
