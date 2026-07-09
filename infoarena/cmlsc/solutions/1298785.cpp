#include <fstream>

using namespace std;

 ifstream x ("cmlsc.in");
 ofstream y ("cmlsc.out");

 int n,m;
 int a[1025],b[1025];
 int map[1025][1025];

int main()
{
    int i,j;

    x>>n>>m;

    for(i=1;i<=n;i++)
       x>>a[i];

    for(j=1;j<=m;j++)
    x>>b[j];

    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
          if(a[i]==b[j])
             map[i][j]=map[i-1][j-1]+1;
          else
             map[i][j]=max(map[i-1][j],map[i][j-1]);

/*
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
           y<<map[i][j]<<' ';
        y<<'\n';
    }
    y<<'\n';
*/

    y<<map[n][m]<<'\n';

    i=n;
    j=m;
    while(map[i][j]!=0)
    {
        bool flag=true;

        while(flag==true)
        {
            flag=false;

            if(map[i][j]==map[i-1][j])
            {
                i--;
                flag=true;
            }

            if(map[i][j]==map[i][j-1])
            {
                j--;
                flag=true;
            }
        }

        y<<a[i]<<' ';

        i--;
        j--;
    }

    return 0;
}
