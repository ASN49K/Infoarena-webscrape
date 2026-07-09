#include <array>
#include <fstream>
#include <cstdlib>
#include <iterator>
#include <algorithm>

using namespace std;

const int NMAX = 1031;

int main()
{
    array<array<int, NMAX>, 3> v;
    array<array<int, NMAX>, NMAX> C;
    ifstream in{"cmlsc.in"};
    ofstream out{"cmlsc.out"};

    in >> v[0][0] >> v[1][0];
    
    for(int i = 1; i <= v[0][0]; ++i) in >> v[0][i];
    for(int i = 1; i <= v[1][0]; ++i) in >> v[1][i];

    for(int i = 1; i <= v[0][0]; ++i)
    {
	for(int j = 1; j <= v[1][0]; ++j)
	{
	    if(v[0][i] == v[1][j]) C[i][j] = 1 + C[i - 1][j - 1];
	    else                   C[i][j] = max(C[i][j - 1], C[i - 1][j]);
	}
    }

    v[2][0] = C[v[0][0]][v[1][0]]; 
    {
	int i = v[0][0];
	int j = v[1][0];
	int k = v[2][0];

	while(i && j)
	{
	    if(v[0][i] == v[1][j]) v[2][k--] = v[0][i], --i, --j;
	    else if(C[i][j - 1] >= C[i - 1][j]) --j;
	    else --i;
	}
    }

    out << v[2][0] << '\n';
    copy(v[2].begin() + 1, v[2].begin() + v[2][0] + 1, ostream_iterator<int>{out, " "});
    out << '\n';

    return EXIT_SUCCESS;
}
