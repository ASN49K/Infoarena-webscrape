#include <iostream>
#include <fstream>

using namespace std;

int euclid(int a, int b)
{
    int aux;
    while(b != 0){
        aux = b;
        b = a%b;
        a = aux;
    }
    return a;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    int t;
    int x,y;
    f>>t;
    for(int i=0;i<t;++i){
        f>>x>>y;
        g << euclid(x,y)<<'\n';
    }
    return 0;
}
