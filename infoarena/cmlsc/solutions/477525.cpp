#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int *a, *b;
vector<int> parent, length;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

void print(int ind)
{
	if (parent[ind] > -1) 
		print(parent[ind]);
	out << b[ind] << " ";
		
}

int main()
{
	
	int m, n, i, j, max = 0, ind_max = -1;
	in >> m >> n;
	a = new int[m];
	b = new int[n];
	parent.resize(n, -1);
	length.resize(n, 0);
	
	for (i = 0; i < m; i++)
		in >> a[i];
	for (i = 0; i < n; i++)
		in >> b[i];
		
		
		
	for (i = 0; i < m; i++)
	{
		max = 0;
		for (j = 0; j < n; j++)
		{
			if (a[i] == b[j])
			{
				length[j]++;
				if (length[j] > max)
				{
					max = length[j];
					ind_max = j;
				}
			}
			else if (max > length[j])
				 {
					length[j] = max;
					parent[j] = ind_max;
				 }
		}
	}
	
	max = 0;
	for (i = 0; i < n; i++)
		if (max < length[i]) max = (ind_max = i, length[i]);
	
	out << max << "\n";
	if (max > 0) print(ind_max);
	
	delete a;
	delete b;
	in.close();
	out.close();
	return 0;
}
