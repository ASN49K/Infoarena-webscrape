#include <fstream>
using namespace std;

int gcd(int u, int v){
    if(u == v)
        return v;
    if(u == 0)
        return v;
    if(v == 0)
        return u;
    if(u%2 == 0){ // if u is even
        if(v%2 == 0) // if u and v are even
            return (2*gcd(u/2, v/2));
        else // u is even and v is odd
            return  gcd(u/2, v);
    }
    else if(v%2 == 0) // if u is odd and v is even
        return gcd(u, v/2);
    else{ // both are odd
        if(u>=v)
            return gcd((u-v)/2, v);
        else
            return gcd((v-u)/2, u);
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