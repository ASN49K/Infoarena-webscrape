#include <vector>
#include <map>
#include <queue>
#include <set>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

#define oo (1<<30)

using namespace std;

#define F
#define INPUT "cmlsc.in"
#define OUTPUT "cmlsc.out"

struct subEntry {
  bool completed;
  bool hasValue;
  int len;
  int val;
  int x; //prev x
  int y; // prev y
};

const int M = 1024;
const int N = 1024;

struct subEntry sub[M][N];

int A[M];
int B[N];

int n = 0;
int m = 0;

void setTo(int x, int y, int len, int val, int parX, int parY) {

  sub[x][y].len = len;
  sub[x][y].val = val;
  sub[x][y].hasValue = true;
  sub[x][y].completed = true;
  sub[x][y].x = parX;
  sub[x][y].y = parY;
}

void longestSub(int i, int j) {
  if (sub[i][j].completed) {
    return;
  } else {
    if (i != 0 && j != 0) {
      if (A[i] == B[j]) {
        longestSub(i - 1, j - 1);
        setTo(i, j, 1 + sub[i - 1][j - 1].len, A[i], i - 1, j - 1);
      } else {
        longestSub(i, j - 1);
        longestSub(i - 1, j);
        if (sub[i][j- 1].len > sub[i - 1][j].len) {
          sub[i][j].len = sub[i][j -1].len; 
          sub[i][j].x = i; sub[i][j].y = j - 1;
        } else {
           sub[i][j].len = sub[i - 1][j].len; 
           sub[i][j].x = i - 1; sub[i][j].y = j;
        }
      }
    }  else {
      if (A[i] == B[j]) {
        setTo(i, j, 1, A[i], -1, -1);
      } else {
        if (i > 0) {
          longestSub(i - 1, j);  
          sub[i][j].len = sub[i - 1][j].len;
          sub[i][j].x = i - 1; 
          sub[i][j].y = j;
        }   else if (j > 0) {
          longestSub(i, j - 1);  
          sub[i][j].len = sub[i][j - 1].len;
          sub[i][j].x = i; 
          sub[i][j].y = j - 1;
        } else if (i == 0 && j == 0) {
          sub[i][j].len = 0;
          sub[i][j].x = -1;
          sub[i][j].y = -1;
        } else {
          cerr<< "SHOULD NOT REAC" << endl;
        }
      }
    } 
  }

  sub[i][j].completed = true;
}


void solve() {
  cin >> m >> n; 
  for (int i = 0; i < m; i++)
  {
    cin >> A[i];
  }   
  for (int i = 0; i < n; i++)
  {
    cin >> B[i];

  }   

  longestSub(m - 1, n- 1);
  cout << sub[m -1][n - 1].len << endl; 
  struct subEntry e = sub[m-1][n-1];

  vector<int> elems;
  while (true) {
    if (e.hasValue) {
      elems.push_back(e.val);
    }
    if (e.x == -1 || e.y == -1) {
      break;
    }
    e = sub[e.x][e.y];
    
  }
  for (int i = elems.size() -1; i >= 0 ; i--) {
    cout << elems[i] << " ";
  }
}

int main() {
#ifdef F 
  freopen(INPUT, "r", stdin);
  freopen(OUTPUT, "w", stdout);
#endif
  solve();
}
