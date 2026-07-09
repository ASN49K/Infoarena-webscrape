#include <fstream>

using namespace std;
inline int Cmmdc(int a,int b)
{
    int r;
    while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
    return a;
}

int main()
{
   int t,a,b,i,r;
   ifstream fin("euclid2.in");
   ofstream fout("euclid2.out");
   fin>>t;
   for(i=1;i<=t;i++)
   {
       fin>>a>>b;
        fout<<Cmmdc(a,b)<<"\n";
   }
   fin.close();
   fout.close();

     return 0;
}

