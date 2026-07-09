#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
struct citire{
int a, b;
inline void read(){
fin>>a>>b;
}
}v[10000];
int GCD(int a, int b){
if(!b) return a;
return GCD(b, a%b);
}


int main()
{   int n, i;
    fin>>n;
    for(i=1;i<=n;i++) v[i].read(),
        fout<<GCD(v[i].a, v[i].b)<<"\n";

    return 0;
}
