#include<iostream>
#include<fstream>

using namespace std;

/* Recursivity takes 30 points
int euclid(int x,int y)
{
	if (y == 0)
		return x;
	else
		return euclid(y, x%y);
}
*/

int euclid(int x, int y)
{
	int r = 0;
	while(y != 0)
	{
		r = y;
		y = x%y;
		x = r;
	}
	return x;
}

int main(int argc, char** argv)
{
	int nrPerechi;
	int a,b;
	
	/*
	ifstream in;
	ofstream out;
	
	in.open("euclid2.in");
	out.open("euclid2.out");
	in >> nrPerechi;
	*/
	
	FILE* f;
	FILE* g;
	f = fopen("euclid2.in","r");
	g = fopen("euclid2.out","w");
	
	fscanf(f,"%d",&nrPerechi);
	
	for (int i = 0; i < nrPerechi; i++)
	{
		fscanf(f,"%d",&a);
		fscanf(f,"%d",&b);

		//out << euclid(a,b) << endl;
		fprintf(f,"%d\n",euclid(a,b));
	}
	
	fclose(f);
	fclose(g);
	//in.close();
	//out.close();
	
	return 0;
}
