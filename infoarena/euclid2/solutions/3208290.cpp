#include <fstream>
using namespace std;
long long n,m,i,j,x,c,smax,y,t;
int divz(long long a, long long b){
    int r = 0;
    while(b){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin >> t;
    for(i =1 ; i <=t; i++){
        fin >> x >> y;
        fout << divz(x,y) << "\n";
    }
    return 0;
}
