#include <iostream>
#include <fstream>
#include <list>
using namespace std;

list<int> cmlsc(int N1, int* v1, int N2, int* v2)
{
	list<int> L12;
	if (N1 == 0) return L12;	
	//the first position of v1[0] in v2
	int i2 = 0;
	while (i2 < N2 && v2[i2] != v1[0]) i2++;

	list<int> list1;
	if (i2 < N2) 
	{
		list1 = cmlsc(N1 - 1, v1 + 1, N2 - i2, v2 + i2);
		list1.push_front(v1[0]);
	}	
	
	list<int> list2 = cmlsc(N1 - 1, v1 + 1, N2, v2);

	if (list1.size() >= list2.size()) return list1;
	else return list2;
}

//int pb_001_cmlsc()
int main()
{
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

	list<int> L12 = cmlsc(N1, v1, N2, v2);
	
	ofstream ofs(out_file);
	ofs<<L12.size()<<"\n";
	for (list<int>::iterator it = L12.begin(); it != L12.end(); it++) ofs<<*it<<" ";		
	ofs.close();

	return 0;
}