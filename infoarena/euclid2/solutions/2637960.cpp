#include <iostream>
 #include <fstream>

using namespace std;

int main()
{
     ifstream intrare("euclid2.in");
     ofstream iesire("euclid2.out");

     int i, A, B, swapp;
     intrare >> i;
     while(i != 0){
          intrare >> A >> B;
          if(A < B){
               swapp = A;
               A = B;
               B = swapp;
          }

          if(A % B == 0)
               iesire << B;
          else if(A % B != 0)
               iesire << A % B;
          iesire << endl;

          i--;
     }


     return 0;
}
