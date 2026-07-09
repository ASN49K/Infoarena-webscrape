#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

FILE *in,*out;

//definitii
#define pb push_back

//constante
const int Nmax=1025;
const int Mmax=1025;

//variabile
int nElem,mElem;
int a[Nmax],b[Mmax];
int best[Nmax][Mmax];
vector<int> answer;

int main(void)
{
	in=fopen("cmlsc.in","rt");
	out=fopen("cmlsc.out","wt");
	
	fscanf(in,"%d%d",&nElem,&mElem);
	
	for(int i=1 ; i<=nElem ; ++i)
		fscanf(in,"%d",&a[i]);
	
	for(int i=1 ; i<=mElem ; ++i)
		fscanf(in,"%d",&b[i]);
	
	for(int i=1 ; i<=nElem ; ++i)
		for(int j=1 ; j<=mElem ; ++j)
			if(a[i] == b[j])
				best[i][j] = best[i-1][j-1] + 1;
			else
				best[i][j] = max(best[i-1][j], best[i][j-1]);
			
	int i=nElem;
	int j=mElem;

	while(i && j)
	{
		if(a[i] == b[j])
		{
			answer.pb(a[i]);
			i--;
			j--;
		}
		else
			if(best[i][j-1] <= best[i-1][j])
				i--;
			else
				j--;
	}
	
	fprintf(out,"%d\n",answer.size());
	vector<int> :: iterator it,end=answer.end();
	for(it=answer.begin() ; it!=end ; ++it)
		fprintf(out,"%d ",*it);
	
	fclose(in);
	fclose(out);
	return 0;
}
