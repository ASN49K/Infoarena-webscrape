#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int a,int b){if(!b) return a;else return euclid(b,a%b);}
int n,a,b;
int main(){
 f>>n;
 for(int i=0; i<n; i++){f>>a>>b;g<<euclid(a, b)<<'\n';}
}