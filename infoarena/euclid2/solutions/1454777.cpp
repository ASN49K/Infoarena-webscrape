#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
long int cmmdc ( long int a , long int b )
{
    long int rest = 1 ;
    while ( rest != 0 )
    {
        rest = a % b ;
        a = b ;
        b = rest;
    }
  return a ;
}

long int T , x , y ;
void Rezolvare ()
{
    fin >> T ;
    while ( T >= 1 )
     {
         fin >> x >> y;
         fout << cmmdc (x,y) ;
         fout << "\n";
         --T ;
     }
}
int main()
{
    Rezolvare ();
    return 0;
}
