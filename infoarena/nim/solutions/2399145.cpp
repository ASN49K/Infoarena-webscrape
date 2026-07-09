#include <fstream>

using namespace std;

ifstream fin ("nim.in");
ofstream fout ("nim.out");
int t,n,x,val,i;
int main (){

    fin>>t;
    for (;t--;){
        fin>>n;
        fin>>val;
        for (i=2;i<=n;i++){
            fin>>x;
            val ^= x;
        }
        if (val == 0)
            fout<<"NU\n";
        else fout<<"DA\n";
    }

    return 0;
}
