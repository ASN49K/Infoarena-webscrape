#include <stdio.h>
#include <stdlib.h>
int mat[1025][1025],s1[1024],s2[1024],v[1024];
int main()
{
    FILE *fin,*fout;
    int n,m,l,c,i;
    fin=fopen("cmlsc.in","r");
    fscanf(fin,"%d%d",&m,&n);
    for(i=0;i<m;i++){
      fscanf(fin,"%d",&s1[i]);
    }
    for(i=0;i<n;i++){
      fscanf(fin,"%d",&s2[i]);
    }
    fclose(fin);
    for(l=1;l<=m;l++){
      for(c=1;c<=n;c++){
        if(s1[l-1]==s2[c-1]){
          mat[l][c]=mat[l-1][c-1]+1;
        }else{
          if(mat[l-1][c]>mat[l][c-1]){
            mat[l][c]=mat[l-1][c];
          }else{
            mat[l][c]=mat[l][c-1];
          }
        }
      }
    }
    l=m;
    c=n;
    i=0;
    while((0<l)&&(0<c)){
      if(s1[l-1]==s2[c-1]){
        v[i]=s1[l-1];
        i++;
        l--;
        c--;
      }else{
        if(mat[l-1][c]>mat[l][c-1]){
          l--;
        }else{
          c--;
        }
      }
    }
    fout=fopen("cmlsc.out","w");
    fprintf(fout,"%d\n",mat[m][n]);
    for(i=i-1;0<=i;i--){
      fprintf(fout,"%d ",v[i]);
    }
    fclose(fout);
    return 0;
}
