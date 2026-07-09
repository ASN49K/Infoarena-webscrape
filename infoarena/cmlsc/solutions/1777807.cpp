 #include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	ifstream fin;
	fin.open("cmlsc.in");
	ofstream fout;
	fout.open("cmlsc.out");
	long long n,m;
	fin >> n >> m;
	vector <string> a(n),b(m),k;
	for (int i=0;i<n;i++)
	{
		fin >> a[i];
	//	cout << a[i] << endl;
	}
	for(int i=0;i<m;i++)
	{
		fin >> b[i];
		if (find(a.begin(),a.end(),b[i])!=a.end())
			k.push_back(b[i]);
	}
	fout << k.size() << "\n";
	for (int i=0;i<k.size();i++)
	{
		fout << k[i] << " ";
		//cout << b[i] << " ";
	}
	//cout << n << m;
	fin.close();
	fout.close();
	return 0;
}
