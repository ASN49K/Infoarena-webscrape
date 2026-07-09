#include <bits/stdc++.h>

const int kMaxN = 100000;

int n, m, ind;
int v[5 * kMaxN + 1];

int get_root(int a, int &type)
{
	int k = a, r;
	type = 0;
	while (v[a]) {
		a = v[a];
		type = !type;
	}
	r = a;
	if (type) {
		a = k;
		while (v[a]) {
			if (type) v[a] = r;
			else v[a] = k;
			a = v[a];
			type = !type;
		}
	}
	return r;
}

int main()
{
	freopen("meciul.in", "rt", stdin);
	freopen("meciul.out", "wt", stdout);

	int t, a, b;

	scanf("%d", &t);

	for (int i = 0; i < t; ++i) {
		scanf("%d %d", &n, &m);
		ind = n + 1;
		for (int j = 1; j <= n; ++j) v[j] = -1;
		for (int j = 0; j < m; ++j) {
			scanf("%d %d", &a, &b);
			if (v[a] == -1) {
				if (v[b] == -1) {
					v[a] = 0;
					v[b] = a;
					printf("YES\n");
				} else {
					v[a] = b;
					printf("YES\n");
				}
			} else {
				if (v[b] == -1) {
					v[b] = a;
					printf("YES\n");
				} else {
					int r1, r2, t1, t2;
					r1 = get_root(a, t1);
					r2 = get_root(b, t2);
					if (r1 == r2) {
						if (t1 == t2) printf("NO\n");
						else printf("YES\n");
					} else {
						if (t1 == 1) {
							v[r1] = a;
							v[a] = b;
						} else if (t2 == 1) {
							v[r2] = b;
							v[b] = a;
						} else {
							v[ind] = 0;
							v[r1] = ind;
							v[r2] = ind;
							++ind;
						}
						printf("YES\n");
					}
				}
			}
		}
	}

	return 0;
}
