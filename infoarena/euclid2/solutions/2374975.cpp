#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a, int b){
    if(!b)
        return a;
    return cmmdc(b, a%b);
}
int main(){
    int t, x, y;
    fin>>t;
    while(t){
        fin>>x>>y;
        fout<<cmmdc(x, y)<<endl;
        t--;
    }
    return 0;
}