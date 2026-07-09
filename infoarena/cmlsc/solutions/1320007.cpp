#include <fstream>
#include <iostream>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int Mla,Mlb,i,j,v1[1025],v2[1025],rez[1025],poz=1;
int matrice[1025][1025];
int main()
{
    in>>Mla>>Mlb;

    for(int i=1; i<=Mla; i++)
    {
        in>>v1[i];
    }
    for(int i=1; i<=Mlb; i++)
    {
        in>>v2[i];
    }
    for(int i=1; i<=Mla; i++)
    {

        for(int j=1; j<=Mlb; j++)
        {
            if(v1[i]==v2[j])
            {
                matrice[i][j]=matrice[i-1][j-1]+1;
            }
            else
            {
                matrice[i][j]=max(matrice[i-1][j],matrice[i][j-1]);
            }
        }
    }
    out<<matrice[Mla][Mlb]<<endl;

    int i=Mla;
    int j=Mlb;
    while(i>=1&&j>=1){
    if(v1[i]==v2[j]){
    rez[poz]=v1[i];
    poz++;
    i--;
    j--;
    } else{
    if(matrice[i][j-1]>matrice[i-1][j]){
    j=j-1;
    } else{
    i=i-1;
    }
    }
    }
     for(i=poz-1;i>=1;i--){
     out<<rez[i]<<" ";
     }

}
