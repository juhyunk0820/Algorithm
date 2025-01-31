#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;
    
    vector<vector<int>> map(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }
    
    vector<int> commands(k);
    for (int i = 0; i < k; ++i) {
        cin >> commands[i];
    }
    
    int up = 0, down = 0, east = 0, west = 0, north = 0, south = 0;
    int cur_x = x, cur_y = y;
    
    for (int cmd : commands) {
        int nx = cur_x, ny = cur_y;
        if (cmd == 1) ny += 1;
        else if (cmd == 2) ny -= 1;
        else if (cmd == 3) nx -= 1;
        else if (cmd == 4) nx += 1;
        
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        
        int temp;
        switch (cmd) {
            case 1:
                temp = up;
                up = west;
                west = down;
                down = east;
                east = temp;
                break;
            case 2:
                temp = up;
                up = east;
                east = down;
                down = west;
                west = temp;
                break;
            case 3:
                temp = up;
                up = south;
                south = down;
                down = north;
                north = temp;
                break;
            case 4:
                temp = up;
                up = north;
                north = down;
                down = south;
                south = temp;
                break;
        }
        
        cur_x = nx;
        cur_y = ny;
        
        if (map[cur_x][cur_y] == 0) {
            map[cur_x][cur_y] = down;
        } else {
            down = map[cur_x][cur_y];
            map[cur_x][cur_y] = 0;
        }
        
        cout << up << '\n';
    }
    
    return 0;
}