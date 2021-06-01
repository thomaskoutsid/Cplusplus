#include <iostream>
#include <cmath>
#include <cstdlib>
bool works(int b[], int c);
void print(int b[]);
void next(int b[], int c);
using namespace std;
int main(){
   
   int b[8];
   next(b, 0);
   return 0;
   
}
bool works(int b[], int c) {
   static int cross[][5] = {
   {-1}, {0, -1}, {0, 1, -1}, {0, 2, -1}, {1, 2, -1}, {1, 2, 3, 4, -1}, 
   {2, 3, 5, -1}, {4, 5, 6, -1} };
   for(int i = 0; i < c; i++)
        if(b[c] == b[i]) return false;
   
   for(int i = 0; cross[c][i]!=-1 ; i++){ 
      if (b[cross[c][i]] + 1 == b[c] || b[cross[c][i]] - 1 == b[c])
        return false;
   }
   return true;
}
void print(int b[]) {
   static int count = 1;
   cout << "Solution number #" << count << ": " << endl;
   cout << " " << " " << b[1] << b[4] << endl;
   cout << " " << b[0] << b[2] << b[5] << b[7] << endl;
   cout << " " << " " << b[3] << b[6] << endl;
   cout << endl;
   count++;
}
void next(int b[], int c) {
   if (c == 8) print(b);
   else {
   for (b[c] = 1; b[c] < 9; ++b[c])
      if (works(b, c)) next(b, c + 1);
    }
}
