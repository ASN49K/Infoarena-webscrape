#include <iostream>
#include <string>
using namespace std;

int M,N,mArr[1025],nArr[1025],i,j,table[1025][1025]={0},MAX=0,temp;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    
    cin>>M>>N;
    
    for(i=1;i<=M;++i)	cin>>mArr[i];
    for(j=1;j<=N;++j)	cin>>nArr[j];
    
    for(i=1;i<=M;++i)    
		for(j=1;j<=N;++j)
			if(mArr[i]==nArr[j])
			{
				table[i][j]=table[i-1][j-1]+1;
				++MAX;	
			}	
			else	table[i][j]=max(table[i-1][j],table[i][j-1]);
    cout<<MAX<<endl;
    temp=MAX;
    
	int solution[MAX];
    
    i=M;
    j=N;
    while(i>0 && j>0)
	{
		if(mArr[i]==nArr[j])
		{
			solution[MAX-1]=mArr[i];
			--MAX;
			i-=1;
			j-=1;
		}
		else
			(table[i-1][j]>table[i][j-1]?--i:--j);	
	}
	
	i=0;
	while(i<temp)	cout<<solution[i++]<<" ";
}

