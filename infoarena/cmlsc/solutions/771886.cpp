#include <iostream>
#include <fstream>
#include <list>
using namespace std;

//#include "../utils/PerformanceTimer.h"

//int pb_001__cmlsc()
int main()
{
	//PerformanceTimer timer;
	//timer.init();
	
	char* in_file = "cmlsc.in";
	char* out_file = "cmlsc.out";

	const int MAX_N = 1024;
	int N1, N2;	
	
	int v1[MAX_N];
	int v2[MAX_N];
	
	ifstream ifs(in_file);
	ifs>>N1>>N2;
	for (int i = 0; i < N1; i++) ifs>>v1[i];
	for (int i = 0; i < N2; i++) ifs>>v2[i];
	ifs.close();

	//cout<<timer.getElapsedTime()<<endl;

	//int* L = new int[(N1+1)*N2];
	int L1[MAX_N][MAX_N];	
	int* L = (int*) L1;
	
	//cout<<timer.getElapsedTime()<<" processing start time"<<endl;

	//DYNAMIC PROGRAMING
	//default initialization
	//L[N1][y] = none; L[x][N2] = none; 
	for (int j = 0; j < N2; j++) L[N1*N2 + j] = 0;
	
	//recursive
	for (int n1 = N1 - 1; n1 >= 0; n1--)
	{
		for (int n2 = N2 - 1; n2 >= 0; n2--)
		{
			int size1 = 0;
			//search for the position of the element v[n1] into (v + n2)
			int i2 = 0;
			while (n2 + i2 < N2 && v2[n2 + i2] != v1[n1]) i2++;
			if (n2 + i2 < N2)
			{
				if (n2 + i2 + 1 < N2) size1 = L[(n1 + 1)*N2 + n2 + i2 + 1]; //<<if>> due to : L[x][N2] = none; 
				size1++;
			}

			int size2 = L[(n1 + 1)*N2 + n2];

			if (size1 >= size2) L[n1*N2 + n2] = size1;
			else L[n1*N2 + n2] = size2;
		}
	}
	
	//cout<<timer.getElapsedTime()<<" generation of solution"<<endl;

	//generate solution
	list<int> cmlsc;
	int length = L[0*N2 + 0];	
	int n1 = 0, n2 = 0;
	int l = 0;
	while (l < length)
	{
			int size1 = 0;
			//search for the position of the element v[n1] into (v + n2)
			int i2 = 0;
			while (n2 + i2 < N2 && v2[n2 + i2] != v1[n1]) i2++;
			if (n2 + i2 < N2)
			{
				if (n2 + i2 + 1 < N2) size1 = L[(n1 + 1)*N2 + n2 + i2 + 1]; //<<if>> due to : L[x][N2] = none; 
				size1++;
			}

			int size2 = L[(n1 + 1)*N2 + n2];

			//update the indices
			if (size1 >= size2) 
			{
				
				//found one: append to list and increase l
				cmlsc.push_back(v1[n1]);
				l++;

				n1 = n1 + 1;
				n2 = n2 + i2 + 1;
				//sure < N2 (possible excepting last operation, but there are no memory accesses afterward), 
				// because we stop after <<length>> commons
			}
			else
			{
				n1 = n1 + 1;
				//n2 = n2;
			}			
	}	
	
	////check solution
	//int i1 = 0, i2 = 0;
	//for (list<int>::iterator it = L[0].begin(); it != L[0].end(); it++)
	//{
	//	while (i1 < N1 && v1[i1] != *it) i1++;
	//	while (i2 < N2 && v2[i2] != *it) i2++;
	//	cout<<v1[i1]<<", "<<v2[i2]<<"\n";

	//	if (i1 >= N1 || i2 >= N2) cout<<"Invalid solution"<<endl;
	//	
	//	i1++;
	//	i2++;
	//}

	//cout<<timer.getElapsedTime()<<endl;

	ofstream ofs(out_file);
	ofs<<L[0*N2 + 0]<<"\n";	
	for (list<int>::iterator it = cmlsc.begin(); it != cmlsc.end(); it++) ofs<<*it<<" ";
	ofs.close();

	//release the memory
	//delete[] L;

	//cout<<timer.getElapsedTime()<<endl;

	return 0;
}