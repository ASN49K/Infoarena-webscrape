#include <fstream>
using namespace std;
int cmmdc(int a,int b)
{
    if(b==0) return a;
    else return cmmdc(b,a%b);
}
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

     fout<<cmmdc(x,y)<<'\n';
 }
 fin.close();
 fout.close();
}
