#include<iostream>
using namespace std;
const int rows = 5;
const int cols = 6;
int toPath[] = {6};
struct memoArray {
    int value;
    int direction;
};
memoArray memo[rows][cols] = {0};
int cost(int i, int j){
    int weight[rows][cols]={
        {3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,8,6,4}
      
    };
    
    if(j == 0) return weight[i][0];
    if(memo[i][j].value != 0) return memo[i][j].value;
    
    int left = weight[i][j] + cost(i, j - 1);
    int up = weight[i][j] + cost(i - 1 >= 0 ? i - 1 : rows - 1, j - 1);
    int down = weight[i][j]+cost(i + 1 <= rows - 1 ? i + 1 : 0, j - 1);
    int min = left;
    if(up < min){
        min = up;
        memo[i][j].direction = -1;
    }
    if(down < min){
        min = down;
        memo[i][j].direction = 1;
    }
    return memo[i][j].value = min;
}
int main(){
    int ex[rows];
    for(int i = 0; i < rows; i++){
        ex[i] = cost(i, cols - 1);
    }
    int min = ex[0];
    
    for(int i = 1; i < rows; i++)
        if(min > ex[i]){
            min = ex[i];
            toPath[0] = i;
        }
    int j = 6;
    for(int k = 1; k < 6; k++){
        toPath[k] = toPath[k - 1] + memo[toPath[k - 1]][--j].direction;
    }
    cout<<"The shortest path is of length: "<< min <<". It costs: "<< 
endl;
    for(int g = 5; g >= 0; g--){
        cout << toPath[g] << " ";
    }
    cout << endl;
    
    return 0;
}
