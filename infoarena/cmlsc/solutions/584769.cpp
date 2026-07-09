#include <fstream>
#define maxim(a,b) ((a > b) ? a : b)
using namespace std;
fstream f("cmlsc.in",ios::in),g("cmlsc.out",ios::out);

short a[1025],b[1025];
short n,m;
short maxs[1025][1025];
short drum[1025];



int main()
{
	short max,k;
	f>>n>>m;
	for(int i=1;i<=n;++i)
		f>>a[i];
	for(int i=1;i<=m;++i)
		f>>b[i];
	k=0;
	max=0;
	
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(a[i]==b[j])
			
				maxs[i][j]=maxs[i-1][j-1]+1;
				
			else
				maxs[i][j] = maxim(maxs[i-1][j],maxs[i][j-1]);
			
		}
		int i=n,j=m;
		while( i && j)
        if (a[i] == b[j])
            drum[++max] = a[i], --i, --j;
        else if (maxs[i-1][j] < maxs[i][j-1])
            --j;
        else
            --i;
		
		g<<max<<'\n';
		for(i=max;i;--i)
			g<<drum[i]<<' ';
		return 0;
}

					
				
				
			