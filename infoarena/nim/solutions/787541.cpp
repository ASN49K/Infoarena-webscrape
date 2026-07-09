#include <fstream>
#define MAXN 10005
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");

int t,n,x,a;

int main()
{
    int i,j;
    f>>t;
    for(i=1;i<=t;i++){
        f>>n;
        x=0;
        for(j=1;j<=n;j++){
            f>>a;
            x=x xor a;}
        g<<((x)?"DA\n":"NU\n");}
    f.close();
    g.close();
    return 0;
}
