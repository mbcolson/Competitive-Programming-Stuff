#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Floyd-Warshall Algorithm (runs in O(n^3))
// Pre-condition: m[i][j] contains the weight of edge (i,j) or INF
//                if there is no edge
// Post-condition: m[i][j] contains the minimum cost from vertex i
                   to vertex j. INF indicates that vertex j is
                   unreachable from vertex i.
int main() {
    const ll INF = INT_MAX;
    vector<vector<ll>> m(20, vector<ll>(20, INF));

    for(int i = 0; i < 20; i++)
        m[i][i] = 0;

    // Add edge weights
    m[0][5] = 200;
    m[2][6] = 100;
    m[3][8] = 120;
    m[9][2] = 250;
    m[12][6] = 140;
    m[5][16] = 180;
    m[1][4] = 300;
    m[17][8] = 210;
    m[19][3] = 190;
    m[10][2] = 400;
    m[1][17] = 250;
    m[6][14] = 300;
    m[18][11] = 250;
    m[10][14] = 350;
    m[4][16] = 100;
    m[11][14] = 150;
    m[0][10] = 200;
    m[0][16] = 250;
    m[19][5] = 300;

    for(int k = 0; k < 20; k++)
        for(int i = 0; i < 20; i++)
            for(int j = 0; j < 20; j++)
                m[i][j] = min(m[i][j], m[i][k] + m[k][j]);

    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            if (m[i][j] == INF)
                cout << "INF ";
            else
                cout << m[i][j] << " ";       
        }
        cout << endl;
    } 
        
    return 0;
}
