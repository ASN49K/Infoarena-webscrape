#include<stdio.h>

int a[1024],b[1024],val[1024][1024],res[1024],p;

int main()
{
    FILE *fin,*fout;
    fin=fopen("cmlsc.in","r");
    fout=fopen("cmlsc.out","w");

    int n,m;
    fscanf(fin,"%d %d",&n,&m);

    for(int i=0;i<n;i++)
    {
        fscanf(fin,"%d",&a[i]);
    }

    for(int i=0;i<m;i++)
    {
        fscanf(fin,"%d",&b[i]);
    }

    if(a[0]==b[0])
    {
        val[0][0]=1;
    }

    for(int i=1;i<n;i++)
    {
        if(a[i]==b[0])
        {
            val[i][0]=val[i-1][0]+1;
        }
        else
        {
            val[i][0]=val[i-1][0];
        }
    }

    for(int i=1;i<m;i++)
    {
        if(b[i]==a[0])
        {
            val[0][i]=val[0][i-1]+1;
        }
        else
        {
            val[0][i]=val[0][i-1];
        }
    }

    p=0;

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(val[i][j-1]>=val[i-1][j])
            {
                if(a[i]==b[j])
                {
                    val[i][j]=val[i][j-1]+1;
                }
                else
                {
                    val[i][j]=val[i][j-1];
                }
            }
            else
            {
                if(a[i]==b[j])
                {
                    val[i][j]=val[i-1][j]+1;
                }
                else
                {
                    val[i][j]=val[i-1][j];
                }
            }
        }
    }

    int x=n-1,y=m-1;

    while(1)
    {
        //fprintf(fout,"%d %d\n",x,y);
        if(x==0&&y>0&&val[x][y-1]<val[x][y])
        {
            res[p]=a[x];
            p++;
            x--;
            y--;
        }
        else if(y==0&&x>0&&val[x-1][y]<val[x][y])
        {
            res[p]=a[x];
            p++;
            x--;
            y--;
        }
        else if(x>0&&y>0&&val[x][y]>val[x-1][y]&&val[x][y]>val[x][y-1])
        {
            res[p]=a[x];
            p++;
            x--;
            y--;
        }
        else if(x==0&&x==y&&val[x][y]!=0)
        {
            res[p]=a[x];
            p++;
            x--;
            y--;
        }
        else if((x>0&&y>0&&val[x-1][y]>=val[x][y-1])||y==0)
        {
            x--;
        }
        else if((x>0&&y>0&&val[x-1][y]<=val[x][y-1])||x==0)
        {
            y--;
        }
        if(y<0&&x<0)
        {
            break;
        }
    }

    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            fprintf(fout,"%d ",val[i][j]);
        }
        fprintf(fout,"\n");
    }*/

    fprintf(fout,"%d\n",p);
    for(int i=p-1;i>=0;i--)
    {
        fprintf(fout,"%d ",res[i]);
    }
}
