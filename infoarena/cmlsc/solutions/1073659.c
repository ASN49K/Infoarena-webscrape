#include <stdio.h>
int a[1025],b[1025],v[1025][1025],sir[1024];
int main(){
    int i,max,j,nrcol,nrlin,n,lin,col;
    FILE *fin,*fout;
    fin=fopen("cmlsc.in","r");
    fout=fopen("cmlsc.out","w");
    fscanf(fin,"%d%d",&nrlin,&nrcol);
    for(i=1;i<=nrlin;i++){
        fscanf(fin,"%d",&a[i]);
    }
    for(i=1;i<=nrcol;i++){
        fscanf(fin,"%d",&b[i]);
    }
    max=0;
    for(i=1;i<=nrlin;i++){
        for(j=1;j<=nrcol;j++){
            if(a[i]==b[j]){
                v[i][j]=v[i-1][j-1]+1;
            }else{
                if(v[i-1][j]>v[i][j-1]){
                    v[i][j]=v[i-1][j];
                }else{
                    v[i][j]=v[i][j-1];
                }
            }
            if(v[i][j]>max){
                max=v[i][j];
                lin=i;
                col=j;
            }
        }
    }
    fprintf(fout,"%d\n",max);
    n=0;
    i=lin;
    j=col;
    while((i>0)&&(j>0)){
        if(a[i]==b[j]){
            sir[n]=a[i];
            n++;
            i--;
            j--;
        }else{
            if(v[i-1][j]<v[i][j-1]){
                j--;
            }else{
                i--;
            }
        }
    }
    for(i=n-1;i>=0;i--){
        fprintf(fout,"%d ",sir[i]);
    }
    fprintf(fout,"\n");
    fclose(fin);
    fclose(fout);
    return 0;
}
