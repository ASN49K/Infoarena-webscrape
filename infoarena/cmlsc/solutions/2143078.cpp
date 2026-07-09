#include <cstdio>
#include <algorithm>

using namespace std;
const int NMAX = 1030;
int lim1,lim2;
int sir1[NMAX],sir2[NMAX];
int mat[NMAX][NMAX];
int solutie[NMAX];
int dirI[3]={0,-1,-1};
int dirJ[3]={-1,0,-1};

void rezolvare(int &nrelem)
{
    int i = lim2;
    int j = lim1;
    while(mat[i][j])
    {
        if(sir1[j] == sir2[i])
        {
            solutie[nrelem++]= sir1[j];
            i--;
            j--;
        }
        else
        {
            for(int k = 0 ; k < 3 ; k++)
            {
                int x = i + dirI[k];
                int y = j + dirJ[k];
                if(mat[x][y] == mat[i][j])
                {
                    i = x;
                    j = y;
                    break;
                }
            }
        }
    }

}

void preparation()
{
    for(int i = 1 ; i<= lim2 ; i++)
    {
        for(int j = 1; j <= lim1 ; j++)
        {
            if(sir2[i]== sir1[j])
            {
                mat[i][j] = mat[i-1][j-1]+ 1;
            }
            else
            {
                mat[i][j] = max(max(mat[i-1][j],mat[i-1][j-1]),mat[i][j-1]);
            }
        }
    }
}

void read()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&lim1,&lim2);
    for(int i = 1 ; i <= lim1 ; i++)
        scanf("%d ",&sir1[i]);
    for(int i = 1 ; i <= lim2 ; i++)
        scanf("%d",&sir2[i]);

}

int main()
{
    read();
    int nrelem = 0;
    preparation();
    rezolvare(nrelem);
    printf("%d\n",nrelem);
    for(int i = nrelem - 1; i >= 0 ; i--)
        printf("%d ",solutie[i]);
    return 0;
}
