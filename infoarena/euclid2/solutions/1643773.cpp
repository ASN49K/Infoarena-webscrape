#include <iostream>
#include <fstream>
using namespace std;

int euclidus(int a, int b){
    if(b)
        euclidus(b,a%b);
    else
    return a;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int T;
    f>>T;
    int x,y;
    for(int i=T;i>0;i--){
        f>>x>>y;
        g<<euclidus(x,y);
        g<<"\n";
    }
    return 0;
}
