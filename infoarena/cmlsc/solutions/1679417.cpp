#include <iostream>
#include <fstream>

using namespace std;

ifstream q("cmlsc.in");
ofstream w("cmlsc.out");

int k,y,ver[1025][1025];

///y-ul este folosit la afisare. Odata ce sa gasit un element comun, al doilea vector sa fie cautat de la pozitia "element comun"+1 , pt. a se evita dubla afisare a aceluiasi elemnt, daca el apare de doua ori in v1 si doar o dat ain v2

int maxim(int a,int b)
{
    if(a<b) return b;
    return a;
}

void dinamic(int a[],int b[],int n,int m)
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j]) {ver[i][j]=ver[i-1][j-1]+1;}
            else ver[i][j]=maxim(ver[i][j-1],ver[i-1][j]);
        }
    w<<ver[n][m]<<"\n";
}

void afis(int a[],int b[],int i,int j,int n,int m,int k)
{
    if(k>0)
        if(i<=n)
            if(j<=m)
            {
                if(a[i]==b[j])
                {
                    w<<a[i]<<" ";
                    y++;
                    afis(a,b,i,j+1,n,m,k-1);
                }
                else afis(a,b,i,j+1,n,m,k);
            }
            else afis(a,b,i+1,y,n,m,k);
}

int main()
{int n,m,i,j,v1[1030],v2[1030];
    q>>n>>m;
    for(i=1;i<=n;i++) q>>v1[i];
    for(i=1;i<=m;i++) q>>v2[i];
    dinamic(v1,v2,n,m);
    y=1;
    afis(v1,v2,1,1,n,m,ver[n][m]);


    return 0;
}
