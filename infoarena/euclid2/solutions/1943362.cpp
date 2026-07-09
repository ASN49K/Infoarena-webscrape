#include <iostream>
#include <fstream>

using namespace std;

unsigned int euclid(unsigned int a, unsigned int b)
{
    unsigned int aux;
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
    unsigned int x,y;
    f>>t;
    for(int i=0;i<t;++i){
        f>>x>>y;
        g << euclid(x,y)<<endl;
    }
    return 0;
}
