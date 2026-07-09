#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


long cmmdc(long a, long b){
    long r;
    while(b!=0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}


int main()
{
    int t;
    long a,b;
    fin>>t;

    while(t--){
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';

    }


    return 0;
}
