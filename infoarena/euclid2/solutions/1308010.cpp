#include <fstream>
#define nmax

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int N, a, b;
void cmmdc(int x1, int x2){
    int r;
    do{
        r = x1 % x2;
        x1 = x2;
        x2 = r;
    }while(r);
    g<<x1<<'\n';
}
int main()
{int i;
    f>>N;
    for(i = 1 ; i <= N ; ++i){
        f>>a>>b;
        cmmdc(a, b);
    }
    return 0;
}
