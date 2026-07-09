#include<cstdio>
int t,n,a,i,ok;
FILE *f,*g;
int main(){
    f=fopen("nim.in","r");
    g=fopen("nim.out","w");
    fscanf(f,"%d",&t);
    while(t--){
        fscanf(f,"%d%d",&n,&a);
        ok=a;
        for(i=2;i<=n;i++){
            fscanf(f,"%d",&a);
            ok=ok^a;
        }
        if(ok==0)
            fprintf(g,"NU\n");
        else
            fprintf(g,"DA\n");
    }









    fclose(f);
    fclose(g);
    return 0;
}
