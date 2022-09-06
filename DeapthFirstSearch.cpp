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
		for (i = adjacnyList[node].begin(); i != adjacnyList[node].end(); ++i) {
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

	cout << "Following is Depth First Traversal (starting from vertex 2) \n";
	g.DFS();

	return 0;
}