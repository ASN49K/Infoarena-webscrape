#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int cmmdc (int a, int b)
{
   if(b==0)
    return a;
   return cmmdc(b,a%b);
}
int n,i;
int x,y;
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>x>>y;
        fout<<cmmdc(x,y)<<endl;
    }
    return 0;
}
