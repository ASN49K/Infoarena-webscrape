#include<stdio.h>

int a[1025],b[1025],val[1025][1025],res[1024],p;

int main()
{
    FILE *fin,*fout;
    fin=fopen("cmlsc.in","r");
    fout=fopen("cmlsc.out","w");

    int n,m;
    fscanf(fin,"%d %d",&n,&m);

    for(int i=1;i<=n;i++)
    {
        fscanf(fin,"%d",&a[i]);
    }

    for(int i=1;i<=m;i++)
    {
        fscanf(fin,"%d",&b[i]);
    }

    for(int i=0;i<=n;i++)
    {
        val[i][0]=0;
    }

    for(int i=0;i<=m;i++)
    {
        val[0][i]=0;
    }

    p=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                val[i][j]=val[i-1][j-1]+1;
            }
            else if(val[i-1][j]>val[i][j-1])
            {
                val[i][j]=val[i-1][j];
            }
            else
            {
                val[i][j]=val[i][j-1];
            }
        }
    }

    int x=n,y=m;

    while(1)
    {
        //fprintf(fout,"%d %d\n",x,y);
        if(x==1&&y==1)
        {
            if(val[x][y]!=0)
            {
                //fprintf(fout,"*\n");
                res[p]=a[x];
                p++;
                break;
            }
            else
            {
                break;
            }
        }
        else if(x==1&&y>1)
        {
            if(val[x][y-1]<val[x][y])
            {
                //fprintf(fout,"*\n");
                res[p]=a[x];
                p++;
            }
            y--;
        }
        else if(x>1&&y==1)
        {
            if(val[x-1][y]<val[x][y])
            {
                //fprintf(fout,"*\n");
                res[p]=a[x];
                p++;
            }
            x--;
        }
        else if(x>1&&y>1)
        {
            if(val[x][y]>val[x-1][y]&&val[x][y]>val[x][y-1])
            {
                //fprintf(fout,"*\n");
                res[p]=a[x];
                p++;
            }
            if(val[x-1][y]==val[x][y-1]&&val[x-1][y]==val[x-1][y-1])
            {
                x--;
                y--;
            }
            else if(val[x-1][y]>=val[x][y-1]&&val[x-1][y]>val[x-1][y-1])
            {
                x--;
            }
            else if(val[x][y-1]>val[x-1][y]&&val[x][y-1]>val[x-1][y-1])
            {
                y--;
            }
        }
    }

    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            fprintf(fout,"%d ",val[i][j]);
        }
        fprintf(fout,"\n");
    }*/

    fprintf(fout,"%d\n",p-1);
    for(int i=p-1;i>0;i--)
    {
        fprintf(fout,"%d ",res[i]);
    }
}
