#include <fstream>
#include <vector>
#include <cstdio>

using namespace std;

vector<int> sir;
int n,m,i,j;
short mat[1027][1027];

fstream f,g;

int main()
{
	int maxim=1;
    f.open("cmlsc.in",ios::in);
    g.open("cmlsc.out",ios::out);
    f >> m >> n;
	for(i=2;i<m+2;i++)
		f >> mat[i][0];
	for(i=2;i<n+2;i++)
		f >> mat[0][i];
	bool fl;
	
	for(i=2;i<m+2;i++)
	  { fl=false;
	    for(j=2;j<n+2;j++)
		  if(mat[i][0]==mat[0][j])
			{fl=true;mat[i][j] = maxim;break;}
	   if(fl==true) maxim++;	
	}

	
	int mix = 1;
	int pos = 2;
	for(i=2;i<m+2;i++)
	    for(j=pos;j<n+2;j++)
		   if(mat[i][j] == mix)
		   {
			   pos=j+1;
			   sir.push_back(mat[0][j]);
			   mix++;
			   break;
		   }
		
	
	g << sir.size() << "\n";
    for(i=0;i<sir.size();i++)
       g << sir[i] << " " ;		
    g.close();
    return 0;
}
