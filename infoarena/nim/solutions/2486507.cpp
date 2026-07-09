#include <fstream>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");
int main()
{
    int t,n,x,sum,l,i;
    in>>t;
    for(l=1;l<=t;l++)
    {
     sum=0;
     in>>n;
     for(i=1;i<=n;i++)
     {
      in>>x;
      sum^=x;
     }
     if(sum!=0)
        out<<"DA\n";
     else
        out<<"NU\n";
    }
    return 0;
}
