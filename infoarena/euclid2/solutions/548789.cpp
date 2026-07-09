#include <fstream>
using namespace std;

int gcd(int u, int v){
    if(u == v)
        return v;
    if(0==u)
        return v;
    if(0==v)
        return u;
    if(0==(u&1)){ // if u is even
        if(0==(v&1)) // if u and v are even
            return (gcd((u>>1), (v>>1))<<1);
        else // u is even and v is odd
            return  gcd(u>>1, v);
    }
    else if(0==(v&1)) // if u is odd and v is even
        return gcd(u, (v>>1));
    else{ // both are odd
        if(u>=v)
            return gcd(((u-v)>>1), v);
        else
            return gcd(((v-u)>>1), u);
    }
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int t,a,b;
    for(f>>t;t;--t) {
        f>>a>>b;
        g<<gcd(a,b)<<'\n';
    }
}