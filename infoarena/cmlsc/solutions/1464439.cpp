#include <iostream>
using namespace std;

int M,N,mArr[1025],nArr[1025],i,j,table[1025][1025]={0},solution[1025],MAX=0;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    
    cin>>M>>N;
    
    for(i=1;i<=M;++i)	cin>>mArr[i];
    for(j=1;j<=N;++j)	cin>>nArr[j];
    
    for(i=1;i<=M;++i)    
		for(j=1;j<=N;++j)
			if(mArr[i]==nArr[j])	table[i][j]=table[i-1][j-1]+1;
			else	table[i][j]=max(table[i-1][j],table[i][j-1]);
        
    i=M;
    j=N;
    while(i>0 && j>0)
	{
		if(table[i][j]==table[i-1][j-1]+1)
		{
			solution[table[i][j]]=mArr[i];
			++MAX;
			i-=1;
			j-=1;
		}
		else
		{
			if(max(table[i-1][j],table[i][j-1])==table[i-1][j])	i-=1;
			else	j-=1;
		}		
	}
	
	cout<<MAX<<endl;
	i=1;
	while(i<=MAX)
	{
		if(solution[i]>=0)	cout<<solution[i++]<<" ";
		else break;
	}
}

