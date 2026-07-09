#include <cstdio>
#include <algorithm>
#define NMAX 1030
using namespace std;
int sir1[NMAX],sir2[NMAX];
int mat[NMAX][NMAX];
int subsir[NMAX];
int dirI[3]={-1,-1,0};
int dirJ[3]={-1,0,-1};

void CreateMat(int n1,int n2)
{
    int x,y;
    for(int i = 1 ;  i <= n2 ; i++)
    {
        for(int j = 1;  j <= n1 ; j++)
            if(sir1[j] == sir2[i])
                mat[i][j] = mat[i-1][j-1] + 1;
            else
                mat[i][j] = max(max(mat[i-1][j-1],mat[i-1][j]),mat[i][j-1]);
    }

}

int  Solution(int n1,int n2)
{
    int x,y;
    int i = n2, j = n1;
    int nrelem = 0;
    while(mat[i][j])
    {
        if(sir1[j] == sir2[i])
        {
           subsir[nrelem++] = sir2[i];
            i--;
            j--;
        }
        else
            for(int bearing = 0 ; bearing < 3 ; i++)
            {
                y = i + dirI[bearing];
                x = j + dirJ[bearing];
                if(mat[y][x] == mat[i][j])
                {
                    i = y;
                    j = x;
                    break;
                }
            }
    }
    return nrelem;
}

void PrintSolution(int nrelem)
{
    printf("%d\n",nrelem);
    for( nrelem--; nrelem >= 0 ; nrelem--)
        printf("%d ",subsir[nrelem]);
}

void Preparation(int &n1, int &n2)
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n1,&n2);
    for(int i = 1 ; i <= n1 ; i++)
        scanf("%d ",&sir1[i]);
    for(int i = 1 ; i <= n2; i++)
        scanf("%d",&sir2[i]);
    CreateMat(n1,n2);
}


int main()
{
    int n1,n2;
    Preparation(n1,n2);
    int nrelem = Solution(n1,n2);
    PrintSolution(nrelem);
    return 0;
}
