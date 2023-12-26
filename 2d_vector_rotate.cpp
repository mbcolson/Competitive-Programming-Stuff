#include <bits/stdc++.h>
using namespace std;

/* Rotates the 2d vector 90 degress clockwise */
vector<vector<int>> rotate(vector<vector<int>>& v) {
    int n = v.size(), m = v[0].size();
    vector<vector<int>> res(m, vector<int>(n, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            res[j][n - 1 - i] = v[i][j]; 
    }

    return res;
}
    
int main() {
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = grid.size(), m = grid[0].size();       

    grid = rotate(grid);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }

        cout << endl;
    }

   /*  [7 4 1]        [9 8 7]         [3 6 9]         [1 2 3]
       [8 5 2]  -->   [6 5 4]   -->   [2 5 8]   -->   [4 5 6]
       [9 6 3]        [3 2 1]         [1 4 7]         [7 8 9]   */
  
    return 0;
}
