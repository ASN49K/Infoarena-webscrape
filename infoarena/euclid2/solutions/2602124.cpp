#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}

int main(){

   int n,t,x,y;
   in>>t;
   while(t--){
        in>>x>>y;
        out<<gcd(x,y)<<"\n";
   }
   return 0;
}


