#include <fstream>
#include <list>

int main() {
    std::ifstream in("cmlsc.in");
    std::ofstream out("cmlsc.out");
    std::list<int> myL;
    int nV1, nV2;
    in >> nV1 >> nV2;
    int *A = new int[nV1 + 1];
    int *B = new int[nV2 + 1];
    for(int i = 1; i <= nV1; i++) {
        in >> A[i];
    }
    for(int i = 1; i <= nV2; i++) {
        in >> B[i];
    }
    int **Arr = new int*[nV1 + 1];
    for(int i = 0; i <= nV1; i++) {
        Arr[i] = new int[nV2 + 1];
    }
    for(int i = 0; i <= nV1; i++) {
        Arr[i][0] = 0;
    }
    for(int j = 0; j <= nV2; j++) {
        Arr[0][j] = 0;
    }
    for(int i = 1; i <= nV1; i++) {
        for(int j = 1; j <= nV2; j++) {
            if(A[i] == B[j]) {
                Arr[i][j] = Arr[i - 1][j - 1] + 1;
            } else {
                Arr[i][j] = std::max(Arr[i - 1][j], Arr[i][j - 1]);
            }
        }
    }
    for(int x = nV1, y = nV2; x != 0 && y != 0;) {
        if(A[x] == B[y]) {
            myL.push_back(A[x]);
            x--;
            y--;
        } else if(Arr[x - 1][y] > Arr[x][y - 1]) {
            x--;
        } else {
            y--;
        }
    }
    while(!myL.empty()) {
        out << myL.back() << ' ';
        myL.pop_back();
    }
    return 0;
}
