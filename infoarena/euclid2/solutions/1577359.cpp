#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
inline int cmmdc(int a,int b){int r;while(b!=0){r=a%b;a=b;b=r;}return a;}
int main()
{
    int n,a,b;
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
