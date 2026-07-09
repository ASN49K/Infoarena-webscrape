#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout ("euclid2.out");
int a,b, x, y,n,i,r;
int main()
{
   fin>>n;
   for(i=1;i<=n;i++)
   {
       fin>>x>>y;
       a=x;
       b=y;
       while(b!=0)
       {
           r=a%b;
           a=b;
           b=r;
       }
   fout<<a<<"\n";
   }

    return 0;
}
