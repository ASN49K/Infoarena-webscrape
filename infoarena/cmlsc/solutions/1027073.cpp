#include <stdio.h>
using namespace std;
FILE * fin=fopen("cmlsc.in","r");
FILE * fout=fopen("cmlsc.out","w");
int x[1200],y[1200];
int mat[1200][1200];
 int h=0,st[5000],k,i1,j1;
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


/*fprintf(fout,"  ");
    for(j=1;j<=l2;j++) fprintf(fout,"%d ",y[j]);
    fprintf(fout,"\n");
    for(i=1;i<=l1;i++){
        fprintf(fout,"%d ",x[i]);
        for(j=1;j<=l2;j++){
            fprintf(fout,"%d ",mat[i][j]);}
            fprintf(fout,"\n");}

*/

 fprintf(fout,"%d\n",mat[l1][l2]);
    i=l1;j=l2;
    int ok=1,l=0;
    while (mat[i][j]!=0)
    {
        if (x[i]==y[j])
        {
            l++;
            st[l]=x[i];
            i--; j--;
        }
        else
        {
            if (mat[i-1][j]>=mat[i][j-1]) i--;
            else j--;
        }
    }
    for (i=l;i>0;i--)
    {
        fprintf(fout,"%d ",st[i]);
    }




    return 0;

}



