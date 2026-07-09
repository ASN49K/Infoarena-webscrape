#include <fstream>
int C[1030][1030],X[1030],Y[1030],V[1030];
using namespace std;
int main()
{	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");
	int n,m,i,j;
	in>>n>>m;
	for(i=1;i<=n;i++)
		in>>X[i];
	for(j=1;j<=m;j++)
		in>>Y[j];
		
	
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(X[i]==Y[j])
				C[i][j]=C[i-1][j-1]+1;
			else if(C[i][j-1]>C[i-1][j-1])
				C[i][j]=C[i][j-1];
			else
				C[i][j]=C[i-1][j];
				
	out<<C[n][m]<<"\n";
	i=n;j=m;
	while(i>0 && j>0)
		if(X[i]==Y[j])
			{V[C[i][j]]=X[i];i--;j--;}
		else if(C[i][j-1] > C[i-1][j])
			j--;
		else i--;
	
	for(i=1;i<=C[n][m];i++)
	out<<V[i]<<" ";
	
	in.close();
	out.close();
	return 0;
}
