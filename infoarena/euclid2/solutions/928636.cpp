#include <fstream>
using namespace std;
int a,b,r,i,n;
int main()
{ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>n;
for (i=1; i<=n; i++){
    f>> a >>b;
    r=0;
    while (b!=0){
        r=a%b;
        a=b;
        b=r;
        }
    g<<a<<'\n';
}
g.close(); f.close(); return 0;
}
