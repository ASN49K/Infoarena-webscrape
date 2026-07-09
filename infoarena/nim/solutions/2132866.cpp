#include <stdio.h>
#include <stdlib.h>

using namespace std;

int v[10001];

int trans(int x){
    if(x==0)
        return 0;
    long long p=1;
    while(p<=x)
        p<<=1;
    p>>=1;
    return p;
}

int main()
{
    FILE *fin, *fout;
    int n,k,i;
    fin=fopen("nim.in","r");
    fout=fopen("nim.out","w");
    fscanf(fin,"%d",&n);
    for(n;n>0;n--){
        fscanf(fin,"%d",&k);
        int total=0;
        for(i=0;i<k;i++){
            fscanf(fin,"%d",&v[i]);
            total=(total^v[i]);
        }
        total=trans(total);
        if(total!=0){
            i=0;
            while(i<k && (v[i]&total)!=total)
                i++;
            if(i<k)
                fprintf(fout,"DA\n");
            else
                fprintf(fout,"NU\n");
        }else
            fprintf(fout,"NU\n");
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
