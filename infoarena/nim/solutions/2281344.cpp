#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   ifstream fin("nim.in");
   ofstream fout("nim.out");
   int i,suma=0,nr,t,j,n;
   fin>>t;
   for(i=1;i<=t;i++)
   {
       suma=0;
       fin>>n;
       for(j=1;j<=n;j++)
       {
           fin>>nr;
           suma=suma^nr;
       }
       if(suma!=0)
        {
            fout<<"DA"<<endl;
        }
        else
        {
            fout<<"NU"<<endl;
        }
   }
   fin.close();
   fout.close();
   return 0;
}