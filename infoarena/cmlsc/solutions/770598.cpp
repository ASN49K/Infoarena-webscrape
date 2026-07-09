#include <iostream>
#include <fstream>
#include <list>
using namespace std;

//int pb_001_cmlsc()
int main()
{
	char* in_file = "cmlsc.in";
	char* out_file = "cmlsc.out";

	const int MAX_N = 1024;
	int N1, N2;	
	
	int v1[MAX_N];
	int v2[MAX_N];

	list<int> L[MAX_N][MAX_N];

	ifstream ifs(in_file);
	ifs>>N1>>N2;
	for (int i = 0; i < N1; i++) ifs>>v1[i];
	for (int i = 0; i < N2; i++) ifs>>v2[i];
	ifs.close();

	//DYNAMIC PROGRAMING
	//default initialization
	//L[N1][x] = none; L[y][N2] = none;
	
	//recursive
	for (int n1 = N1 - 1; n1 >= 0; n1--)
	{
		for (int n2 = N2 - 1; n2 >= 0; n2--)
		{
			list<int> list1;
			//search for the position of the element v[n1] into (v + n2)
			int i2 = 0;
			while (n2 + i2 < N2 && v2[n2 + i2] != v1[n1]) i2++;
			if (n2 + i2 < N2)
			{
				list1 = L[n1 + 1][n2 + i2];
				list1.push_front(v1[n1]);
			}

			list<int>& list2 = L[n1 + 1][n2];

			if (list1.size() >= list2.size()) L[n1][n2] = list1;
			else L[n1][n2] = list2;
		}
	}
	
	ofstream ofs(out_file);
	ofs<<L[0][0].size()<<"\n";
	for (list<int>::iterator it = L[0][0].begin(); it != L[0][0].end(); it++) ofs<<*it<<" ";		
	ofs.close();

	return 0;
}