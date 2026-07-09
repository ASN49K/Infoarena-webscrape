#include<fstream>
#include<vector>
using namespace std;
int main()
{
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n,m;
vector<int> x,y;
if(in && !in.eof() && in>>n>>m)
{
  int i=0,t;
   for(i=0; in && i<n && in>>t; ++i)
     x.push_back(t);
   for(i=0; in && i<m && in>>t; ++i)
     y.push_back(t);
   
}
vector< vector<int> > c(m+1 , vector<int>(n+1,0));
for(int i=1;i<=m;++i)
	for(int j=1;j<=n;++j)
	{
	  if(x[i-1]==y[j-1])
	  {
	    c[i][j]=c[i-1][j-1]+1;
		continue;  
	  };		  
	  if(c[i-1][j]>=c[i][j-1])
	  {
	   c[i][j]=c[i-1][j];
	  } else {
	            c[i][j]=c[i][j-1];
	         }
     }
int ll=m , cc=n;
vector<int> v;
while(ll || cc)
{
	 if(ll && cc && x[ll-1]==y[cc-1])
	 {
	   v.push_back(x[ll-1]);
       --ll; --cc;
       continue;	   
	 }
	  if(ll && c[ll][cc]==c[ll-1][cc])
	  {
		  ll--;
          continue;		  
	  }
	   	  if(cc && c[ll][cc]==c[ll][cc-1])
	  {
		  cc--;          	  
	  }
}
out<<c[m][n]<<endl;
vector<int>::reverse_iterator rit;
for(rit=v.rbegin();rit!=v.rend();++rit)
{
  out<<*rit<<" ";	
}
return 0;
}