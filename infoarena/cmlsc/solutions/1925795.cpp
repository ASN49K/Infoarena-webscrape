#include <algorithm>
#include <cstdio>
#include <vector>
#define N 1025
using namespace std;

vector <int> A,B,Sol;
int d[N][N],lga,lgb;

void Read(){

    int x,i;
    freopen("cmlsc.in","r",stdin);
    A.push_back(0);B.push_back(0); //am nevoie ca vectorii sa inceapa de la 1

    scanf("%d%d",&lga,&lgb);
    for (i=0;i<lga;++i) {
        scanf("%d",&x);
        A.push_back(x);
        }
    for (i=0;i<lgb;++i) {
        scanf("%d",&x);
        B.push_back(x);
        }
}

void Dynamic(){

    int i,j;

    for (i=0;i<=lga;++i)
        for (j=0;j<=lgb;++j)
            if (!i || !j) d[i][j]=0;
            else if (A[i]==B[j]) d[i][j]=d[i-1][j-1]+1;
                 else d[i][j]=max(d[i][j-1],d[i-1][j]);

    i=lga;j=lgb;
    while (i>0 && j>0)
        {
        if (A[i]==B[j]) {
            Sol.push_back(A[i]);
            i--;
            j--;
            }
        else if (d[i][j]==d[i-1][j]) i--;
             else j--;
        }
}

void Write(){

    int i;
    freopen("cmlsc.out","w",stdout);

    printf("%d\n",d[lga][lgb]);
    for (i=Sol.size()-1;i>=0;i--)
        printf("%d ",Sol[i]);

}

int main()
{
    Read();
    Dynamic();
    Write();
    return 0;
}
