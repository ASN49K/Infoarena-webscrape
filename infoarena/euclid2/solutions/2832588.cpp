#include <iostream>
#include <fstream>
using namespace std;
ifstream f("flip.in");
ofstream g("flip.out");
int main()
{
    int N, M, s = 0;
    int v[17][17], p[17][17];
    cin >> N >> M;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++){
        cin >> v[i][j];
    }
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
    {
        p[i][j] = v[i][j];
    }
    for(int i=1; i<=N; i++){
        int sum = 0;
        for(int j=1; j<=M; j++){
            sum += v[i][j];
        if (sum < 0){
        for(int j=1; j<=M; j++)
           v[i][j] *= -1;
        }
        }
    }
    for(int j=1; j<=M; j++){
        int sum = 0;
        for(int i=1; i<=M; i++)
            sum += v[i][j];
        if(sum < 0)
            for(int i=1; i<=M; i++)
                v[i][j] *=-1;
    }

    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
    {
        s += v[i][j];
    }
    cout << s;
}
