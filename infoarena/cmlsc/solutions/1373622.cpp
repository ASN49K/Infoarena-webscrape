#include <iostream>
#include <fstream>
#include <deque>
using namespace std;
ifstream f("alee.in");
ofstream g("alee.out");
int v[180][180];
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
deque < int > qx,qy;
void lee()
{
    int nx,ny,yy,xx;
    while(!qx.empty()){
        nx = qx.front();
        ny = qy.front();
        for(int i = 0; i <= 3; i++){
            xx = nx + dx[i];
            yy = ny + dy[i];
            if(v[xx][yy] == 0){
                qx.push_back(xx);
                qy.push_back(yy);
                v[xx][yy] = v[nx][ny] + 1;
            }
        }
        qx.pop_front();
        qy.pop_front();
    }
}

int main()
{
    int n,m,xi,yi,xf,yf;
    f >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        f >> xi >> yi;
        v[xi][yi] = -1;
    }
    f >> xi >> yi >> xf >> yf;
    v[xi][yi] = 1;
    qx.push_back(xi);
    qy.push_back(yi);
    for(int i = 0; i <= n + 1; i++)
        {
            v[0][i] = -1;v[i][n+1] = -1;v[n+1][i] = -1;v[i][0] = -1;
        }
    lee();
    g << v[xf][yf];
    return 0;
}
