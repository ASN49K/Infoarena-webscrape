#include <fstream>
#include <vector>
#define DIM 1025
#define LIMIT 256

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

struct subsir {
    int head;
    int positionB;
    int positionA;
    int length;
    subsir* previous;

    subsir() {
        head = 0;
        positionA = -1;
        positionB = -1;
        length = 0;
        previous = nullptr;
    }
};

int n, m;
int A[DIM], B[DIM];
vector<int> positionsInB[LIMIT + 1];
vector<subsir> subsiruri;

int findBestPosition(int prevPositionB, int directoryIndex) {
    int position = -1;
    int st = 0;
    int dr = positionsInB[directoryIndex].size() - 1;
    while (st <= dr) {
        int mid = (st + dr) / 2;
        if (positionsInB[directoryIndex][mid] > prevPositionB) {
            dr = mid - 1;
            position = positionsInB[directoryIndex][mid];
        }
        else {
            st = mid + 1;
        }
    }
    if (position < prevPositionB)
    {
        position = -1;
    }
    return position;
}

void printSubsir(subsir current) {
    if (current.previous != nullptr) {
        printSubsir(*current.previous);
    }
    fout << current.head << " ";
}

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fin >> A[i];
    }
    for (int i = 1; i <= m; i++) {
        fin >> B[i];
        positionsInB[B[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (positionsInB[A[i]].size() == 0)
            continue;
        int place = -1;
        int maxLength = -1;
        subsir previous;
        for (vector<subsir> ::iterator it = subsiruri.begin(); it != subsiruri.end(); it++) {
            if (it->length <= maxLength)
                continue;
            int placeInB = findBestPosition(it->positionB, A[i]);
            if (placeInB != -1) {
                if (maxLength < it->length) {
                    maxLength = it->length + 1;
                    place = placeInB;
                    previous = *it;
                }
            }
        }
        subsir newSubsir;
        if (maxLength != -1) {
            newSubsir.head = A[i];
            newSubsir.positionA = i;
            newSubsir.positionB = place;
            newSubsir.previous = &previous;
            newSubsir.length = maxLength;
        }
        else {
            newSubsir.head = A[i];
            newSubsir.positionA = i;
            newSubsir.positionB = positionsInB[A[i]][0];
            newSubsir.previous = nullptr;
            newSubsir.length = 1;
        }
        subsiruri.push_back(newSubsir);
    }
    int sol = -1;
    subsir maxSubsirEnd;
    for (vector<subsir> ::iterator it = subsiruri.begin(); it < subsiruri.end(); it++) {
        if (sol < it->length) {
            sol = it->length;
            maxSubsirEnd = *it;
        }
    }
    fout << sol << "\n";
    printSubsir(maxSubsirEnd);
}