#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct vertex {
    typedef pair<int, vertex*> ve;
    vector<ve> adj; //cost of edge, destination vertex
    string name;
    int h, open, close;
    vertex(string s, int happiness, int open_time, int close_time) : name(s), h(happiness), 
    open(open_time), close(close_time) {}
};

class graph {
public:
    typedef map<string, vertex *> vmap;
    vmap work;
    void addvertex(const string&, const int h, const int open_time, const int close_time);
    void addedge(const string& from, const string& to, int cost);
    void printMap();
};

void graph::addvertex(const string &name, const int h, const int open_time, const int close_time) {
    vmap::iterator itr = work.find(name);
    if (itr == work.end()) {
        vertex *v;
        v = new vertex(name, h, open_time, close_time);
        work[name] = v;
        return;
    }
    cout << "\nVertex already exists!";
}

void graph::addedge(const string& from, const string& to, int cost) {
    vertex *f = (work.find(from)->second);
    vertex *t = (work.find(to)->second);
    pair<int, vertex *> edge = make_pair(cost, t);
    f->adj.push_back(edge);
}

void graph::printMap() {
    vmap::iterator itr;

    for(itr = work.begin(); itr != work.end(); itr++) {
        cout << itr->first << " " << work[itr->first]
    }
}

int main() {
    graph map;
    int n, m;
    int t, b;

    cin>>n>>m>>t>>b;

    for(int i = 0; i<n; i++) {
        string name;
        int h, open_time, close_time;
        cin >> name >> h >> open_time >> close_time;
        map.addvertex(name, h, open_time, close_time);
    }
    for(int i = 0; i<m; i++) {
        string from, to;
        int cost;
        cin >> from >> to >> cost;
        map.addedge(from, to, cost);
    }
    map.printMap();
}