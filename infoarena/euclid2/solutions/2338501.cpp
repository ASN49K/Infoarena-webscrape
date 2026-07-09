#include <fstream>
using namespace std;
int cmmdc(int a, int b){
    if(!b) return a;
    return cmmdc(b,a%b);
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int t;
    fin>>t;
   while(t)
    {
    int a,b;
    fin>>a>>b;
    fout<<cmmdc(a,b)<<'\n';
    --t;
    }
    return 0;
}
