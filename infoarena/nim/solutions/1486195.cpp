#include<cstdio>
int t,n,i,j,a,ok;
FILE *f,*g;
int main(){
    f=fopen("nim.in","r");
    g=fopen("nim.out","w");
    fscanf(f,"%d",&t);
    while(t--){
        fscanf(f,"%d%d",&n,&a);
        ok=a;
        for(i=1;i<n;i++){
            fscanf(f,"%d",&a);
            ok=ok^a;
        }
        if(ok)
            fprintf(g,"DA\n");
        else
            fprintf(g,"NU\n");
    }
    fclose(f);
    fclose(g);
    return 0;
}
