#include <iostream>
#include <cmath>
using namespace std;
int solution(int n){
  int* q = new int[n];
  int sol = 0, c = 0;
	q[0] = 0;
	bool next_col = true;
	
	while(c >= 0){
	    if(next_col){
	      q[c] = 0;
	      next_col = false;
	    }
	    else q[c]++;
	        if(q[c] >= n){
             c--;
             continue;
            }
            bool ans = true;
	         for(int i = 0; i < c; i++)
	        	if(q[i] == q[c]) ans = false;
	        for(int i = 0; i < c; i++)
		        if((c - i) == abs(q[c] - q[i])) ans = false;
       	    if(ans){
            	if(c == (n - 1))
                sol++;
            	else{
                 c++;
                 next_col = true;
            	}
            }
	} 
  return sol;
  delete [] q;
}
int main(){
	int n;
	cout << "Please enter the number of Queens: ";
	cin >> n;
	cout << endl;
	for(int i = 1; i <= n; i++){
	    cout << "There are " << solution(i) << " solutions to the " << 
i << " Queens problem." << endl;
	}
	return 0;
}
