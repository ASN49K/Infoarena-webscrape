#include <fstream>

using namespace std;

int main()
{
    ifstream fin("nim.in");
    ofstream fout("nim.out");
    int t,n,a,sum;fin>>t;
    for(int j=1;j<=t;j++){
        fin>>n;sum=0;
        for(int i=1;i<=n;i++){
            fin>>a;sum=sum^a;
        }
        if(sum==0){fout<<"NU"<<'\n';}
        else{fout<<"DA"<<'\n';}
    }
    return 0;
}
