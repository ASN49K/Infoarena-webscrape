#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int n;

struct per{
    int a, b;
}pereche;

void rezolvare(per z){
    int c;
    while(z.b){
        c=z.a%z.b;
        z.a=z.b;
        z.b=c;
    }
    out<<z.a<<endl;
}

int main()
{
    in>>n;
    for(int i=1; i<=n; i++){
        in>>pereche.a>>pereche.b;
        rezolvare(pereche);
    }
    return 0;
}
