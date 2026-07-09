#include <fstream.h>

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int n, v[1024], w[1024], m, mat[1024][1024], sir[1024], aux;

void read()
{    f >> n >> m;
     for (int i=1; i<=n; i++)
	 f >> v[i];
     for (int j=1; j<=m; j++)
	 f >> w[i];
}

void program()
{    for (int i=1; i<=n; i++)
	 for (int j=1; j<=m; j++)
	     if (v[i]==w[i])
		mat[i][j]++;
	     else if (mat[i-1][j]>mat[i][j-1]) mat[i][j]=mat[i-1][j];
		  else mat[i][j]=mat[i][j-1];
     i=n;
     int j=m;
     while (i && j)
     {     if (v[i]==w[j])
	   {  sir[++aux]=v[i];
	      i--;
	      j--;
	   }
	   else if (mat[i][j-1]>mat[i-1][j])
		   j--;
		else i--;
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


