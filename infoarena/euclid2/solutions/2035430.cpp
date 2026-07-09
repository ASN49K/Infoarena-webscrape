#include <fstream>
#include <vector>

using namespace std;
int x,prim;
bool a[20000001];

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a, int b){
    int r;
    while(b){
        r = a % b;
        a = b;
        b = r;
    }
    return b;
}

int main()
{
    int a, b, t;
    f>>t;
    for(int i = 0; i < t; i++){
    f>>a>>b;
    g<<euclid(a, b)<<'\n';
    }
    return 0;
}
