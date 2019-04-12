#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
bool hasPath_DFS(unordered_map<int, vector<int>* > &adjacencyList, int v1, int v2,
unordered_map<int, bool> &visited) {
vector<int> *adjacentVertices = adjacencyList[v1];
// Check if v1 and v2 are directly connected
for(int i = 0; i < adjacentVertices -> size(); i++) {
if(adjacentVertices -> at(i) == v2) {
return true;
}
}
// Mark it visited to avoid calling over this vertex again
visited[v1] = true;
// Recursion call
for(int i = 0; i < adjacentVertices -> size(); i++) {
if(visited.count(adjacentVertices -> at(i)) == 0) {
bool ans = hasPath_DFS(adjacencyList, adjacentVertices -> at(i), v2, visited);
if(ans) {
return true;
}
}
}
return false;
}
bool hasPath_DFS(unordered_map<int, vector<int>* > &adjacencyList, int v1, int v2) {
unordered_map<int, bool> visited;
return hasPath_DFS(adjacencyList, v1, v2, visited);
}
int main() {
int n, e;
cin >> n >> e;
// Taking graph input and creating an adjacency list
unordered_map<int, vector<int>* > adjacencyList;
for(int i = 0; i < n; i++) {
vector<int> *v = new vector<int>;
adjacencyList[i] = v;
}
int count = 1;
while(count <= e) {
int source, dest;
cin >> source >> dest;
adjacencyList[source] -> push_back(dest);
adjacencyList[dest] -> push_back(source);
count++;
}
int v1, v2;
cin >> v1 >> v2;
if(hasPath_DFS(adjacencyList, v1, v2)) {
cout<< "true" << endl;
}
else {
cout<< "false" << endl;
}
return 0;
}
