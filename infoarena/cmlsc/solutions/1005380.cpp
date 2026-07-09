#include <stdio.h>
#define fr(i,a,b) for(int i=a;i<b;++i)
#define N 1024

int a[N],b[N];
int r[N][N];
int p[N][N];
bool first;
void printa(int x,int y){
    switch(p[x][y]){
        case 0: return;
        case 1: printa(x-1,y);return;
        case 2: printa(x,y-1);return;
        case 3: printa(x-1,y-1);break;
        }
    if(!first)printf(" ");else first=false;
    printf("%i",a[x]);
    }
int main(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m;
    scanf("%i%i",&n,&m);
    fr(i,0,n)scanf("%i",a+i);
    fr(i,0,m)scanf("%i",b+i);
    fr(i,0,n){
        fr(j,0,m){
            int max1=0;
            int mp=0;
            int max2=i?r[i-1][j]:0;
            if(max2>max1){max1=max2;mp=1;}
            max2=j?r[i][j-1]:0;
            if(max2>max1){max1=max2;mp=2;}
            max2=(a[i]==b[j])?(i&&j?r[i-1][j-1]+1:1):0;
            if(max2>max1){max1=max2;mp=3;}
            r[i][j]=max1;
            p[i][j]=mp;
            }
        }
    if(!n||!m){printf("0\n");return 0;}
    printf("%i\n",r[n-1][m-1]);
    first=true;
    printa(n-1,m-1);
    if(!first) printf("\n");

    return 0;
    }
