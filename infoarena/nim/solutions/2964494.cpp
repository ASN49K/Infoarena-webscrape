#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int n,t;
string s;
int main(){
    ios_base::sync_with_stdio(false);
    fin>>t;
    while(t--){
        fin>>n;
        int s=0,x;
        for(int i=1;i<=n;i++){
            fin>>x;
            s^=x;
        }
        if(s==0)
            fout<<"NU\n";
        else
            fout<<"DA\n";
    }
    return 0;
}
