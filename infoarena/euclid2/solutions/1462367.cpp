#include <fstream>
using namespace std;

int main()
{
 int n;
 ifstream fin("euclid2.in");
 ofstream fout("euclid2.out");
 fin>>n;
 for(int i=1;i<=n;i++)
 {
     int x,y;
     fin>>x>>y;
     while(x!=y)
     {
         if(x>y)x=x-y;
         else y=y-x;
     }
     fout<<x<<'\n';
 }
 fin.close();
 fout.close();
}
