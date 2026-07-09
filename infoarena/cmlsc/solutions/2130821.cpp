#include <iostream>
#include <fstream>
using namespace std;
int A[1024],B[1024],m,n;
int matrice[1024][1024];
ofstream g("cmlsc.out");
void citire()
{
    ifstream f("cmlsc.in");
    f>>m>>n;
    int i,j;
    for(i=1; i<=m; i++)
        f>>A[i];
    for(j=1; j<=n; j++)
        f>>B[j];
    f.close();
}
void solutie(int i,int j)
{
    if(i!=0 && j!=0)
    {
        if(A[i]==B[j])
        {
            solutie(i-1,j-1);
            g<<A[i]<<" ";
        }
        else
        {
            if(matrice[i][j]==matrice[i][j-1])
                solutie(i,j-1);
            else
                solutie(i-1,j);
        }
    }
}
void CMS()
{
    int i,j;
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if(A[i]==B[j])
                matrice[i][j]=matrice[i-1][j-1]+1;
            else
                matrice[i][j]=max(matrice[i-1][j],matrice[i][j-1]);
    //cout<<"Cel mai lung subsir maximal are lungimea: "<<matrice[m][n]<<endl;
}
int main()
{
    citire();
    cout<<m<<" "<<n;
    CMS();
    int i,j;
    cout<<"  ";
    for(j=1; j<=n; j++)
        cout<<B[j]<<" ";
    cout<<endl;
    for(i=1; i<=m; i++)
    {
        cout<<A[i]<<" ";
        for(j=1; j<=n; j++)
            cout<<matrice[i][j]<<" ";
        cout<<endl;
    }
    solutie(m,n);
    return 0;
}
