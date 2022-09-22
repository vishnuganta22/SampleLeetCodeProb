#include <iostream>
#include <map>
#include <list>

using namespace std;

class Graph {
private:
	void DFSUtils(int node) {
		nodeVisited[node] = true;

		cout << node << " ";
		list<int>::iterator i;
		for (auto i = adjacnyList[node].begin(); i != adjacnyList[node].end(); ++i) {
			if (!nodeVisited[*i]) {
				DFSUtils(*i);
			}
		}
	}
public:
	map<int, bool> nodeVisited;
	map<int, list<int>> adjacnyList;

	void addEdge(int v, int w) {
		adjacnyList[v].push_back(w);
	}

	void DFS() {
		for (auto i : adjacnyList)
			if (nodeVisited[i.first] == false)
				DFSUtils(i.first);
		clearNodeVisited();		
	}

	void baseDFSUtils(int node){
		if(nodeVisited[node] == true) return;

		nodeVisited[node] = true;
		cout << node << " ";
		for (auto i = adjacnyList[node].begin(); i != adjacnyList[node].end(); ++i) {
			if (!nodeVisited[*i]) {
				baseDFSUtils(*i);
			}
		}
	}
	
	void baseDFS(int node){
	    baseDFSUtils(node);
	    clearNodeVisited();
	}
	
	void clearNodeVisited(){
	    nodeVisited.clear();
	}
};

int main() {
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 9);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(9, 3);

	cout << "Following is Depth First Traversal \n";
	g.DFS();
	cout << "\n Following is Depth First Traversal with base case \n";
	g.baseDFS(2);
	return 0;
}