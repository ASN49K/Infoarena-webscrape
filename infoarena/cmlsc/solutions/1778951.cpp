#include <stdio.h>
#include <stdlib.h>
#define MAXN 1024

#define BUF_SIZE 16384
char buf[BUF_SIZE];
int pbuf=BUF_SIZE;
FILE*fi,*fo;
inline char nextch(){
    if(pbuf==BUF_SIZE){
        fread(buf, BUF_SIZE, 1, fi);
        pbuf=0;
    }
    return buf[pbuf++];
}
inline long long nextnum(){
    long long a=0;
    char c=nextch();
    while((c<'0' || c>'9') && c!='-')
        c=nextch();
    int semn=1;
    if(c=='-'){
        semn=-1;
        c=nextch();
    }
    while('0'<=c && c<='9'){
        a=a*10+c-'0';
        c=nextch();
    }
    return a*semn;
}

inline int maxim(int a, int b){
    return a > b ? a : b;
}

int a[1+MAXN], b[1+MAXN], d[1+MAXN][1+MAXN], stiva[MAXN+1], ind;
int main(){
    fi=fopen("cmlsc.in","r");
    fo=fopen("cmlsc.out","w");
    int n=nextnum(), m=nextnum();
    for(int i=1;i<=n;i++) a[i]=nextnum();
    for(int j=1;j<=m;j++) b[j]=nextnum();

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=maxim(d[i-1][j], d[i][j-1]);

    int i=n, j=m;
    while(i){
        if(a[i]==b[j]){
            stiva[++ind]=a[i];
            i--;
            j--;
        }
        else if(d[i-1][j]<d[i][j-1])
            j--;
        else
            i--;
    }
    fprintf(fo,"%d\n", ind);
    for(int i=ind;i>0;i--)
        fprintf(fo,"%d ", stiva[i]);
    fclose(fi);
    fclose(fo);
    return 0;
}
