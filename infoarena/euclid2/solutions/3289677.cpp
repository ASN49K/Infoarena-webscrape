#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a, int b){
    if(b==0) return a;
    return cmmdc(b, a%b);
}
int main(){
    int t;
    fin>>t;
    while(t--){
        int a, b;
        fin>>a>>b;
        fout<<cmmdc(a,b)<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
