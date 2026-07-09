#include <iostream>
#include <fstream>
using namespace std;

ifstream infile("euclid2.in");
ofstream infile2("euclid2.out");

int main()
{

   int x;
   int nr1,nr2,rest;
   infile >> x;
   for(int i =1; i<=x ; i++){
    infile >> nr1 >> nr2;
    while(nr2!=0){
         rest = nr1 % nr2;
         nr1=nr2;
         nr2=rest;
    }
    infile2 << nr1 << "\n";
}

    return 0;
}
