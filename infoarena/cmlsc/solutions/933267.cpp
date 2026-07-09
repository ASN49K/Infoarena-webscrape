#include <fstream>

using namespace std;

int f[300];

int main(){
    int n,m,a,i,S;
    S=0;
    ifstream in ("cmlsc.in");
    ofstream out ("cmlsc.out");
    in>>n>>m;
    for(i=1;i<=n;i++){
        in>>a;
        f[a]++;
    }
    i=0;
    while(i!=m){
        in>>a;
        if(f[a]==1){
            S++;
            f[a]++;
        }
        i++;
    }
    out<<S<<'\n';
    for(i=0;i<=256;i++)
        if(f[i]==2){
            out<<i<<" ";
        }
    in.close();
    out.close();
    return 0;
}
