#include <cstdio>

using namespace std;

int main()
{
    FILE *f = fopen("cmlsc.in","r");
    FILE *g = fopen("cmlsc.out","w");
    int n,m;
    int a[1000],b[1000],poz[1000],ord[1000];
    fscanf(f,"%d %d",&n,&m);
    for(int i=0;i<n;i++)
        fscanf(f,"%d",&a[i]);
    for(int i=0;i<m;i++)
        fscanf(f,"%d",&b[i]);
    for(int i=0;i<n;i++)
    {
        poz[i] = -1;
        ord[i] = -1;
        for(int j=0;j<m;j++)
        {
            if(a[i] == b[j])
            {
                poz[i] = j;
            }
        }
    }
    ord[0] = 1;
    for(int i=1;i<n;i++)
    {
        int j = i;
        if(poz[i] != -1)
        {
            while(poz[j-1] == -1 && j-1 >= 0)
                j--;
            while(poz[i] < poz[j-1] && j-1 >= 0)
            {
                j--;
            }
            ord[i] = ord[j-1] + 1;
        }
    }
    int nr=0,i=0,j=0,k=0,rez[1000];
    while(ord[i] == -1)
        i++;
    rez[j] = ord[i];
    for(i=i+1;i<n;i++)
    {
        if(ord[k] + 1 == ord[i])
        {
            k = i;
            rez[++j] = a[i];
        }
    }
    nr = j+1;
    fprintf(g,"%d\n",nr);
    for(int i=0;i<nr;i++)
        fprintf(g,"%d ",rez[i]);
    return 0;
}
