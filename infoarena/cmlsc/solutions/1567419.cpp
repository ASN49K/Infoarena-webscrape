#include <iostream>
#include <fstream>
#include <vector>
#define NMAX 1030
using namespace std;

vector<unsigned char> a,b;
int N,M,D[NMAX][NMAX];
void read()
{
    unsigned char x;
    scanf("%d%d", &N, &M);
    for(int i=1;i<=N;i++){
        scanf("%d", &x);
        a.push_back(x);
    }
    for(int i=1;i<=M;i++){
        scanf("%d", &x);
        b.push_back(x);
    }
}

afisareSirComun()
{
    vector<int> sol;
    int i,j;
    i=N;
    j=M;
    while(i)
    {
        if(a[i-1]==b[j-1]){
            sol.push_back(a[i-1]);i--;j--;
        }
        else
            if(D[i-1][j]<D[i][j-1])
                j--;
            else
                i--;
    }
    for(int i=sol.size()-1;i>=0;i--)
        cout<<sol[i]<<' ';
    cout<<'\n';

}

int dinamica()
{
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(a[i-1]==b[j-1])
                D[i][j]=D[i-1][j-1]+1;
            else
                D[i][j]=max(D[i-1][j],D[i][j-1]);
    return D[N][M];
}

int main()
{
    freopen("cmlsc.in","rt",stdin);
    freopen("cmlsc.out","wt",stdout);
    read();
    cout<<dinamica()<<'\n';
    afisareSirComun();
}
