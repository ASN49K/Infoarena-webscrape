#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
   int r;
   while(b!=0)
   {
       r = a%b;
       a = b;
       b = r;
   }
   return a;
}
int main()
{
    int a, b, n, i;
    ifstream fin ("euclid.in");
    ofstream fout ("euclid.out");
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
