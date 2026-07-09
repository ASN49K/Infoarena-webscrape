#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream o("euclid2.out");
int gcd(int a, int b){
if(!b) return a;
if(!a) return b;
if(a<b) return gcd(a, b-a);
return gcd(a-b, b);
}
int main(){
int a, b;
f>>a;
while(f>>a){
f>>b;
o<<gcd(b, a)<<'\n';
}
}
