#include <iostream>
#include<fstream>
using namespace std;

int matrice[1030][1030];

int LCS(int *s1,int *s2,int Ls1,int Ls2)
{

    for(int i=1;i<=Ls1;i++)
    {
        for(int j=1;j<=Ls2;j++)
        {
            if(s1[i]==s2[j])
                matrice[i][j]=matrice[i-1][j-1]+1;
            else
            {
                int maxim=matrice[i][j-1];
                if(maxim<matrice[i-1][j])
                    maxim=matrice[i-1][j];
                matrice[i][j]=maxim;
            }

        }
    }
    return matrice[Ls1][Ls2];
}

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int Ls1,Ls2;
    int s1[1030];
    int s2[1030];
    fin>>Ls1>>Ls2;
    for(int i=1;i<=Ls1;i++)
        fin>>s1[i];
    for(int i=1;i<=Ls2;i++)
        fin>>s2[i];
    fout<<LCS(s1,s2,Ls1,Ls2);


    return 0;
}
