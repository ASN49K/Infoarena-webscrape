#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define dbg(x) cout << #x <<": " << x << "\n";
using ll = long long;

class InP {
	FILE *fin;
	char *buff;
	int sp;

public:
	InP(const char *p) {
		fin = fopen(p, "r");
		buff = new char[4096]();
		sp = 4095;
	}
	char read_ch() {
		sp++;
		if (sp == 4096) {
			fread(buff, 1, 4096, fin);
			sp = 0;
		}
		return buff[sp];
	}

	InP &operator >>(int &n) {
		char c;
		int sgn = 1;
		while (!isdigit(c = read_ch()) && c != '-');
		if (c == '-') {
			n = 0;
			sgn = -1;
		}
		else n = c - '0';
		while (isdigit(c = read_ch()))
			n = n * 10 + c - '0';
		n = n * sgn;
		return *this;
	}

	InP &operator >>(ll &n) {
		char c;
		int sgn = 1;
		while (!isdigit(c = read_ch()) && c != '-');
		if (c == '-') {
			n = 0;
			sgn = -1;
		}
		else n = c - '0';
		while (isdigit(c = read_ch()))
			n = n * 10LL + c - '0';
		n = n * sgn;
		return *this;
	}

	InP &operator >> (char &n) {
		n = read_ch();
		// while ((n = read_ch()) != '\n' && n != ' ');
		return *this;
	}

};

class OuP {
	FILE *fout;
	char *buff;
	int sp;

public:

	OuP(const char *p) {
		fout = fopen(p, "w");
		buff = new char[50000];
		sp = 0;
	}
	~OuP() {
		fwrite(buff, 1, sp, fout);
		fclose(fout);
	}
	void write_ch(char c) {
		if (sp == 50000) {
			fwrite(buff, 1, sp, fout);
			sp = 0;
		}
		buff[sp++] = c;
	}

	OuP &operator <<(int n) {
		if (n <= 9)
			write_ch(n + '0');
		else {
			*(this) << (n / 10);
			write_ch(n % 10 + '0');
		}
		return *this;
	}

	OuP &operator <<(ll n) {
		if (n <= 9)
			write_ch(n + '0');
		else {
			*(this) << (n / 10);
			write_ch(n % 10 + '0');
		}
		return *this;
	}

	OuP &operator <<(char c) {
		write_ch(c);
		return *this;
	}

	OuP &operator <<(char *c) {
		while (*c) {
			write_ch(*c);
			c++;
		}
		return *this;
	}

};

InP fin("cmlsc.in");
OuP fout("cmlsc.out");

int n, m;
int a[1025], b[1025];
int dp[1025][1025];

int main() {

	fin >> n >> m;
	for (int i = 1; i <= n; ++i)
		fin >> a[i];
	for (int i = 1; i <= m; ++i)
		fin >> b[i];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	fout << dp[n][m] << '\n';
	int i = n, j = m;
	vector<int> x;
	while (i && j) {
		if (a[i] == b[j])
			x.pb(a[i]);
		if (dp[i - 1][j] >= dp[i][j - 1])
			i--;
		else j--;
	}

	reverse(x.begin(), x.end());
	for (auto i : x)
		fout << i << " ";

	// fin.close();
	// fout.close();
	return 0;
}