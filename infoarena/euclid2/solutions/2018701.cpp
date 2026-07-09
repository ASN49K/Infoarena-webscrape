#include<iostream>
#include<fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t, x, y, i, r;

int main(){

         fin>>t;

         for( i=1; i<=t; i++){
                  fin>>x>>y;
                  while( y != 0){
                           r=x%y;
                           x=y;
                           y=r;
                  }
                  fout<<x<<'\n';
         }
return 0;
}
