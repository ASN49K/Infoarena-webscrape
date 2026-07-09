#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

long long a,b;
long long cmm(long long i, long long j){
    if(j!=0) cmm(j,i%j);
    else return i;
}

int main()
{     int t;
        in>>t;
        for(int i=0;i<t;i++){
      in>>a>>b;
      out<<cmm(a,b)<<'\n';
        }
}

