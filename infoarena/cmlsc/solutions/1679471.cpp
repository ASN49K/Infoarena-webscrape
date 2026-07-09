#include <iostream>
#include <fstream>

using namespace std;

ifstream q("cmlsc.in");
ofstream w("cmlsc.out");

int k,y,sir[1025],ver[1025][1025];
int n,m;

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

void afis(int a[],int b[],int n,int m,int k)
{
    int i,j;
    for(i=n,j=m;i;)
    {
        if(a[i]==b[j]) {sir[++y]=a[i];i--;j--;}
        else if(ver[i][j-1]>ver[i-1][j]) j--;
            else i--;
    }
    for(i=y;i>=1;i--) w<<sir[i]<<" ";
}


int main()
{int i,v1[1030],v2[1030];
    q>>n>>m;
    for(i=1;i<=n;i++) q>>v1[i];
    for(i=1;i<=m;i++) q>>v2[i];
    dinamic(v1,v2,n,m);
    afis(v1,v2,n,m,ver[n][m]);


    return 0;
}
