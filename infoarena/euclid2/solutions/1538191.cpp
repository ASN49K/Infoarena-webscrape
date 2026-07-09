#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int main ()
{
    int a,b,i,d=0,j,n;
     fin >> n;
     for (j=1;j<=n;j++)
     {
         fin >> a >> b;
         for (i=1;i<=a && i<=b;i++)
         {
             if(a%i==0 && b%i==0)
             {
                 d=i;
             }
         }
         fout << d << endl;
     }
}
