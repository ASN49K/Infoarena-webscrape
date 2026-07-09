#include <fstream>

using namespace std;
int i, j, m, n, A[1024], B[1024], v[1024], aux;
unsigned char nr[256];
bool ok;
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    for(i=1; i<=m; i++){
        fin>>A[i];
    }
    for(i=1; i<=n; i++){
        fin>>B[i];
        aux=0;
        ok=1;
        for(j=1; j<=m && ok; j++)
            if(B[i]==A[j]){
                if(aux==nr[A[j]]){
                    ok=0;
                    nr[A[j]]++;
                    v[i]=j;
                }else {aux++;}
            }
        if(ok) v[i]=0;
    }
    aux=0;
    for(i=1; i<=n; i++)
        if(v[i]>aux){
            aux=v[i];
            fout<<A[v[i]]<<endl;

    return 0;
}
