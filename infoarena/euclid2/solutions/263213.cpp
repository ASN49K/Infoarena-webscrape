#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

int gcd(int u, int v){
    if (v==0) return u;
    else return gcd(v,u%v);
}

int main(){
       ifstream f("euclid2.in");
       ofstream g("euclid2.out");
       int n, nr = 0;
       long u, v;
       f>>n;
       for (int i = 0;i<n;i++){ 
       f>>u>>v;
       g<<gcd(u,v)<<endl;
       }
       f.close();
       g.close();
       return 0;
       
}
