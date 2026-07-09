# include <fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int t,n,x,r,i,s;
int main () {
    fin>>t;
    for(r=1;r<=t;r++){
        fin>>n;
        s=0;
        for(i=1;i<=n;i++){
            fin>>x;
            s=(s^x);
        }
        if(s==0)
            fout<<"NU\n";
        else
            fout<<"DA\n";
    }
    return 0;
}
