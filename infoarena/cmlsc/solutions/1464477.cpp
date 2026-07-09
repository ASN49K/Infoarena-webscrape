#include <iostream>
using namespace std;
 
int M,N,mArr[1025],nArr[1025],i,j,table[1025][1025]={0},solution[1025],MAX=0;
 
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
     
    cin>>M>>N;
     
    for(i=1;i<=M;++i)    cin>>mArr[i];
    for(j=1;j<=N;++j)    cin>>nArr[j];
     
    for(i=1;i<=M;++i)    
        for(j=1;j<=N;++j)
            if(mArr[i]==nArr[j])	table[i][j]=table[i-1][j-1]+1;
            else    table[i][j]=max(table[i-1][j],table[i][j-1]);
    
    i=M;
    j=N;
    while(i>0 && j>0)
    {
		if(mArr[i]==nArr[j])
        {
            solution[table[i][j]-1]=mArr[i];
            ++MAX;
            i-=1;
            j-=1;
        }
        else	(table[i-1][j]>table[i][j-1]?--i:--j);	
     
    }
    
    cout<<MAX<<endl;
//    
////    i=M;
////    j=N;
////    while(i>0 && j>0)
////	{
////		if(mArr[i]==nArr[j])
////		{
//			solution[MAX-1]=mArr[i];
//			--MAX;
////			i-=1;
////			j-=1;
////		}
////		else
////			(table[i-1][j]>table[i][j-1]?--i:--j);	
////	}
//     
    i=0;
    while(i<MAX)	cout<<solution[i++]<<" ";

}

