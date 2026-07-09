#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N          200
#define MODULO   98999

static int s[N + 1][N + 1], S[N + 1][N + 1];

int sitrling_main() {
	freopen("stirling.in", "r", stdin);
	freopen("stirling.out", "w", stdout);

	memset(s, 0, sizeof(s));
	memset(S, 0, sizeof(S));

	s[1][1] = 1;
	S[1][1] = 1;

	int i, j;

	for (i = 2; i <= N; i++) {
		for (j = 1; j <= i; j++) {
			s[i][j] = (s[i - 1][j - 1] - (i - 1) * s[i - 1][j]) % MODULO;
			S[i][j] = (S[i - 1][j - 1] + j * S[i - 1][j]) % MODULO;
		}
	}

	int T;
	scanf("%d\n", &T);

	for (i = 0; i < T; i++) {
		int x, n, m;
		scanf("%d %d %d\n", &x, &n, &m);
		if (x == 1) {
			printf("%d\n", s[n][m]);
		} else if (x == 2) {
			printf("%d\n", S[n][m]);
		}
	}

	return 0;
}

typedef struct uf_node_ {
	int rank;
	struct uf_node_ *parent;
} uf_node;

uf_node *new_node() {
	uf_node *node = (uf_node *) malloc(sizeof(uf_node));
	node->rank = 0;
	node->parent = node;
	return node;
}

uf_node *data[100001];

void do_union(int x, int y) {
	uf_node *nx = data[x];

	while (nx != nx->parent)
		nx = nx->parent;

	uf_node *ny = data[y];

	while (ny != ny->parent)
		ny = ny->parent;

	if (nx->rank < ny->rank) {
		nx->parent = ny;
		ny->rank++;
	} else {
		ny->parent = nx;
		nx->rank++;
	}
}

int do_find(int x, int y) {
	uf_node *nx = data[x];

	while (nx != nx->parent)
		nx = nx->parent;

	uf_node *ny = data[y];

	while (ny != ny->parent)
		ny = ny->parent;

	return nx == ny;
}

int union_find_main() {
	freopen("disjoint.in", "r", stdin);
	freopen("disjoint.out", "w", stdout);

	int n, m, i;
	int cod, x, y;
	scanf("%d %d\n", &n, &m);

	for (i = 1; i <= n; i++) {
		data[i] = new_node();
	}

	for (i = 1; i <= m; i++) {
		scanf("%d %d %d\n", &cod, &x, &y);
		if (cod == 1) {
			do_union(x, y);
		} else if (cod == 2) {
			int result = do_find(x, y);
			if (result)
				printf("DA\n");
			else
				printf("NU\n");
		}
	}

	return 0;
}

static char str[100001], *it;

static int termen();
static int factor();

static int eval() {
	int result = termen();
	while (*it == '+' || *it == '-') {
		if (*it == '+') {
			it++;
			result += termen();
		} else if (*it == '-') {
			it++;
			result -= termen();
		}
	}
	return result;
}

int termen() {
	int result = factor();
	while (*it == '*' || *it == '/') {
		if (*it == '*') {
			it++;
			result *= factor();
		} else if (*it == '/') {
			it++;
			result /= factor();
		}
	}
	return result;
}

int factor() {
	int result;
	if (*it == '(') {
		it++;
		result = eval();
		it++;
	} else {
		result = 0;
		while (*it >= '0' && *it <= '9') {
			result = result * 10 + *it - '0';
			it++;
		}
	}
	return result;
}

int evaluare_main() {
	freopen("evaluare.in", "r", stdin);
	freopen("evaluare.out", "w", stdout);

	fgets(str, 100001, stdin);

	int len = strlen(str);
	if (str[len - 1] == '\n') {
		str[len - 1] = 0;
		len--;
	}
	it = str;
	int result = eval();

	printf("%d\n", result);

	return 0;
}

void doprint(int i, long *pre, long *data) {
	if (i == -1)
		return;

	doprint(pre[i], pre, data);
	printf("%ld ", data[i]);
}

void print(int i, long *pre, long *data) {
	if (i == 0)
		return;

	print(pre[i], pre, data);
	printf("%d ", data[i]);
}

int scmax_main() {
	freopen("scmax.in", "r", stdin);
	freopen("scmax.out", "w", stdout);

	static long data[100010];
	static long M[100010];
	static long pre[100010];

	int nr;
	scanf("%d\n", &nr);

	int i, j;
	for (i = 1; i <= nr; i++) {
		scanf("%ld ", &data[i]);
	}

	int L = 0, inf, sup, mid;
	memset(M, 0, sizeof(M));
	for (i = 1; i <= nr; i++) {
		inf = 1;
		sup = L;
		j = 0;
		if (data[M[L]] < data[i]) {
			j = L;
		} else {
			while (inf <= sup) {
				mid = inf + (sup - inf) / 2;
				if (data[M[mid]] < data[i]) {
					if (data[M[mid + 1]] > data[i]) {
						j = mid;
						break;
					}
					inf = mid + 1;
				} else {
					sup = mid - 1;
				}
			}
		}

		pre[i] = M[j];
		if (j == L || data[i] < data[M[j + 1]]) {
			M[j + 1] = i;
			if (L < (j + 1)) {
				L = j + 1;
			}
		}
	}

	printf("%d\n", L);
	print(M[L], pre, data);
	//for (i = 1; i <= nr; i++) {
	//	printf("%d %ld %d\n", i, data[i], pre[i]);
	//}

	/*
	 static long S[100000]
	 int bestS, bestJ;
	 S[0] = 1;
	 pre[0] = -1;
	 for (i = 1; i < nr; i++) {
	 bestS = 0;
	 bestJ = -1;
	 for (j = 0; j < i; j++) {
	 if (data[j] < data[i]) {
	 if (bestS < S[j]) {
	 bestS = S[j];
	 bestJ = j;
	 }
	 }

	 }
	 S[i] = 1 + bestS;
	 pre[i] = bestJ;
	 }

	 int maxS = S[0], maxI = 0;
	 for (i = 1; i < nr; i++) {
	 if (maxS < S[i]) {
	 maxS = S[i];
	 maxI = i;
	 }
	 }

	 printf("%d\n", maxS);
	 doprint(maxI, pre, data);
	 */
	return 0;
}

char B[2000010];
char A[2000010];

int strmatch_main() {
	freopen("strmatch.in", "r", stdin);
	freopen("strmatch.out", "w", stdout);

	fgets(A, 2000010, stdin);
	fgets(B, 2000010, stdin);

	int nA = strlen(A);
	if (A[nA - 1] == '\n') {
		nA--;
		A[nA] = 0;
	}

	int nB = strlen(B);
	if (B[nB - 1] == '\n') {
		nB--;
		B[nB] = 0;
	}

	if (nA > nB) {
		printf("0\n");
		return 0;
	}

	int i = nA, j, ok;
	int hA1 = 0, hA2 = 0, hB1 = 0, hB2 = 0;
	int P = 73, MOD1 = 100007, MOD2 = 100021;
	int P1 = 1, P2 = 1;
	for (i = 0; i < nA; i++) {
		hA1 = (hA1 * P + A[i]) % MOD1;
		hA2 = (hA2 * P + A[i]) % MOD2;

		hB1 = (hB1 * P + B[i]) % MOD1;
		hB2 = (hB2 * P + B[i]) % MOD2;

		if (i > 0) {
			P1 = (P1 * P) % MOD1;
			P2 = (P2 * P) % MOD2;
		}
	}

	int nsols = 0;
	int pos[1000];

	while (1) {
		if (hA1 == hB1 && hA2 == hB2) {
			if (nsols < 1000)
				pos[nsols] = i - nA;
			nsols++;
		}

		if (i < nB) {
			hB1 = ((hB1 - (B[i - nA] * P1) % MOD1 + MOD1) * P + B[i]) % MOD1;
			hB2 = ((hB2 - (B[i - nA] * P2) % MOD2 + MOD2) * P + B[i]) % MOD2;
			i++;
		} else {
			break;
		}
	}

	printf("%d\n", nsols);
	for (i = 0; i < nsols && i < 1000; i++)
		printf("%d ", pos[i]);

	return 0;
}

static int prev[2000010];

void initprev(char *p, int m) {
	int q, k;

	k = 0;
	prev[1] = 0;
	for (q = 2; q <= m; q++) {
		while (k > 0 && p[k + 1] != p[q]) {
			k = prev[k];
		}
		if (p[k + 1] == p[q])
			k++;
		prev[q] = k;
	}
}

void kmp(char *A, int m, char *B, int n) {
	int i;
	int q;
	int c = 0;
	static int res[1000];

	initprev(A, m);
	q = 0;

	for (i = 1; i <= n; i++) {
		while (q > 0 && A[q + 1] != B[i])
			q = prev[q];
		if (A[q + 1] == B[i])
			q++;
		if (q == m) {
			q = prev[q];
			if (c < 1000) {
				res[c] = i - m;
			}
			c++;
		}
	}

	printf("%d\n", c);
	for (i = 0; i < c; i++)
		printf("%d ", res[i]);
}

int kmp_main() {
	freopen("strmatch.in", "r", stdin);
	//freopen("grader_test50.in", "r", stdin);
	//freopen("strmatch.out", "w", stdout);

	memset(B, 0, sizeof(B));
	memset(A, 0, sizeof(A));
	fgets(B + 1, 2000009, stdin);
	fgets(A + 1, 2000009, stdin);
	kmp(B, strlen(B + 1), A, strlen(A + 1));
	return 0;
}

/*
#define GC 10002

int graph[GC][GC];
int cFlow[GC][GC];
int cPath[GC], cPathLen = 0;
int bestRes = 0;
char used[GC];

int dfs(int node, int maxFlow, int nNodes);

int getMaxFlow(int nNodes) {
	int i, j;
	for (i = 0; i < nNodes; i++) {
		printf("%d => ", i);
		for (int j = 0; j < nNodes; j++) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	memset(cFlow, 0, sizeof(cFlow));
	memset(used, 0, sizeof(used));
	while (dfs(0, 1 << 30, nNodes) > 0)
		;
	return bestRes;
}

int dfs(int node, int maxFlow, int nNodes) {
	int i;
	if (node == nNodes - 1) {
		int prev = 0;
		for (i = 0; i < cPathLen; i++) {
			int val = cPath[i];
			if (val == prev) {
				continue;
			}
			cFlow[prev][val] += maxFlow;
			prev = val;
		}
		cFlow[prev][node] += maxFlow;
		bestRes += maxFlow;
		memset(used, 0, sizeof(used));
		return maxFlow;
	}

	cPath[cPathLen++] = node;
	used[node] = 1;
	for (i = 0; i < nNodes; i++) {
		if (i == node || used[i]) {
			continue;
		}
		if (graph[node][i] > cFlow[node][i]) {
			int tmp = graph[node][i] - cFlow[node][i];
			int res = dfs(i, maxFlow > tmp ? tmp : maxFlow, nNodes);
			if (res > 0) {
				cPathLen--;
				return res;
			}
		}
	}

	cPathLen--;
	return 0;
}

int matching_main() {
	freopen("cuplaj.in", "r", stdin);
	//freopen("cuplaj.out", "r", stdout);

	int n, m, e;

	scanf("%d %d %d\n", &n, &m, &e);

	memset(graph, 0, sizeof(graph));
	int i, u, v;
	for (i = 0; i < e; i++) {
		scanf("%d %d\n", &u, &v);
		graph[u][n + v] = 1;
	}

	for (i = 1; i <= n; i++) {
		graph[0][i] = 1;
	}

	for (i = 1; i <= m; i++) {
		graph[n + i][n + m + 1] = 1;
	}

	int result = getMaxFlow(n + m + 2);
	printf("%d\n", result);

	return 0;
}
*/

#define MAX_P 1000010
char fprim[MAX_P];
int prim[80000], np;

void calculate() {
	int i, j;

	for (i = 2; i < MAX_P; i++)
		fprim[i - 1] = 1;

	np = 0;
	for (i = 2; i < MAX_P; i++) {
		if (!fprim[i]) continue;
		for (j = 2 * i; j < MAX_P; j += i) {
			fprim[j] = 0;
		}
		prim[np++] = i;
	}
}

long long query(long long A, long long B) {
	// #number <= A that are primes with B
	int sets[30];
	int k = 0, d = 0;
	long long result = 0;

	while (B > 1) {
		if (B % prim[d] == 0) {
			sets[k++] = prim[d];
		}
		while (B % prim[d] == 0) {
			B /= prim[d];
		}

		if (prim[d] * prim[d] > B && B > 1) {
			sets[k++] = B;
			B = 1;
		}
		d++;
	}

	long long tmp;
	int i, j, counter, sign;
	for (j = 1; j < (1 << k); j++) {
		tmp = 1;
		counter = 0;
		for (i = 0; i < k; i++) {
			if ((1 << i) & j) {
				tmp = tmp * 1LL * sets[i];
				counter++;
			}
		}

		if (counter % 2 == 0)
			sign = -1;
		else
			sign = +1;

		result = result + 1LL * sign * A / tmp;
	}

	return A * 1LL - result;
}

void pinex_main() {
	freopen("pinex.in", "r", stdin);
	freopen("pinex.out", "w", stdout);

	int i, M;
	long long A, B;
	scanf("%d\n", &M);

	calculate();

	for (i = 0; i < M; i++) {
		scanf("%lld %lld\n", &A, &B);
		long long result = query(A, B);
		printf("%lld\n", result);
	}
}

void nim_main() {
	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);

	int t, i, n, j, sum, tmp;
	scanf("%d\n", &t);
	for (i = 0; i < t; i++) {
		scanf("%d\n", &n);
		sum = 0;
		for (j = 0; j < n; j++) {
			scanf("%d ", &tmp);
			sum ^= tmp;
		}

		if (sum) printf("DA\n");
		else printf("NU\n");
	}
}

int main(int argc, char **argv) {
//return stirling_main();
//return union_find_main();
//return evaluare_main();
//return scmax_main();
//return strmatch_main();

	//return kmp_main();
	//return matching_main();

	//pinex_main();
	nim_main();

	return 0;
}
