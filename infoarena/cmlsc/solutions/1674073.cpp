#include <cstdio>
#include <vector>

using namespace std;

vector<int> lcs(int* a, int* b, int n, int m){
    int c=0;
    vector<int> s;

    if(n==0||m==0)return s;
    if(a[n-1]==b[m-1]){
        s.push_back(a[n-1]);
        vector<int> v=lcs(a, b, n-1, m-1);
        s.insert(s.end(), v.begin(), v.end());
    }
    else{
        vector<int> p1;
        vector<int> p2;
        p1=lcs(a, b, n-1, m);
        p2=lcs(a, b, n, m-1);
        if(p1.size()>p2.size()){
            s.insert(s.end(), p1.begin(), p1.end());
        }
        else{
            s.insert(s.end(), p2.begin(), p2.end());
        }
    }
    return s;
}

int main()
{
    FILE* f=fopen("cmlsc.in", "r");
    FILE* f1=fopen("cmlsc.out", "w");

    int n, m, v[1024], w[1024];
    fscanf(f, "%d %d", &n, &m);

    for(int i=0;i<n;i++){
        fscanf(f, "%d ", &v[i]);
    }

    for(int i=0;i<m;i++){
        fscanf(f, "%d ", &w[i]);
    }
    vector<int> sol=lcs(v, w, n, m);
    fprintf(f1, "%d\n", sol.size());

    for(int i=sol.size();i>0;i--){
        fprintf(f1, "%d ", sol[i-1]);
    }
    return 0;
}
