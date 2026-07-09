#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
   long int a = 0, b = 1, t = 0, r = 0, i = 0;
   fin >> t;
   for(i = 0; i < t; i++)
   {
       fin >> a >> b;
       while(b != 0)
       {
           r = a % b;
           a = b;
           b = r;
       }
       fout<<a<<endl;
   }
   
   return 0;
}