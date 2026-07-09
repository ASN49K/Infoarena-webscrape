#include <iostream>
#include <fstream>
//using namespace std;


int n,m,i,j;
int *a,*b,**mat;	

inline int max(int a, int b)
{
	return a>b?a:b;
}

void afis(ofstream &out, int i, int j)
{
	if(i<=0||j<=0) return;
	if(max(mat[i-1][j],mat[i][j-1])<mat[i][j])
	{		
		afis(out,i-1,j-1);
		out<<b[i]<<" ";
	}
	else 
		if(max(mat[i-1][j],mat[i][j-1])==mat[i-1][j])
			afis(out,i-1,j);
		else afis(out,i,j-1);
}
int main()
{
	
	ifstream in("cmlsc.in");
	in>>m>>n;
	a=new int[m+1];
	b=new int[n+1];
	mat = new int* [m+1];
	for(i=1;i<=m;i++)
	{
		mat[i]= new int[n+1];
		in>>a[i];
	}
	for(j=1;j<=n;j++)
		in>>b[j];
	
	mat[0] = new int[n+1];
	for(i=1;i<=m;i++)
		mat[i][0]=0;

	for(j=1;j<=n;j++)
		mat[0][j]=0;	

	for(i=1;i<=m;i++)
	{		
		for(j=1;j<=n;j++)
		{
			if(a[i]==b[j])
				mat[i][j] = mat[i-1][j-1]+1;
			else
				mat[i][j]= max(mat[i-1][j],mat[i][j-1]);
		}
	}
	ofstream out("cmlsc.out");
	out<<mat[m][n]<<endl;
	afis(out,m,n);
	out.close();

	/*for(i=0;i<=m;i++)
	{
		for (j=0;j<=n;j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	cin>>i;*/
	return 0;
}