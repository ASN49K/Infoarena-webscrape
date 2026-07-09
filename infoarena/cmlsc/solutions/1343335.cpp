#include<stdio.h>
#include<vector>

using namespace std;

FILE *in, *out;

//definitions
#define max(x,y) ((x)>(y) ? (x) : (y))
#define pb push_back

//constants
const int sz = 1024;

//variables
int m, n;
int a[sz];
int b[sz];
int lcs[sz][sz];

vector<int> answer;

//functions

int main(void)
{
	in = fopen("cmlsc.in", "rt");
	out = fopen("cmlsc.out", "wt");
	
	fscanf(in, "%d%d", &m, &n);
	
	for(int i=1; i<=m; ++i)
		fscanf(in, "%d", &a[i]);
	for(int i=1; i<=n; ++i)
		fscanf(in, "%d", &b[i]);
	
	for(int i=m; i>=1; --i)
		for(int j=n; j>=1; --j)
			if(a[i] == b[j])
				lcs[i][j] = 1 + lcs[i+1][j+1];
			else
				lcs[i][j] = max(lcs[i+1][j], lcs[i][j+1]);
				
	
	fprintf(out,"%d\n", lcs[1][1]);
	
	int i=1, j=1;
	
	while( i<=m)
	{
		if(a[i] == b[j])
		{
			answer.pb(a[i]);
			i++;
			j++;
		}
		else
			if( lcs[i][j+1] >= lcs[i+1][j])
				j++;
			else
				i++;
	}
	
	vector<int> :: iterator it, end=answer.end();
	
	for(it = answer.begin(); it!=end; ++it)
		fprintf(out, "%d ", *it);
	
	fclose(in);
	fclose(out);
	return 0;	
}
