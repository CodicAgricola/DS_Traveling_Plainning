#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    string map[110];
    int happiness[110];
    int open[110];
    int close[110];
    bool visited[110];
    int edge[110][110];
    int n, m;
    int t, b;

    cin>>n>>m>>t>>b;

    //initialize
    for(int i = 0; i<n; i++) {
        visited[i] = false;
        for(int j = 0; j<n; j++) {
            edge[i][j] = -1;
        }
    }
    //input vertex
    for(int i = 0; i<n; i++) {
        string name;
        int h, open_time, close_time;
        cin >> name >> h >> open_time >> close_time;
        map[i] = name;
        happiness[i] = h;
        open[i] = open_time;
        close[i] = close_time;
    }
    //input edge
    for(int i = 0; i<m; i++) {
        string from, to;
        int cost;
        int from_id = -1;
        int to_id = -1;
        cin >> from >> to >> cost;
        //find from
        for(int j = 0; j<n; j++) {
            if(from == map[j]) from_id = j;
            if(to == map[j]) to_id = j;
            if(from_id != -1 && to_id != -1) break; // founded
        }
        edge[from_id][to_id] = cost;
        edge[to_id][from_id] = cost;
    }

    for(int i = 0; i<n; i++) {
        cout << map[i] << " " << happiness[i] << " " << open[i] << " " << close[i];
        for(int j = 0; j<n; j++) {
            if(edge[i][j] != -1) cout << " " << edge[i][j];
        }
        cout << endl;
    }
}