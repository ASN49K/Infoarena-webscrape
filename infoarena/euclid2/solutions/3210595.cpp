#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

ifstream fin("operatii.in");
ofstream fout("operatii.out");

int cmmdc(int a,int b)
{
   while(b)
   {
      int r = a % b;
      a = b;
      b = r;
   }

   return a;
}

int main() {
  int n,a,b,i;
  fin >> n;

  for(i = 1; i <= n; i ++)
   {
      fin >> a >> b;
      fout << cmmdc(a,b) << '\n';
   }

   return 0 ; 
 }