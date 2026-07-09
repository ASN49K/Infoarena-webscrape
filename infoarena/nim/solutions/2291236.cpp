#include <fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int t,n,sol,i,x;
int main(){
    fin>>t;
    for(;t--;){
        fin>>n;
        sol=0;
        for(i=1;i<=n;i++){
            fin>>x;
            sol^=x;
        }
        if(sol==0)
            fout<<"NU\n";
        else
            fout<<"DA\n";
    }
    return 0;
}
