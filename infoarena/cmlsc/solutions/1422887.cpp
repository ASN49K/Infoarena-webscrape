#include <iostream>
#include <fstream>
using namespace std;
ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
int a[1025],b[1025],v[1025],m,n,i,j,l=1;
void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      }
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

int main(){
  fi >> n >> m;
  for(i=1;i<=n;i++) fi >> a[i];
  for(i=1;i<=m;i++) fi >> b[i];
  i = 1; j = 1;
  quickSort(a,1,n);
  quickSort(b,1,m);
  while(i<=n or j<=m){
    if(a[i] < b[j]) i++;
    else if(a[i] > b[j]) j++;
    else if(a[i] == b[j]){
      v[l] = a[i]; l++;
      i++; j++;
    }
  }
  fo << l-1 << endl;
  for(i=1;i<=l-1;i++) fo << v[i] << ' ';
  return 0;
}
