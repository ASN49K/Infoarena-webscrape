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
};
int GCD(int a, int b){
if(!b) return a;
return GCD(b, a%b);
}


int main()
{   int n;
    fin>>n;
    for(;n;n--){citire n; n.read(),
        fout<<GCD(n.a, n.b)<<"\n";}

    return 0;
}
