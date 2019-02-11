#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    vector<int> res;
    if (n <= 2) {
	for (int i = 0; i < n; ++i) {
	    res.push_back(i);
	}
	return res;
    }
    vector<unordered_set<int>> graph;
    graph.resize(n);
    for (auto edge : edges) {
	graph[edge.first].insert(edge.second);
	graph[edge.second].insert(edge.first);
    }
    queue<int> que;
    for (int i = 0; i < n; ++i) {
	if (graph[i].size() == 1) {
	    que.push(i);
	}
    }
    while (n>2) {
	n = n - que.size();
	queue<int> new_que;
	while (!que.empty()) {
	    int cur = que.front();
	    que.pop();
	    int next_leaf = *(graph[cur].begin());
	    graph[next_leaf].erase(cur);
	    if (graph[next_leaf].size() == 1) {
		new_que.push(next_leaf);
	    }
	}
	que = new_que;
    }	
    while (!que.empty()){
	int leaf = que.front();
	que.pop();
	res.push_back(leaf);
    }
    return res;
}

int main( int argc, char *argv[] ) {
    int n = 6;
    vector<pair<int, int>> edges = { {0, 3}, {1, 3}, {2, 3}, {3, 4}, {4, 5}};
    auto vs = findMinHeightTrees(n, edges);
    for (auto v : vs ){
	cout << v << endl;
    }

    return 0;
}
