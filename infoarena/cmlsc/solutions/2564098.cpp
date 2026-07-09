#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Result {
	int len;
	vector<int> subsequence;
};

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n, m;
	vector<int> v;
	vector<int> w;

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;

		v.push_back(-1); // adaugare element fictiv - indexare de la 1
		for (int i = 1, e; i <= n; i++) {
			fin >> e;
			v.push_back(e);
		}

		w.push_back(-1); // adaugare element fictiv - indexare de la 1
		for (int i = 1, e; i <= m; i++) {
			fin >> e;
			w.push_back(e);
		}

		fin.close();
	}
    int parsing(vector<int> a, vector<int> b, int size1, int size2, Result* result)
    {
        int table[size1+1][size2+1]={0};
        for(int i = 0; i <= size1; i++)
        {
            for(int j = 0; j <= size2; j++)
            {
                if(i == 0 || j == 0)
                    table[i][j] = 0;
                else if(a[i-1]==b[j-1] )
                {
                    table[i][j]=table[i-1][j-1]+1;
                }
                else
                    table[i][j]=max(table[i-1][j],table[i][j-1]);
            }
        }
        /**
        for(int i = 0; i <= size1; i++)
        {
            for(int j = 0; j <= size2; j++)
                cout<<table[i][j]<<" ";
            cout<<endl;
        }*/
        int i = size1, j = size2;
        vector<int> seq;
        while(table[i][j])
        {
            if(a[i-1]==b[j-1])
            {
                seq.push_back(a[i-1]);
                i--;j--;
            }
            else if(table[i-1][j]>table[i][j-1])
                i--;
            else j--;
        }
        for(int k = seq.size()-1; k >= 0; k--)
            result->subsequence.push_back(seq[k]);
        return table[size1][size2];
    }
	Result get_result() {
		Result result;
		result.len = 0;
        v.erase(v.begin());
        w.erase(w.begin());
		/*
		TODO: Aflati cel mai lung subsir comun intre v (de lungime n)
		si w (de lungime m).
		Se puncteaza separat urmatoarele 2 cerinte:
		2.1. Lungimea CMLSC. Rezultatul pentru cerinta aceasta se va pune in
		``result.len``.
		2.2. Reconstructia CMLSC. Se puncteaza orice subsir comun maximal valid.
		Solutia pentru aceasta cerinta se va pune in ``result.subsequence``.
		*/
        result.len = parsing(v, w, v.size(), w.size(), &result);
		return result;
	}

	void print_output(Result result) {
		ofstream fout("out");
		fout << result.len << '\n';
		for (int x : result.subsequence) {
			fout << x << ' ';
		}
		fout << '\n';
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
