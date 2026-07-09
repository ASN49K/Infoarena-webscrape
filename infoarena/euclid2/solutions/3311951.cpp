#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int rec(int a, int b){
    if(min(a,b)==0)
        return max(a,b);
    return rec(max(a,b)%min(a,b), min(a,b));
}
int main()
{
    int t,a,b;
    fin>>t;
    for(int i=1;i<=t;i++){
        fin>>a>>b;
        fout<<rec(a,b)<<'\n';
    }
    return 0;
}
