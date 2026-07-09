#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b){
    int r;
    while(b){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    int n,aux1,aux2;
    f>>n;
    for(int i=1;i<=n;i++){
        f>>aux1>>aux2;
        g<<cmmdc(aux1,aux2)<<endl;
    }
    f.close();
    g.close();
}
