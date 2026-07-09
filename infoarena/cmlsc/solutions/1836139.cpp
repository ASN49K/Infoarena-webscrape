#include <iostream>
#include <fstream>
#include <malloc.h>
#include <queue>
#include <queue>

#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

ifstream input("cmlsc.in");
ofstream output("cmlsc.out");
int MAX = 0;

queue<int> solve(queue<int> first, queue<int> second, int *pInt, int *pInt1);

queue<int> readData(int size,int *aparitions){
    queue<int> numbers;
    int element;

    for(int i = 0; i < size; i++ )
    {
        input >> element;
        numbers.push(element);
        aparitions[element]++;
    }
    return numbers;
}

int main() {
    int n = 0, m = 0;
    queue<int> first;
    queue<int> second;
    queue<int> common;
    int *aparitionsFirst = (int*)malloc(256*sizeof(int));
    int *aparitionsSecond = (int*)malloc(256*sizeof(int));

    for(int i = 0; i < 256; i++){
        aparitionsFirst[i] = 0;
        aparitionsSecond[i] = 0;
    }

    input >> n >> m;
    first = readData(n,aparitionsFirst);
    second = readData(m,aparitionsSecond);
    common = solve(first, second, aparitionsFirst, aparitionsSecond);
    output<<MAX <<"\n";
    while(common.size() != 0 )
    {
        output<<common.front()<<" ";
        common.pop();
    }
    return 0;
}

queue<int> solve(queue<int> first, queue<int> second, int *aparitionsFirst, int *aparitionsSecond) {
    MAX = 0;
    int element;
    int test = -1;
    queue<int> common;
    while(first.size() != 0 )
    {
        element = first.front();
        first.pop();
        if(aparitionsSecond[element] != 0){
            aparitionsSecond[element]--;
            common.push(element);
            MAX++;
            while( test != element && second.size() != 0 )
            {
                test = second.front();
                second.pop();
            }
            if(second.size() == 0 )
                break;
        }
    }
    return common;
}
