#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int n;
long a,b;
int main()
{
   int i;
   fin>>n;
   for (i=1;i<=n;i++)
   {
       fin>>a>>b;
       while (a!=b)
        if (a>b) a-=b;
          else b-=a;
       fout<<a<<'\n';
   }
   return 0;
}
