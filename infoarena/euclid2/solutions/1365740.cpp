#include <iostream>
#include <fstream>

using namespace std;

#define min(a,b) (a<b)?a:b
#define max(a,b) (a>b)?a:b

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, a, b;

int euclid(int a, int b){
    //gcd(a,b) = b iff a|b
    //gcd(a,b) = gcd(b,r)
    int r;
    while(a%b !=0) {
        r = a % b;
        a = b;
        b = r;
    }
    return b;
}

int main()
{
    ios::sync_with_stdio(false);
    fin >> n;
    while(n-- > 0){
        fin >> a >> b;
        fout << euclid(max(a,b), min(a,b)) << '\n'  ;
    }
    return 0;
}
