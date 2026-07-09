#include <fstream>
 
using namespace std;
 
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int a[1051],b[1051],maxi[1051][1051],n,m,k;

void afis(int x,int y,int k){
	while(a[x] != b[y])	if(maxi[x][y-1] >= maxi[x-1][y] && x > 0 && y > 0) y--;else x--;
	if(x == 0 || y == 0){
		cout << k << '\n';
		return;
	} 
	afis(x-1,y-1,k+1);
	cout << a[x] << ' ';
}

int main()
{

 cin>>n>>m;
	for(int i=1;i<=n;i++)	
		cin>>a[i];
	
	
for(int i=1;i<=m;i++) 
  	cin>>b[i];
  	
 	int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j]) maxi[i][j]=maxi[i-1][j-1]+1;
            	else if (maxi[i-1][j]>=maxi[i][j-1])
            				maxi[i][j]=maxi[i-1][j];
            			else maxi[i][j]=maxi[i][j-1];
            			
 /* for(i=1;i<=n;i++)
  {
        for(j=1;j<=n;j++)
        	cout<<maxi[i][j]<<" ";
	 cout<<endl; 
	 
	}*/
	//cout<<"Cel mai lung subsir polindrom este: ";
	afis(n,n,0);  
    return 0;
}
