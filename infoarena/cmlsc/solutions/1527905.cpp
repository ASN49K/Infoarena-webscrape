#include <fstream>

using namespace std;
int i, x, v[1025], a[1025], n, p, nr;
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>n>>p;
    for(i=1;i<=n;i++){
        fin>>x;
        v[x]=1;
    }
    for(i=1;i<=p;i++){
        fin>>x;
        a[x]=1;
    }
    for(i=1;i<=n;i++){
        if(a[i]==v[i] && a[i]!=0){
           nr++;
           fout<<a[i]<<" ";
        }
    }
    return 0;
}
