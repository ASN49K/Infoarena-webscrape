#include<fstream>
using namespace std;
int euc(int a,int b){
    if(!b) return a;
        return euc(b,a%b);
}
int main(){
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b;
fin>>n;
    for(int i=1;i<=n;++i){
        fin>>a>>b;

         fout<<euc(a,b)<<endl;
    }
}


