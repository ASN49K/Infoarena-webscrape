#include <cstdio>

using namespace std;

int lcs(int* a, int* b, int n, int m, int* s){
    int c=0;

    if(n==0||m==0)return 0;
    if(a[n-1]==b[m-1]){
        s[0]=a[n-1];
        c++;
        c+=lcs(a, b, n-1, m-1, s+1);
    }
    else{
        int t1, t2;
        int* p1=new int[100];
        int* p2=new int[100];

        if((t1=lcs(a, b, n-1, m, p1))>(t2=lcs(a, b, n, m-1, p2))){
            c+=t1;
            for(int it=t1;it>0;it--){
                s[t1-it]=p1[it-1];
            }
        }
        else{
            c+=t2;
            for(int it=t2;it>0;it--){
                s[t2-it]=p2[it-1];
            }
        }
    }
    return c;
}

int main()
{
    FILE* f=fopen("cmlsc.in", "r");
    FILE* f1=fopen("cmlsc.out", "w");

    int n, m, v[1024], w[1024];
    fscanf(f, "%d %d", &n, &m);

    for(int i=0;i<n;i++){
        fscanf(f, "%d ", &v[i]);
    }

    for(int i=0;i<m;i++){
        fscanf(f, "%d ", &w[i]);
    }

    int* sol=new int[100];
    int k=lcs(v, w, n, m, sol);
    fprintf(f1, "%d\n", k);

    for(int i=k;i>0;i--){
        fprintf(f1, "%d ", sol[i-1]);
    }
    return 0;
}
