#include <iostream>
 #include <fstream>

using namespace std;
int euclidean(int a, int b){
     if(!b) return a;
     return euclidean(b, a%b);
}
int main()
{
     ifstream intrare("euclid2.in");
     ofstream iesire("euclid2.out");

     int i, A, B, swapp;
     intrare >> i;
     int s = 10;
     while(i--){
          intrare >> A >> B;
          iesire << euclidean(A, B) << "\n";
     }
     return 0;
}
