#include <bits/stdc++.h>
using namespace std;

ifstream f("euclid2.in");
ofstream o("euclid2.out");
int a,b,n;

void gcd(int a, int b){
    int aux=0;
    while(b!=0){
    aux = b;
    b = a%b;
    a = aux;
    }
    o<<a<<"\n";
}
int main()
{
    f>>n;
    for(int i=1;i<=n;i++){
        f>>a>>b;
        gcd(a,b);
    }
    return 0;
}
