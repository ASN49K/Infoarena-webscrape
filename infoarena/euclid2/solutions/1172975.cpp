#include <fstream>

using namespace std;
int n,i,j,s=-1;
bool v[2000005];
ifstream fin("ciur.in");
ofstream fout("ciur.out");
int main()
{
   fin>>n;
   v[0]=0;v[1]=0;v[2]=0;j=2;
   while(j<=n)
   {
       while(v[j]!=0)
        j++;
       v[j]=1;
       s++;
       i=2*j;
       while(i<=n)
       {
           v[i]=1;
           i+=j;
       }
   }
 fout<<s;
    return 0;
}
