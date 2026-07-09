#include <iostream>
#include <fstream>
using namespace std;
ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
int n,m;
int LCS[1025][1025];
int LCSPasi[1025][1025];
int V1[1025];
int V2[1025];
void gasire(int linie,int coloana)
{
    if(linie>0 && coloana>0)
    {
        if(LCS[linie][coloana]!=0 )
        {
            if(LCSPasi[linie][coloana]==-1)
                gasire(linie,coloana-1);
            else if(LCSPasi[linie][coloana]==2)
                gasire(linie-1,coloana);
            else
            {
                gasire(linie-1,coloana-1);
                fo<<V1[linie]<<" ";
            }
        }
    }
}
int main()
{
    ///Pasi
    ///1 pentru diagonala
    ///-1 pentru stanga - aceeasi linie,col-1
    ///2 pnetru joc - aceeasi coloana , linie-1

    fi>>n>>m;
    for(int i=1;i<=n;i++)
        fi>>V1[i];
    for(int i=1;i<=m;i++)
        fi>>V2[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(V1[i]==V2[j])
            {
                LCS[i][j]=LCS[i-1][j-1]+1;
                LCSPasi[i][j]=1;
            }else
            {
                if(LCS[i-1][j]>LCS[i][j-1])
                {
                    LCS[i][j]=LCS[i-1][j];
                    LCSPasi[i][j]=2;
                }else
                {
                    LCS[i][j]=LCS[i][j-1];
                    LCSPasi[i][j]=-1;
                }
            }
        }
    }
    fo<<LCS[n][m]<<endl;
    gasire(n,m);
    return 0;
}
