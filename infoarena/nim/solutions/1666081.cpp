#include <fstream>
using namespace std;

ofstream fout ("nim.out");
ifstream fin  ("nim.in");
int n,t,suma,aux;
int main()
{
   fin>>t;
   for(int i = 1 ; i <= t ; i++)
   {
       fin>>n;
       int suma = 0;
       for(int j = 1 ; j <= n ; j++)
       {
           fin>>aux;
           suma ^= aux ;
       }
       if(suma) fout<<"DA\n";
       else fout<<"NU\n";
   }
}
