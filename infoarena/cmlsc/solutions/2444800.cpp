#include <fstream>
#include <algorithm>

using namespace std;
int m[1030][1030];
int main()
{
	ifstream cin("cmlsc.in");
	ofstream cout("cmlsc.out");

	char c;
    int i,j,n,k,cnt=0,h=0;
    cin>>n>>k;
    i=n+1;
    j=k+1;
    char b[j],a[i],l[1030];
    for(int r=0;r<i-1;r++)
    {
		cin>>c;
		a[r+1]=c;
    }
    for(int r=0;r<j-1;r++)
    {
		cin>>c;
		b[r+1]=c;
    }
    reverse(a,a+i);
    reverse(b,b+j);


    for(int r=1;r<i;r++)
    {
		for(int c=1;c<j;c++)
		{
			if(a[r-1]==b[c-1])
			{
				m[r][c]=m[r-1][c-1]+1;
			}
			else
			{
				if(m[r-1][c]>m[r][c-1])
					m[r][c]=m[r-1][c];
				else
					m[r][c]=m[r][c-1];
			}
		}
    }
	i--;
	j--;
	i--;
	j--;
    while(i>=0 && j>=0)
    {
		if(a[i]==b[j])
		{
			l[h]=a[i];
			cnt++;
			h++;
			i--;
			j--;
		}
		else if(m[i-1+1][j+1]==m[i+1][j+1]) i--;
		else if(m[i+1][j-1+1]==m[i+1][j+1]) j--;
    }

    cout<<cnt<<'\n';

    for(int z=0;z<h;z++)
    {
		cout<<l[z]<<" ";
    }

    return 0;
}
