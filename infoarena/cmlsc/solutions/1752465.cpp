#include<iostream>
#include<fstream>
#define DX 1050
using namespace std;
fstream fin("cmlsc.in",ios::in),fout("cmlsc.out",ios::out);
int *x,*y,n,m,maxim,ai,bj;

void citire();
void dp();
void scrie(int a,int b);

struct bs{
public:
    bs(){
        c=i=j=0;
    }
    bs(int c,int i,int j): c{c},i{i},j{j}
    {
    }
    bool operator < (const bs& b) const{
        return (this->c<b.c);
    }
    int c,i,j;
};
bs bst[DX][DX];

int main()
{
    int a,b,aux;
    citire();
    dp();
    fout<<bst[ai][bj].c<<"\n";
    scrie(ai,bj);
}
void scrie(int a,int b)
{
    if(a==0) return;
    scrie(bst[a][b].i,bst[a][b].j);
    if(x[a]==y[b]) fout<<x[a]<<" ";
}

void dp()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(x[i]==y[j])
            {
                bst[i][j].c++;
                if(bst[i][j].c>bst[i+1][j+1].c) bst[i+1][j+1]=bs(bst[i][j].c,i,j);
            }
            else
            {
                bst[i+1][j]=max(bst[i+1][j],bst[i][j]);
                bst[i+1][j+1]=max(bst[i+1][j+1],bst[i][j]);
                bst[i][j+1]=max(bst[i][j+1],bst[i][j]);
            }
            if(bst[i][j].c>maxim)
            {
                maxim=bst[i][j].c;
                ai=i;bj=j;
            }
        }
    }
}

void citire()
{
    int i;
    fin>>n>>m;
    x=new int[n+2];
    y=new int[m+2];
    for(i=1;i<=n;i++) fin>>x[i];
    for(i=1;i<=m;i++) fin>>y[i];
}
