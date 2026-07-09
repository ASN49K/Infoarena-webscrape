using namespace std;
#include<fstream>
#include<iostream>


int a[1025][1025], arr1[1025], arr2[1025],m,n;
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");

int max3(int a, int b, int c)
{
	if(a>b)
		if(a>c)
			return a;
		else
			return c;

	if(b<c)
		return c;
	return b;
}

void initialize()
{

	int i;

	if(arr1[0] == arr2[0])
		a[0][0] = 1;

	for(i=1; i<m;i++)
		if(arr1[i] == arr2[0])
			a[i][0] = a[i-1][0] + 1;
		else
			a[i][0] = a[i-1][0];

	for(i=1; i<n;i++)
		if(arr2[i] == arr1[0])
			a[0][i] = a[0][i-1] + 1;
		else
			a[0][i] = a[0][i-1];

}


void findSol(int i, int j)
{
	if(i>=0 && j>=0)
	{

    if (arr1[i] == arr2[j])
	{
		findSol(i-1, j-1);
		g<<arr1[i]<<' ';
	}
	else 
	if (a[i-1][j] < a[i][j-1])
		findSol(i,j-1);
	else
        findSol(i-1,j);
	}
}


int main()
{


	int i,j;

	f>>m>>n;

	for(i=0;i<m;i++)
		f>>arr1[i];

	for(i=0;i<n;i++)
		f>>arr2[i];

	initialize();

	for(i=1;i<m;i++)
		for(j=1;j<n;j++)
			if(arr1[i] == arr2[j])
				a[i][j] = a[i-1][j-1] + 1;
			else
				a[i][j] = max3(a[i-1][j-1], a[i-1][j], a[i][j-1]);



	g<<a[m-1][n-1]<<endl;

	findSol(m-1,n-1);


		return 0;
}