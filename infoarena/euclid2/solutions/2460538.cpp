#include <iostream>
#include <fstream>

using namespace std;

int main()
     {
          ifstream fin("euclid2.in");
          ofstream fout("euclid2.out");
         int T;
         fin >> T;
         int a, b, rest;
         for(int i = 1; i <= T; i++)
           {
               fin >> a >> b;
               while(b != 0)
           {
            rest = a % b;
            a = b;
            b = rest;
           }
            fout << a << "\n";
           }

            fin.close();
            fout.close();

         return 0;
     }
