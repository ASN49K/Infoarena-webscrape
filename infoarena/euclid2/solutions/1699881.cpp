#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int n,a,b,r,i;
int main () {
    fin>>n;
    for(i=1;i<=n;i++){
        fin>>a>>b;
        while(b!=0){
            r=a;
            a=b;
            b=r%b;
        }
        fout<<a<<"\n";
    }
}
