#include <queue>
#include <iostream>
#include <unordered_map>
using namespace std;
void printBFS(int** edges, int n, bool* visited) {
queue<int> pendingVertices;
int sv = 0;
pendingVertices.push(sv); // starting vertex = 0
visited[sv] = true;
while (!pendingVertices.empty()) {
int currentVertex = pendingVertices.front();
pendingVertices.pop();
cout << currentVertex << " " ;
for (int i = 0; i < n; i++) {
if (i == currentVertex) {
continue;
}
if (edges[currentVertex][i] == 1 && !visited[i]) {
pendingVertices.push(i);
visited[i] = true;
}
}
}
}
void BFS(int** edges, int n) {
bool * visited = new bool[n];
for (int i = 0; i < n; i++) {
visited[i] = false;
}
printBFS(edges, n, visited);
delete [] visited;
}
int main() {
int n;
int e;
cin >> n >> e;
int** edges = new int*[n];
for (int i = 0; i < n; i++) {
edges[i] = new int[n];
for (int j = 0; j < n; j++) {
edges[i][j] = 0;
}
}
for (int i = 0; i < e; i++) {
int f, s;
cin >> f >> s;
edges[f][s] = 1;
edges[s][f] = 1;
}
BFS(edges, n);
for (int i = 0; i < n; i++) {
delete [] edges[i];
}
delete [] edges;
}
