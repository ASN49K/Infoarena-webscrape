#include<fstream>

using namespace std;

int main(){
	int n, m, v1[1024], v2[1024], size=0, solutie[1024];
	ifstream input("cmlsc.in");
	input >> n >> m;
	for (int i = 0; i < n; i++)
	{
		input >> v1[i];
	}
	
	for (int i = 0; i < m; i++)
	{
		input >> v2[i];
		for (int j = 0; j < n; j++)
		{
			if (v1[j] == v2[i])
			{
				solutie[size] = v1[j];
				size += 1;
			}
		}
	}
	input.close();

	ofstream output("cmlsc.out");

	output << size << "\n";
	for (int i = 0; i < size; i++)
	{
		output << solutie[i] << " ";
	}
	return 0;

}