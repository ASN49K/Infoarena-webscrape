#include<fstream>
#define g 1026
using namespace std;
int c[g][g]={0},n,m;
ifstream be ("cmlsc.in");
ofstream ki ("cmlsc.out");
void read (int a[], int b[], int &n, int &m)
 {
  int i;
  be>>n>>m;
  for (i=1;i<=n;i++)
     be>>a[i];
  for (i=1;i<=m;i++)
     be>>b[i];
  be.close();
 }

int program (int a[], int b[])
 {
  int i,j;
  for (i=n;i>=1;i--)
    for (j=m;j>=1;j--)
       if (a[i]==b[j])
	 c[i][j]=c[i+1][j+1]+1;
       else
	  if (c[i][j+1]>c[i+1][j])
	    c[i][j]=c[i][j+1];
	  else
	    c[i][j]=c[i+1][j];
  return c[1][1];
 }

void road (int a[], int b[])
 {
  int i=1,j=1,sz=0;
    while (i<=n && j<=m)
	if (a[i]==b[j])
	  { ki<<a[i]; sz++;
	    if (sz<c[1][1])
	      ki<<" "; i++; j++; }
	else
	  if (c[i][j+1]==c[i][j])
	    j++;
	  else
	    i++;
 }


int main()
 {
  int a[g]={0},b[g]={0};
  read (a,b,n,m);
  ki<<program (a,b);
  ki<<"\n";
  road (a,b);
  ki<<"\n";
  ki.close();
  return 0;
 }
