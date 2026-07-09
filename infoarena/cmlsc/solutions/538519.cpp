#include<stdio.h>
#include<vector>

FILE* f;
FILE* ff;
int* a;
int* b;
int m,n;

void init()
{
	f=fopen("cmlsc.in","r");
	fscanf(f,"%d%d",&m,&n);
	a=new int [m];
	b=new int [n];
	for (int i=0;i<m;i++)
		fscanf(f,"%d",&a[i]);
	for (int i=0;i<n;i++)
		fscanf(f,"%d",&b[i]);
	ff=fopen("cmlsc.out","w");
}

/*
void afisare()
{
	fprintf(ff,"%d %d \n",m,n);
	for (int i=0;i<m;i++)
		fprintf(ff,"%d ",a[i]);
	fprintf(ff,"\n");
	for (int i=0;i<n;i++)
		fprintf(ff,"%d ",b[i]);
}
*/

int max(int x,int y)
{
	return x>y?x:y;
}
void calculeaza()
{
	using std::vector;
	vector<vector<int> > c(m+1,vector<int>(n+1,0));
	int i,j;

	for ( i = 1 ; i <= m ; i++ )
		for ( j = 1 ; j <= n ; j++ )
		{
			if (a[i-1]==b[j-1]) c[i][j] = c[i-1][j-1] + 1;
			else c[i][j] = max(c[i][j-1], c[i-1][j]);
		}

	int linie,coloana;
	linie = m;
	coloana = n;
	vector<int> v;
		while ( linie || coloana )
		{
			if ( linie-1 && coloana-1 && a[linie-1] == b[coloana-1])
			{
				v.push_back(a[linie-1]);
				linie--;
				coloana--;
				continue;
			}
			if ( linie-1 && c[linie][coloana] == c[linie-1][coloana] )
			{
				linie--;
				continue;
			}
			if ( coloana-1 && c[linie][coloana] == c[linie][coloana-1] )
			{
				coloana--;
				continue;
			}
		}

		fprintf(ff,"%d\n",c[m][n]);
		vector<int>::reverse_iterator revIter;
		for (revIter=v.rbegin();revIter!=v.rend();revIter++)
		{
			fprintf(ff,"%d ",*revIter);
		}
}

int main()
{
	init();

	//afisare();
	calculeaza();

	fclose(f);
	fclose(ff);

	return 0;
}
