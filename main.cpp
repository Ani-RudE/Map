#include <bits/stdc++.h>
using namespace std;
int NO_PARENT = -1;
void printPath(int currentVertex, vector<int> parents)
{
	if (currentVertex == NO_PARENT)
	{
		return;
	}
	printPath(parents[currentVertex], parents);
	cout << currentVertex << " ";
}
void printSolution(int startVertex, int endvertex, vector<int> distances, vector<int> parents)
{
	int nVertices = distances.size();
	cout << "Vertex\t Distance\tPath";
	for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++)
	{
		if (vertexIndex == endvertex)
		{
			cout << "\n"
				 << startVertex+1 << " -> ";
			cout << vertexIndex+1 << " \t\t ";
			cout << distances[vertexIndex] << "\t\t";
			printPath(vertexIndex, parents);
		}
	}
}
void dijkstra(vector<vector<int>> adjacencyMatrix, int startVertex, int endvertex)
{
	int nVertices = adjacencyMatrix[0].size();
	vector<int> shortestDistances(nVertices);
	vector<bool> added(nVertices);
	for (int vertexIndex = 0; vertexIndex < nVertices;
		 vertexIndex++)
	{
		shortestDistances[vertexIndex] = INT_MAX;
		added[vertexIndex] = false;
	}
	shortestDistances[startVertex] = 0;
	vector<int> parents(nVertices);
	parents[startVertex] = NO_PARENT;
	for (int i = 1; i < nVertices; i++)
	{
		int nearestVertex = -1;
		int shortestDistance = INT_MAX;
		for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++)
		{
			if (!added[vertexIndex] && shortestDistances[vertexIndex] < shortestDistance)
			{
				nearestVertex = vertexIndex;
				shortestDistance = shortestDistances[vertexIndex];
			}
		}
		added[nearestVertex] = true;
		for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++)
		{
			int edgeDistance = adjacencyMatrix[nearestVertex][vertexIndex];
			if (edgeDistance > 0 && ((shortestDistance + edgeDistance) < shortestDistances[vertexIndex]))
			{
				parents[vertexIndex] = nearestVertex;
				shortestDistances[vertexIndex] = shortestDistance + edgeDistance;
			}
		}
	}
	printSolution(startVertex, endvertex, shortestDistances, parents);
}
int main()
{
	vector<vector<int>> adjacencyMatrix = {{0, 10, 13, 18, 20, 19, 13, 8},
										   {10, 0, 5, 17, 15, 20, 17, 10},
										   {13, 5, 0, 12, 10, 18, 15, 8},
										   {18, 17, 12, 0, 7, 6, 3, 5},
										   {20, 15, 10, 7, 0, 14, 10, 8},
										   {19, 20, 18, 6, 10, 0, 3, 8},
										   {13, 17, 15, 3, 10, 2, 0,5},
										   {8, 10, 8, 4, 5, 10, 8, 0}};
	ifstream file;
	file.open("ascii-art.txt");
	if (!file.is_open())
	{
		cout << "Unable to open the file." << endl;
		return 0;
	}

	string line;
	while (getline(file, line))
	{
		cout << line << endl;
	}

	file.close();
	while (true)
	{
		int a, b;
		cout << "Enter the source and destination vertex" << endl;
		cin >> a >> b;
		a -= 1;
		b -= 1;
		dijkstra(adjacencyMatrix, a, b);
		int c;
		cout << "Enter 1 to continue" << endl;
		cin >> c;
		if (c == 0)
			break;
	}
	return 0;
}
