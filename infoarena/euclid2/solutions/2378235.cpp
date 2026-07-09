#include <bits/stdc++.h>
using namespace std;



int main () {

	freopen("permutari.in", "r", stdin);

	freopen("permutari.out", "w", stdout);



	int N;

	vector<int> v;



	cin >> N;

	for (int i = 1; i <= N; ++i)

		v.push_back(i);

	do {

		for (int i = 0; i < N; ++i)

			cout << v[i] << ' ';

		cout << '\n';

	} while (next_permutation(v.begin(), v.end()));

}
/*#include <bits/stdc++.h>
using namespace std;
ifstream fin("permutari.in");
ofstream fout("permutari.out");

int n;
bool vf[11], found;
short sol[10];

void bak(int k)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        if(!vf[i])
        {
            sol[k] = i;
            found = vf[i] = 1;
            bak(k+1);
            found = vf[i] = 0;
        }
    }
    if(k == n)
    {
        for(i = 0; i < n; i++)
            fout << sol[i] << ' ';
        fout << '\n';
    }
}


int main()
{
    fin >> n;
    bak(0);
    return 0;
}
*/
