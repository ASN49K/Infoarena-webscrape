#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define mp make_pair
#define CHECK(x) if(!(x)) return false;
typedef pair<int, int> pii;

#ifdef INFOARENA
#define ProblemName "euclid2"
#endif

#define MCONCAT(A, B) A B
#ifdef ProblemName
#define InFile MCONCAT(ProblemName, ".in")
#define OuFile MCONCAT(ProblemName, ".out")
#else
#define InFile "fis.in"
#define OuFile "fis.out"
#endif

const int MAXBUF = 2000000;
char parseBuf[MAXBUF];
char *head;
bool isDigit[255];

void parseInit() {
  int a = fread(parseBuf, 1, MAXBUF, stdin);
  parseBuf[a] = 0;
  head = parseBuf;
  memset(isDigit, 0, sizeof isDigit);
  for (int i = '0'; i <= '9'; ++i)
    isDigit[i] = true;
}

int nextInt() {
  int ans = 0;
  for (; !isDigit[*head]; ++head);
  for (; isDigit[*head]; ++head)
    ans = ans * 10 + (*head) - '0';
  return ans;
}

int gcd(int a, int b) {
  while (b) {
    int aux = a % b;
    a = b;
    b = aux;
  }
  return a;
}

int main() {
  freopen(InFile, "r", stdin);
  freopen(OuFile, "w", stdout);
  parseInit();
  int T = nextInt();
  while (T--) {
    int a = nextInt(), b = nextInt();
    printf("%d\n", gcd(a, b));
  }
  return 0;
}
