#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int gcd(int a,int b){
if(!b)return a;
return gcd(b,a%b);
}

int main(){
int n;
in >> n;
for(int i=0;i<n;i++){
    int a,b;
    in >> a >> b;
    out << gcd(a,b) << endl;
}
}
