#include <fstream>

using namespace std;
int n,a,b;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

void euclid(int a,int b){
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    g<<a<<'\n';
}

int main()
{
    f>>n;
    for(int i=1;i<=n;i++){
        f>>a>>b;
        euclid(a,b);
    }
    return 0;
}
