#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int l1,l2,v1[1025]={},v2[1025]={},tab[1025][1025]={},cmlsc[1025]={},lenght=0;

void Read()
{
	in>>l1>>l2;
	
	for(int i=1;i<=l1;i++)
		in>>v1[i];
	
	for(int i=1;i<=l2;i++)
		in>>v2[i];
}

int main()
{
	Read();

	for(int i=1;i<=l1;i++)
		for(int j=1;j<=l2;j++)
			if(v1[i]==v2[j])
				tab[i][j]=1+tab[i-1][j-1];
			else
				tab[i][j]=max(tab[i-1][j],tab[i][j-1]);
	
	for(int i=l1,j=l2;i>0,j>0;)
	{
		if(v1[i]==v2[j])
		{
			lenght++;
			cmlsc[lenght]=v1[i];
			i--;
			j--;
		}
		else if(tab[i][j-1]<tab[i-1][j])
			i--;
		else
			j--;
	}
	
	out<<lenght<<'\n';
	
	for(int i=lenght;i>0;i--)
		out<<cmlsc[i]<<' ';

	return 0;
}