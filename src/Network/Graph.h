#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>

using namespace std;

class Graph
{
private:
    static const int MAX = 20;

    string cities[MAX];
    int cityCount;

    double matrix[MAX][MAX];

    struct Edge
    {
        int destination;
        double distance;
        Edge* next;
    };

    Edge* head[MAX];

    int findCity(string name) const;

    void dfsRec(int index, bool visited[]) const;

public:
    Graph();
    ~Graph();

    bool addLocation(string name);

    bool addRoad(string source, string destination, double distance);

    void displayNetwork() const;

    void bfs(string start) const;

    void dfs(string start) const;

    bool isReachable(string source, string destination) const;

    void shortestPath(string source, string destination) const;

    void minimumSpanningTree() const;
};

#endif