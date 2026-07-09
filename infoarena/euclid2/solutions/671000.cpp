#include<fstream>
using namespace std;

int euclid(int a, int b){
if(!b) return a;
return euclid(b,a%b);
}

int main(){
int n,a,b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>n;
for(;n;--n)
f>>a;
f>>b;
g<<euclid(a,b)<<'\n';
return 0;
}

