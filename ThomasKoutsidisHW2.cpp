#include <iostream>
using namespace std;
bool equivalent(int a[], int b[], int n){
  int shift;
  for (int i = 0; i < n; i++){
   shift = 0;
    for (int j = 0; j < n; j++){
     if (a[j] == b[(j + i) % n])
     shift++;
     if (shift == n) return true;
    }
  }
  return false;
}
int main(){
  int a[] = {1, 2, 3, 4, 5};
  int b[] = {3, 4, 5, 1, 2};


  cout << equivalent(a, b, 5);
}
