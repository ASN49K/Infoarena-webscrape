#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int rez,maxim,a,b;
int valoare,pozitie;
int arb[400050];

void search(int nod,int left,int right)
{
	if(a<=left && right<=b)
	{
		//cout<<left<<" "<<right<<endl;
		maxim+=arb[nod];
		return;
	}
	int mij=(left+right)/2;

	if(a<=mij) search(2*nod,left,mij);
	if(mij < b) search(2*nod+1,mij+1,right);
	
	return;
}
void update(int nod,int left,int right)
{
	if(left==right)
	{
		++arb[nod];
		return;
	}
	
	int mij=(left+right)/2;
	if(pozitie<=mij) update(2*nod,left,mij);
		else update(2*nod+1,mij+1,right);
		
	arb[nod]=arb[2*nod]+arb[2*nod+1];
	return;
}


int main()
{
	int n,x;
	long long S=0;
	freopen("costperm.in","r", stdin);
	freopen("costperm.out","w", stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{	
		scanf("%d",&x);
		
		valoare=x;
		maxim=0;
		
		a=x+1;// limita stanga
		b=n; // limita dreapta
		search(1,1,n);
			
		S+=maxim*x;
		
		pozitie=x;	 // practic numarul ii pozitia pentru intervale	
		
		update(1,1,n);
		
	}
	printf("%lld",S);

	return 0;
}
