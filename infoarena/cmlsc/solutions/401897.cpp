#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdio>
#define MAX(a,b,c) max(a,max(b,c))
#define m(i,j) mat[i][j]
#define for(i,a,b) for(i=a;i<b;i++)

using namespace std;
int mat[1027][1027];
int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	vector<int> sir;
	int maxim;
	int i,j,m,n;
	memset(mat,0,sizeof(mat));
	f >> n;
	f >> m;
	for(i,2,n+2)
		f >> m(i,0);
    for(i,2,m+2)
		f >> m(0,i);
    for(i,2,n+2)
        for(j,2,m+2)
        {
           if(m(i,0)==m(0,j)) m(i,j)++;
		   m(i,j)+= MAX(m(i,j-1),m(i-1,j-1),m(i-1,j));
		}			
	

maxim = 1;
	for(i,2,n+2)
		for(j,2,m+2)
			if(m(i,j) == maxim&&
			   m(i,j)>m(i-1,j)&&
			   m(i-1,j)==m(i-1,j-1)&&
               m(i-1,j)==m(i,j-1)
               )
              sir.push_back(m(i,0)),maxim++;
     int len = sir.size();
	 g << len << "\n";
    for(i,0,len)
        g << sir[i] << " ";
	g.close();
    return 0;   	
}
