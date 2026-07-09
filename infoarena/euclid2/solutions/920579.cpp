#include<fstream>
using namespace std;
int i,n,x,y;

int cmmdc( int a, int b) {
    int r;
    do {
        r=a%b;
        a=b; b=r;
       } while (r!=0);
    return(a);
}

int main(void){
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>n;
    for (i=1; i<=n; ++i) { fin>>x>>y; fout<<cmmdc(x,y)<<"\n"; }
 return(0);
}
