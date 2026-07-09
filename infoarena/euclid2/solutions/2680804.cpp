#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,i,k,x[200001];
int main()
{
    fin>>n;
    for(i=1;i<=2*n;i++)
        fin>>x[i];
    for(i=1;i<=2*n-1;i++) {
        if(x[i]<=x[i+1]) {
            for(k=x[i];k>=1;k--)
                if(x[i]%k==0 && x[i+1]%k==0) {
                    fout<<k<<endl;
                    break;
            }
        }
        if(x[i]>x[i+1]) {
            for(k=x[i+1];k>=1;k--)
                if(x[i]%k==0 && x[i+1]%k==0) {
                    fout<<k<<endl;
                    break;
                }
        }
        i++;
    }
    return 0;
}
