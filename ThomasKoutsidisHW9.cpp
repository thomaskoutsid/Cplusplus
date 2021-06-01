#include <iostream>
#include <cmath>
bool okQ(int q[], int c);
void print(int q[]);
using namespace std;
int count=0;
int main(){
  int q[8] , c = 0;
	q[0] = 0;
	bool next_col = true;
	while(c >= 0){
	    if(next_col){
	        q[c] = 0;
	        next_col = false;
	    }
	    else q[c]++;
	         if(q[c] >= 8){
            	c--;
            	continue;
            }
            if(okQ(q,c)){
            	if(c == 7) print(q);
            	else{
                    c++;
                    next_col = true;
            	}
            }
	}
}
bool okQ(int q[], int c){
    bool ans=true;
	for(int i = 0; i < c; i++){
		if(q[i] == q[c])
			ans = false;
	}
	for(int i = 0; i < c; i++){
		if((c-i) == abs(q[c] - q[i]))
			ans = false;
	}    
	return ans;
}
void print(int q[]){
    int i, j, k, l;
    typedef char box[5][7];
    box bb, wb, *board[8][8], wq, bq;
    for(i = 0; i < 5; i++)
        for(j = 0; j < 7; j++){
            wb[i][j] = ' ';
            bb[i][j] = char(219);
        }
    for(i = 0; i < 5; i++)
        for(j = 0; j < 7; j++){
            if(i == 0 || j == 0 || i == 4 || j == 6 || (i == 1 && j == 2) 
|| (i == 1 && j == 4)){
                wq[i][j] = ' ';
                bq[i][j] = char(219);
            }
            else{
                wq[i][j] = char(219);
                bq[i][j] = ' ';
            }
        }
        
    for(i = 0; i < 8; i++)
        for(j = 0; j < 8; j++)
            if((i + j) % 2 == 0) board[i][j] = &wb;
            else board[i][j] = &bb;
	cout<< "Solution number: " << ++count <<endl;
	for(int i = 0 ; i < 8; i++){
		if((i + q[i]) % 2 == 0) board[i][q[i]] = &wq;
		else board[i][q[i]] = &bq;
	}
    cout<<" ";
    for(int i = 0; i < 7*8; i++)
        cout << '_';
    cout << endl;
    for(int i = 0; i < 8; i++)
        for(int k = 0; k < 5; k++){
            cout << " " << char(179);
            for(int j = 0; j < 8; j++)
                for(int l = 0; l < 7; l++) cout << (*board[i][j])[k][l];
            cout << char(179) << endl;
        }
    cout << " ";
    for(int i = 0; i < 7*8 ;i++) cout << char(196);
    cout<<endl;
}
