#include <fstream>
using namespace std;
ifstream fin("cmmdc.in");
ofstream fout("cmmdc.out");
int main(){
    int a, b, r, i, t;
    fin>>t;
    for(i=1;i<=t;i++){
    fin>>a>>b;
        while(b!=0){
            r=a%b;
            a=b;
            b=r;
        }fout<<a<<"\n";
    }
}
