#include <fstream>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int t,n,x,sum;
int main()
{int i,j;
   fin>>t;
   for(i=1;i<=t;i++)
   {
       fin>>n;
       fin>>sum;
       for(j=2;j<=n;j++)
       {
           fin>>x;
           sum=sum^x;
       }
       if(sum>0)
        fout<<"DA"<<'\n';
       else
        fout<<"NU"<<'\n';
   }

}
