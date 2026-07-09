#include <fstream>
#include <vector>

using namespace std;
int x,prim;
bool a[20000001];

ifstream f("ciur.in");
ofstream g("ciur.out");

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
    g<<euclid(a, b);
    }
    return 0;
}
