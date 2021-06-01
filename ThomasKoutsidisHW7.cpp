#include <iostream>
#include <cmath>
#include <cstdlib>
bool ok(int q[], int col);
void print(int q[], int count);
void backtrack (int &col);
using namespace std;
int main() {
    int c = 0, q[3], count = 0;
    q[3] = 0;
    bool test = false;
        while(true){
            while(c < 3){
                if(!test)
                    q[c] = -1;
                
                test = false;
        
                while(q[c] < 3){
                    q[c]++;     
                    if(q[c] == 3){
                        backtrack(c);
                        continue;
                    }
                    if (ok(q,c)) break;
                }
                c++;
            }
            print(q, ++count);
            backtrack(c);
            test = true;
        }
        return 0;
}

bool ok(int q[], int col){
    int mp[3][3]={{0,2,1},
                  {0,2,1},
                  {1,2,0}};
    int wp[3][3]={{2,1,0},
                  {0,1,2},
                  {2,0,1}};
    
    for (int i = 0; i < col; i++){
            if (q[col]==q[i]) return false;
        if((mp[i][q[col]] < mp[i][q[i]] && wp[q[col]][i] < wp[q[col]][col]) || (mp[col][q[i]] < mp[col][q[col]] && wp[q[i]][col] < wp[q[i]][i])) return false;
    }
    return true;
}

void backtrack(int &col){
    --col;
    if(col == -1) exit(1);
}

void print(int q[], int count){
    cout << "Solution number " << count << ": " << endl;
    for (int i = 0; i < 3; i++)
        cout <<  q[i] << " ";
    cout << endl;
}
