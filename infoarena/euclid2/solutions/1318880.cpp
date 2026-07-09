#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main ()
{
    int t,i,a,b,r,x,y;
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a>>b;

         x=a;
         y=b;
         while (y!=0)
         {
         r=x%y;
         x=y;
         y=r;
         }
         fout<<x<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
