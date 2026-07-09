#include <stdio.h>
using namespace std;
FILE * fin=fopen("cmlsc.in","r");
FILE * fout=fopen("cmlsc.out","w");
int x[1200],y[1200];
int mat[1200][1200];
inline int max(int i,int j)
{
    if(mat[i-1][j]>mat[i][j-1]) return mat[i-1][j];
    return mat[i][j-1];
}
int main()
{
    int l1,l2;
    fscanf(fin,"%d%d",&l1,&l2);
    int i;
    for(i=1;i<=l1;i++) fscanf(fin,"%d",&x[i]);
    for(i=1;i<=l2;i++) fscanf(fin,"%d",&y[i]);

    int j;
    for(i=1;i<=l1;i++){
        for(j=1;j<=l2;j++){
            if(x[i]==y[j]) mat[i][j]=mat[i-1][j-1]+1;
            else mat[i][j]=max(i,j);

        }
    }
    int h=0;
    int st[30000];
    for(i=1;i<=l1;i++){
        for(j=1;j<=l2;j++){
            if(x[i]==y[j]){
                h++;
                st[h]=x[i];
            }



        }
    }
    fprintf(fout,"%d\n",h);
    for(i=1;i<=h;i++) fprintf(fout,"%d ",st[i]);

    return 0;

}



