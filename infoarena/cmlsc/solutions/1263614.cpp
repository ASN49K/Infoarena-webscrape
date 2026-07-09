#include<fstream>
#include<iostream>

using namespace std;


struct value{
	int val;
	int pointer=1025;
	int pointer2=1025;
}solutie[1024];


int main(){
	int n, m, v1[1024], v2[1024], size = 0, last_pos=0, OK=true;
	ifstream input("cmlsc.in");
	input >> n >> m;
	for (int i = 0; i < n; i++){ input >> v1[i];}
	for (int i = 0; i < m; i++)
	{
		
		input >> v2[i];

		for (int j = 0; j < n; j++)
		{
			if (v2[i] == v1[j])
			{
				solutie[size].val = v2[i];
				solutie[size].pointer = j;
				solutie[size].pointer2 = i;
				size += 1;
			}
		}

	}

	input.close();


	do{
		OK = true;
		for (int i = 1; i <= m ; i++)
		{
			if (solutie[i].pointer2<solutie[i - 1].pointer2 || solutie[i].pointer2 > solutie[i + 1].pointer2 || solutie[i].pointer<solutie[i - 1].pointer || solutie[i].pointer > solutie[i + 1].pointer)
			{
				for (int z = i; z < size; z++)
				{
					solutie[z].pointer = solutie[z+1].pointer;
					solutie[z].val = solutie[z+1].val;
					solutie[z].pointer2 = solutie[z+1].pointer2;
				}
				size-=1;

			}
		}

	} while (!OK);


	ofstream output("cmlsc.out");

	output << size << "\n";
	for (int i = 0; i < size; i++)
	{
		output << solutie[i].val << " ";
	}
	return 0;

}
