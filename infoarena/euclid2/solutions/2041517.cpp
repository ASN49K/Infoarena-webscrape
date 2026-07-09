#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int n;

struct per{
    int a, b;
}pereche;

int rezolvare(int a,int b){
    if(!b) return a;
    else rezolvare(b, a%b);
}

int main()
{
    in>>n;
    for(int i=1; i<=n; i++){
        in>>pereche.a>>pereche.b;
        out<<rezolvare(pereche.a, pereche.b)<<endl;
    }
    return 0;
}
