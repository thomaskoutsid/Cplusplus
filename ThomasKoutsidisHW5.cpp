#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdlib.h>
using namespace std;
bool canGo(int b[], int c);
void print(int b[]);
void backtrack(int b[], int &c);
int main(){

  int b[8] = {}, c = 0;
  b[0] = 0;

    while (c >= 0) {
      c++;
      if (c == 8) {
        print(b);
        backtrack(b, c);
    } else {
        b[c] = -1;
    } while (c >= 0) {
      b[c]++;
        if (b[c] == 8) backtrack(b, c);
        else if (canGo(b, c))break;
        }

    }

  return 0;
}
bool canGo(int b[], int c) {
  for (int i = 0; i < c; i++) {
    if (b[i] == b[c] || (c - i) == abs(b[c] - b[i]))
      return false;
  }
  return true;
}
void print(int b[]) {
  static int count = 0;
  cout << "Solution number " << count << ": ";
  for (int i = 0; i < 8; i++) {
    cout << b[i] << " ";
  }
  count++;
  cout << endl;
}
void backtrack(int b[], int &c) {
  c--;
  if (c == -1) exit(0);
  b[c]++;
}
