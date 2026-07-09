#include <fstream>
using namespace std;
int cmmdc(int a, int b){
    if(b==0) return a;
    if(a>b) return cmmdc(a-b,b);
    return cmmdc(a,b-a);
    return a;
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,t;
    fin>>t;
    for(int i=1;i<=t;i++)
    {
    fin>>a>>b;
    fout<<cmmdc(a,b)<<endl;
    }
    return 0;
}
