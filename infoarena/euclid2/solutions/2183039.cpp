#include <bits/stdc++.h>
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
char *writeHead;

void parseInit() {
  int a = fread(parseBuf, 1, MAXBUF, stdin);
  parseBuf[a] = 0;
  head = parseBuf;
  memset(isDigit, 0, sizeof isDigit);
  for (int i = '0'; i <= '9'; ++i)
    isDigit[i] = true;
  writeHead = head;
}

int nextInt() {
  int ans = 0;
  for (; !isDigit[*head]; ++head);
  for (; isDigit[*head]; ++head)
    ans = ans * 10 + (*head) - '0';
  return ans;
}

void putNumber(int x) {
  char *old = writeHead;
  while (x) {
    *(writeHead++) = x % 10 + '0';
    x /= 10;
  }
  //reverse(old, writeHead);
  *(writeHead++) = '\n';
}

int main() {
  freopen(InFile, "r", stdin);
  freopen(OuFile, "w", stdout);
  parseInit();
  int T = nextInt();
  while (T--) {
    int a = nextInt(), b = nextInt();
    putNumber(__gcd(a, b));
  }
  fwrite(parseBuf, 1, writeHead - parseBuf, stdout);
  return 0;
}
