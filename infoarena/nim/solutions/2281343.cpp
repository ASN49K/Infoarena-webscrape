#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   ifstream fin("nim.in");
   ofstream fout("nim.out");
   int i,suma=0,nr,t,j,n;
   cin>>t;
   for(i=1;i<=t;i++)
   {
       suma=0;
       cin>>n;
       for(j=1;j<=n;j++)
       {
           cin>>nr;
           suma=suma^nr;
       }
       if(suma!=0)
        {
            cout<<"DA"<<endl;
        }
        else
        {
            cout<<"NU"<<endl;
        }
   }
   fin.close();
   fout.close();
   return 0;
}