#include <cstdio>
using namespace std;

int M, N, arr1[1<<10], arr2[1<<10];
int k, ans[1<<10], index, length;

int main(){

freopen("cmlsc.in", "r", stdin);
freopen("cmlsc.out", "w", stdout);

scanf("%d %d", &M, &N);

for(int i = 0; i < M; i++){
    scanf("%d", &arr1[i]);
}
for(int i = 0; i < N; i++){
    scanf("%d", &arr2[i]);
}
for(int i = 0; i < M; i++){
    for(int j = k; j < N; j++){
        if(arr1[i] == arr2[j]){
            ans[index++] = arr1[i];
            length++;
            k = j + 1;
            break;
        }
    }
}
printf("%d\n", length);

for(int i = 0; i < length; i++){
    printf("%d ", ans[i]);
}
return 0;
}
