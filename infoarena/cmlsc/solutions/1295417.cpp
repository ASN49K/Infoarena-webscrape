#include<fstream>
using namespace std;
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int n,m,i,j,a[1024],b[1024],c[1024],ma=0,p,d[1024],x=0,p2;
    f>>n>>m;
    for(i=0;i<n;i++)
        f>>a[i];
    for(j=0;j<m;j++)
        f>>b[j];
    i=0;
    while(i<n)
    {
        j=0;
        while(j<m&&a[i]!=b[j])j++;
        if(a[i]==b[j]&&j<m)
        {
            p2=i;
            ma=0;
            c[ma++]=a[i];
            p=j+1;
            i++;
            while(i<n&&p<m)
            {
                j=p;
                while(j<m&&a[i]!=b[j])j++;
                if(a[i]==b[j]&&j<m)
                {
                    c[ma++]=a[i];
                    p=j+1;
                }
                i++;
            }
            if(ma>x)
            {
                x=ma;
                for(int k=0;k<x;k++)
                    d[k]=c[k];
            }
            i=p2;
        }
        i++;
    }
    g<<x<<"\n";
    for(int k=0;k<x;k++)
        g<<d[k]<<" ";
    f.close();
    g.close();
    return 0;
}
