#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int c, count;
  int b[8] = {0};
  c = 0;
  count = 1;

  ncol:
  c++;
  if (c == 8) goto print;
  b[c] = -1;

  nrow:
  b[c]++;
  if (b[c] == 8) goto backtrack;

  for (int i = 0; i < c; i++){
     if (b[i] == b[c] || (c - i) ==  abs(b[c] - b[i]))
     goto nrow;
     }
     goto ncol;

  backtrack:
  c--;
  if (c == -1) return 0;
  goto nrow;

  print:
  cout << "Solution number " << count << ":" << endl;
  for (int i = 0; i < 8; i++){
    cout << b[i] << " ";
  }
  count++;
  cout << endl;
  goto backtrack;
}
