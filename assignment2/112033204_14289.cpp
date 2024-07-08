#include <iostream>
#include <queue>


using namespace std;

struct Node {
    int x;
    int y;
    int step;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    char gaze[n][m];
    int startx, starty, endx, endy;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> gaze[i][j];
            if (gaze[i][j] == 'A') {
                startx = i;
                starty = j;
            } else if (gaze[i][j] == 'B') {
                endx = i;
                endy = j;
            }
        }
    }

    queue<Node> q;
    q.push({startx, starty, 0});
    gaze[startx][starty] = '#';

    int step = -1;
    bool found = false;

    while (!q.empty()) {
        Node current = q.front();
        q.pop();

        if (current.x == endx && current.y == endy) {
            found = true;
            step = current.step;
            break;
        }


        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (const auto &dir : directions) {
            int nx = current.x + dir.first;
            int ny = current.y + dir.second;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && gaze[nx][ny] != '#') {
                q.push({nx, ny, current.step + 1});
                gaze[nx][ny] = '#';
            }
        }
    }

    if (found) {
        cout << "YES\n";
        cout << step << '\n';
    } else {
        cout << "NO\n";
    }

    return 0;
}
