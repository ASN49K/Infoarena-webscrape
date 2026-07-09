#include <fstream>

using namespace std;

ifstream f ("euclid2.in");
ofstream t ("euclid2.out");

int euclid(int a,int b){
    int aux;
    while (b){
        aux=b;
        b=a%b;
        a=aux;
    }
    return a;
}

int main()
{
    int q;
    f>>q;
    for (int a,b;q;--q)
        f>>a>>b,
        t<<euclid(a,b)<<'\n';
    return 0;
}
