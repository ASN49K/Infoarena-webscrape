#include <fstream>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t,n,i,j;

int main(){
    for(fin>>t;t;t--){
        fin>>n>>i;
        for(n--;n;n--){
            fin>>j;
            i=i^j;
        }

        if(i==0)
            fout<<"NU\n";
        else
            fout<<"DA\n";
    }

    return 0;
}
