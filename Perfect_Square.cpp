#include <iostream>
using namespace std;
int perfectSquare(){                                  
     for (int i = 1; i <= 2147483647; i++){ //max value for int variable
      int aPerfectSquare = i * i;
      if (aPerfectSquare % 2 == 1 && (aPerfectSquare / 10) % 2 == 1){
        return aPerfectSquare;
      }
  }
}
int main(){
  cout << perfectSquare();
  
}    
    
   
