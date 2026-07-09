#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a,int b)
{
    if(b)
    if(a>b)
        return cmmdc(b,a%b);
    else
        return cmmdc(a,b%a);
}
int main()
{
   int a,b,T;
   fin>>T;
   for(int i=1;i<=T;i++)
   {
       fin>>a>>b;
       fout<<cmmdc(a,b)<<endl;
   }

   return 0;
}
