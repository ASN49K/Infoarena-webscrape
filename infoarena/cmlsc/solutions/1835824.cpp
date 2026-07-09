#include <iostream>
#include <fstream>
#include <malloc.h>
#include <map>

#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

ifstream input("cmlsc.in");
ofstream output("cmlsc.out");
int MAX = 0;

int * solve(int n, int m, int *pInt, int *second);

int * readData(int size){
    int *vector;
    vector = (int*)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++ )
        input >> vector[i];
    return vector;
}

int main() {
    int n = 0, m = 0;
    int *first = NULL, *second = NULL;
    int *common;
    input >> n >> m;
    first = readData(n);
    second = readData(m);
    common = solve(n,m,first,second);
    for(int i = 0; i < MAX; i++ )
        cout<<common[i]<<" ";
    free(first);
    free(second);
    return 0;
}

int * solve(int n, int m, int *first, int *second) {
    map<int,int> positions;
    MAX = 0;
    int before = -1;
    int *common = (int*)malloc(max(n,m) * sizeof(int));

    for(int i = 0; i < n; i++ )
        positions[first[i]] = i;
    for(int j = 0; j < m; j++ )
    {
        if(positions.find(second[j]) != positions.end())
        {
            int pos = positions[second[j]];
            if( pos  > before )
            {
                common[MAX] = second[j];
                MAX++;
            }
            before = pos;
        }
        before = 0;
    }
    return common;
}
