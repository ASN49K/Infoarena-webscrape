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

const char shit[] = 
  "00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899";

void putNumber(int x) {
  char *old = writeHead;
  while (x) {
    int rest = x % 100;
    *(writeHead++) = shit[rest * 2];
    *(writeHead++) = shit[rest * 2 + 1];
    x /= 100;
  }
  reverse(old, writeHead);
  --writeHead;
  for (; writeHead >= old && *writeHead == '0'; --writeHead);
  ++writeHead;
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
