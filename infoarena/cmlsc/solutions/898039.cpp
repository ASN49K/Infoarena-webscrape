#include <fstream>
#include <list>

using namespace std;

int main()
{
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");
	int n1, n2;
	in>>n1>>n2;
	int *v1, v2, *pd_prv, *pd_cur, *tmp, **par;
	v1 = new int[n1];
	pd_prv = new int[n1];
	pd_cur = new int[n1];
	par = new int*[n2];
	for(int i = 0; i < n2; i++)
		par[i] = new int[n1];

	for (int i = 0; i < n1; i++)
		in>>v1[i];

	for (int i = 0; i < n2; i++) {
		in>>v2;
		for (int j = 0; j < n1; j++) {
			pd_cur[j] = i > 0 ? pd_prv[j] : 0;
			par[i][j] = 1;
			if (j > 0 && pd_cur[j - 1] > pd_cur[j]) {
				pd_cur[j] = pd_cur[j - 1];
				par[i][j] = 0;
			}
			if (v2 == v1[j] && (1 + ((j > 0 && i > 0) ? pd_prv[j - 1] : 0) > pd_cur[j])) {
				pd_cur[j] = 1 + ((j > 0 && i > 0) ? pd_prv[j - 1] : 0);
				par[i][j] = 2;
			}
		}
		tmp = pd_prv;
		pd_prv = pd_cur;
		pd_cur = tmp;
	}
	out<<pd_prv[n1 - 1]<<endl;

	int i = n2 - 1, j = n1 - 1;
	list<int> lst;
	while (i >= 0 && j >= 0) {
		switch (par[i][j]) {
		case 0: j--; break;
		case 1: i--; break;
		case 2: lst.push_front(v1[j]); i--; j--; break;
		default:
            out<<"PROBLEMO! "<<par[i][j]<<endl;
		}
	}
	while (!lst.empty()) {
		out<<lst.front()<<" ";
		lst.pop_front();
	}

	return 0;
}
