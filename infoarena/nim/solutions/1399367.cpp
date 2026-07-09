#include <fstream>
#define DIM 10011
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int t,n,tot;

int main(void){
    register int i,j,x;


    f>>t;
    for(;t>0;t--){
        f>>n;
        tot=0;
        for(i=1;i<=n;i++){
            f>>x;
            tot^=x;
        }
        if(tot) g<<"DA\n";
        else g<<"NU\n";
    }
    f.close();
    g.close();
    return 0;
}
