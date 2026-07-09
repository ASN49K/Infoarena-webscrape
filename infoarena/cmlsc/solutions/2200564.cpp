#include <iostream>
#include <fstream>
using namespace std;
ifstream f("rf.in");
ofstream g("rf.out");
const int Dim=261;
int a[Dim][Dim],N,i,j,k,b[Dim][Dim];
void citire()
{
    f>>N;
    int i,j;
    for(i=1; i<=N; i++)
        for(j=1; j<=N; j++)
            f>>a[i][j];
}
void royfloyd()
{
    int i,j,k;
    for(k=1; k<=N; k++)
        for(i=1; i<=N; i++)
            for(j=1; j<=N; j++)
                if(a[i][k] && a[k][j] && i!=j && (a[i][j]>a[i][k]+a[k][j] || !a[i][j]))
                    {a[i][j]=a[i][k]+a[k][j];b[i][j]==b[i][k]+b[k][j];}
}

void afisare(int a[261][261])
{
    int i,j;
    for(i=1; i<=N; i++)
    {
        for(j=1; j<=N; j++)
            g<<a[i][j]<<" ";
        g<<endl;
    }
}

int main()
{
    citire();
    for(i=1;i<=N;i++)
        if(a[i][j]!=0)b[i][j]=1;
    royfloyd();
    afisare(a);
    afisare(b);
    return 0;
}
