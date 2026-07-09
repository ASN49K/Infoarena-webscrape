#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int ny[1041], my[1041];
int big_brain[1041][1041];

stack<int> walmart;

bool juice(int x, int y){
    return (x != 0 && y != 0);
}

int main()
{
    int n, m;
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> ny[i];
    }
    for(int i = 1; i <= m; i++){
        fin >> my[i];
    }

    for(int x = 1; x <= n; x++){
        for(int y = 1; y <= m; y++){
            int d;
            if(ny[x] == my[y]){
                d = big_brain[x-1][y-1]+1;
            }else{
                d = max(big_brain[x-1][y], big_brain[x][y-1]);
            }
            big_brain[x][y] = d;
        }
    }

    int x = n, y = m;
    while(juice(x, y)){
        int a = big_brain[x-1][y];
        int b = big_brain[x][y-1];
        if(ny[x] == my[y]){
            walmart.push(ny[x]);
        }
        if(a > b){
            x--;
        }else{
            y--;
        }
    }

    fout << big_brain[n][m] << "\n";
    while(!walmart.empty()){
        fout << walmart.top() << " ";
        walmart.pop();
    }
    return 0;
}
