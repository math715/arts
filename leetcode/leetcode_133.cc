
#include <map>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	if (node == nullptr) {
		return nullptr;
	}
	UndirectedGraphNode *result = new UndirectedGraphNode(node->label);
	map<UndirectedGraphNode *, UndirectedGraphNode*> graph_map;
	graph_map[node] = result;
	queue<UndirectedGraphNode*> que;
	que.push(node);
	while(!que.empty()) {
		auto n = que.front();
		que.pop();
		for (auto &neighbor : n->neighbors){
			if ( graph_map.find(neighbor) == graph_map.end()){
				graph_map[neighbor] = new UndirectedGraphNode(neighbor->label);
				que.push(neighbor);
			}
			graph_map[n]->neighbors.push_back(graph_map[neighbor]);

		}
	}
	return result;

}
