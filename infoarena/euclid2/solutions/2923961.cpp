#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(long long int a, long long int b)
{
   while(true)
   {
      if(a==0) return b;
      if(b%a==0) return a;
      b%=a;
      if(b==0) return a;
      if(a%b==0) return b;
      a%=b;
   }
}


int main()
{
    int t,a,b;
    fin>>t;
    for(int i=0;i<t;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a, b)<<'\n';
    }
}
