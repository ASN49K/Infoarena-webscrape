#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    if(a>b){
        a%=b;
        return gcd(b,a);
    }
    b%=a;
    return gcd(a,b);
}

int main()
{
    int c;
    fin>>c;
    for(int i=0; i<c; i++){
        int a,b;
        fin>>a>>b;
        fout<<gcd(a, b);
    }
    return 0;
}
