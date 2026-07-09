#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int ct,best[1025][1025],a[1025],b[1025],sir[1025];

int main()
{
    int i,j,n,m;
    in>>n>>m;

    for(i=1;i<=n;i++)
        in>>a[i];

    for(i=1;i<=m;i++)
        in>>b[i];

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                best[i][j]=best[i-1][j-1]+1;
            else
                {
                	if(best[i][j-1]>best[i-1][j])
                		best[i][j]=best[i][j-1];
                	else
                		best[i][j]=best[i-1][j];
                	}



    for(i=n,j=m;i;)
    	if(a[i]==b[j])
    		sir[++ct]=a[i],i--,j--;
    	else
    		if(best[i-1][j]>best[i][j-1])
    			i--;
    			else
    				j--;

    out<<best[n][m]<<"\n";

    for(i=best[n][m];i>=1;i--)
    	out<<sir[i]<<" ";

    return 0;
}
