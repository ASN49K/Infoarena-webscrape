#include <iostream>
#include <fstream>

using namespace std;

int main()
     {
          ifstream fin;
          fin.open("euclid2.in");
          ofstream fout;
          fout.open("euclid.out");
         int T;
         int a, b, rest;
         fin >> T;
         for(int i; i <= T; i++)
           {

               fin >> a >>b;
               while(b)
           {
            rest = a%b;
            a = b;
            b = rest;
           }
           }
            fout << a;
            fin.close();
            fout.close();

         return 0;
     }
