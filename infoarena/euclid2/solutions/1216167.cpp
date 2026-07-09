#include <fstream>

using namespace std;


ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int n;
long long x,y;

unsigned int cmmdc(long long a, long long b ){
    int r;
    while(b){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    fin>>n;
    while(n){
        fin>>x>>y;
        fout<<cmmdc(x,y)<<'\n';
        n--;
    }
    return 0;
}
