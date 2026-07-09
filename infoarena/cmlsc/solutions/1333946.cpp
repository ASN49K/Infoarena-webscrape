#include <iostream>
#include <stdio.h>
using namespace std;
const int N=1069;
int drum[N][N],v[N],n,m;

inline int  maxim(int x, int y){ if(x>y) return x; return y;}

void citire(){
    FILE * in;
    in=fopen("cmlsc.in","r");
    fscanf(in,"%d%d",&n,&m);

    for(int i=1;i<=n;i++)
        fscanf(in,"%d",&drum[0][i]);

    for(int i=1;i<=m;i++)
        fscanf(in,"%d",&drum[i][0]);

}

void rez(){

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(drum[0][i]==drum[j][0]) drum[i][j]=1+drum[i-1][j-1];
            else drum[i][j]=maxim(drum[i-1][j],drum[i][j-1]);


}

void afisare(){
    FILE *out;
    out=fopen("cmlsc.out","w");
    int lung=0;
    for(int i=n,j=m;i;){
        if(drum[0][i]==drum[j][0]) {
                lung++;
                v[lung]=drum[0][i];
                i--;
                j--;
        }
        else if(drum[i-1][j]<drum[i][j-1]) j--;
            else i--;
    }
    fprintf(out,"%d\n",lung);
    for(int i=lung;i>=1;i--){
        fprintf(out,"%d ",v[i]);
    }
}

int main()
{
    citire();
    rez();
    afisare();
    return 0;
}
