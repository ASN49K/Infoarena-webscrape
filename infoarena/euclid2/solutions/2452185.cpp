#include <iostream>
#include <fstream>

using namespace std;

ifstream fin  ("euclid2.in");
ofstream fout ("euclid2.out");

long long a, b, r, test

int main (){

      fin>>test;
      for(int t=1; t<=test; t++){
            fin>>a;
            fin>>b;


            if(a < b)
                  swap(a, b);
            while(b != 0){
                  r=a%b;
                  a=b;
                  b=r;
            }


            fout<<a<<"\n";
      }

      return 0;
}
