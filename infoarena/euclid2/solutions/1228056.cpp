#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t,x,y;

int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b, a % b);
}


int main(){
    f>>t;
    for(int i=1;i<=t;++i){
        f>>x>>y;
        g<<gcd(x,y)<<'\n';
    }
    f.close();g.close();
    return 1 ;
}
