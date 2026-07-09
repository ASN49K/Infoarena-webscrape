#include <fstream>
using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int n, v[1024], w[1024], m, mat[1024][1024], sir[1024], aux;

void read()
{    f >> n >> m;
     for (int i=1; i<=n; i++)
	 f >> v[i];
     for (int j=1; j<=m; j++)
	 f >> w[j];
}

void program()
{    for (int i=1; i<=n; i++)
	 for (int j=1; j<=m; j++)
	     if (v[i]==w[i])
		mat[i][j]=mat[i-1][j-1]+1;
	     else if (mat[i-1][j]>mat[i][j-1]) mat[i][j]=mat[i-1][j];
		  else mat[i][j]=mat[i][j-1];
     for (int ii=n, int jj=m; ii;)
     {     if (v[ii]==w[jj])
	   {  sir[++aux]=v[ii];
	      ii--;
	      jj--;
	   }
	   else if (mat[ii][jj-1]>mat[ii-1][jj])
		   jj--;
		else ii--;
     }
     g << aux;
     for (int k=1; k>=1; k++)
	 g << v[k] << " ";
}

int main()
{   read();
    program();
    return 0;
}


