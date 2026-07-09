#include <stdio.h>
#include <stdlib.h>

int bin1(int* v,int n,int x) {
    int i,j,m;
    i = 1; j = n;
    while (1) {
        if (x == v[j]) return j;
        m = (i + j) / 2;
        if (x == v[m]) {
            while (m <= n && v[m] == x) m++;
            return m-1;
        }
        if (i == j-1) return -1;
        if (x < v[m]) j = m;
        else i = m;
    }
    return 0;
}

int bin2(int* v,int n,int x) {
    int i,j,m;
    i = 1; j = n;
    while (1) {
        if (x >= v[j]) return j;
        m = (i + j) / 2;
        if (x == v[m]) {
            while (m <= n && v[m] == x) m++;
            return m-1;
        }
        if (i == j-1) return i;
        if (x < v[m]) j = m;
        else i = m;
    }
    return 0;
}

int bin3(int* v,int n,int x) {
    int i,j,m;
    i = 1; j = n;
    while (1) {
        if (x <= v[i]) return i;
        m = (i + j) / 2;
        if (x == v[m]) {
            while (m >= 1 && v[m] == x) m--;
            return m+1;
        }
        if (i == j-1) return j;
        if (x < v[m]) j = m;
        else i = m;
    }
    return 0;
}

int main()
{
    FILE *f = fopen("cautbin.in","r");
    FILE *g = fopen("cautbin.out","w");
    int n,m,*v,i,x,y;
    fscanf(f,"%d",&n);
    v = (int*)malloc((n+1)*sizeof(int));
    for (i=1;i<=n;i++)
        fscanf(f,"%d",&v[i]);
    fscanf(f,"%d",&m);
    for (i=0;i<m;i++) {
        fscanf(f,"%d %d",&x,&y);
        if (x == 0) fprintf(g,"%d\n",bin1(v,n,y));
        if (x == 1) fprintf(g,"%d\n",bin2(v,n,y));
        if (x == 2) fprintf(g,"%d\n",bin3(v,n,y));
    }
    fclose(f);
    fclose(g);
    return 0;
}
