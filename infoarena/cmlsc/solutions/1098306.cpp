#include <iostream>
#include <fstream>
using namespace std;

int X[1025], Y[1025], N, M, Lmax[1025][1025];
ofstream g("cmlsc.out");

void rezolva() {
    int i,j;
    for(i=1; i<=N; i++) Lmax[i][0]==0;
    for(j=1; j<=M; j++) Lmax[0][j]==0;

    for(i=1; i<=N; i++)
        for(j=1; j<=M; j++)
            if(X[i]==Y[j])
                Lmax[i][j]=1+Lmax[i-1][j-1];
            else
                if(Lmax[i-1][j]>Lmax[i][j-1])
                    Lmax[i][j]=Lmax[i-1][j];
                else
                    Lmax[i][j]=Lmax[i][j-1];


}

void afiseaza_solutie_max(int k,int h){
if(Lmax[k][h])
     if(X[k]==Y[h])
       {afiseaza_solutie_max(k-1,h-1);
       g<<X[k]<<' ';}
     else
        {if (Lmax[k][h]==Lmax[k-1][h])
         afiseaza_solutie_max(k-1,h);
         else if (Lmax[k][h]==Lmax[k][h-1])
         afiseaza_solutie_max(k,h-1);
     }
}

int main()
{
    ifstream f("cmlsc.in");

    f>>N>>M;
    for(int i=1; i<=N; i++) f>>X[i];
    for(int i=1; i<=M; i++) f>>Y[i];
    f.close();
    rezolva();
    g<<Lmax[N][M]<<"\n";
    afiseaza_solutie_max(N, M);
    g.close();
    return 0;
}
