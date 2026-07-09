#include <fstream>
using namespace std;
int a,b,t,d,r,i;
int main ()
{  ifstream fin("euclid2.in");
   ofstream fout("euclid2.out");
   fin>>t;
   for(i=1;i<=t;i++)
     {
        fin>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<endl;
     }
    fout.close();
    fin.close();
 return 0;
}
