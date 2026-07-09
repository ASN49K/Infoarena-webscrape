# include <fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int n,t,x,s,i,r;
int main () {
    fin>>t;
    for(r=1;r<=t;r++){
        fin>>n;
        for(i=1;i<=n;i++){
            fin>>x;
            s^=x;
        }
        if(s)
            fout<<"DA\n";
        else
            fout<<"NU\n";
    }
    return 0;
}
