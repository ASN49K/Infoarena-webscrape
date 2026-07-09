#include <fstream>
using namespace std;
ifstream fin ("nim.in");
ofstream fout ("nim.out");
int t,i,a,j,S,x;
int main()
{
    fin>>t;
    for(i=1;i<=t;i++){
        fin>>a;
        S=0;
        for(j=1;j<=a;j++){
            fin>>x;
            S^=x;
        }
        if(S!=0)
            fout<<"DA"<<"\n";
        else
             fout<<"NU"<<"\n";

    }
    return 0;
}
