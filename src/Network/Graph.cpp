#include "Graph.h"

Graph::Graph()
{
    cityCount = 0;

    for (int i = 0; i < MAX; i++)
    {
        head[i] = NULL;

        for (int j = 0; j < MAX; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

Graph::~Graph()
{
    for (int i = 0; i < MAX; i++)
    {
        Edge* temp = head[i];

        while (temp != NULL)
        {
            Edge* del = temp;
            temp = temp->next;
            delete del;
        }
    }
}

int Graph::findCity(string name) const
{
    for (int i = 0; i < cityCount; i++)
    {
        if (cities[i] == name)
        {
            return i;
        }
    }

    return -1;
}

// Add Location
bool Graph::addLocation(string name)
{
    if (cityCount >= MAX)
    {
        cout << "Maximum city limit reached!" << endl;
        return false;
    }

    if (name == "")
    {
        cout << "City name cannot be empty!" << endl;
        return false;
    }

    if (findCity(name) != -1)
    {
        cout << "City already exists!" << endl;
        return false;
    }

    cities[cityCount] = name;
    head[cityCount] = NULL;

    cityCount++;

    cout << "City added successfully!" << endl;

    return true;
}

// Add Road
bool Graph::addRoad(string source, string destination, double distance)
{
    int src = findCity(source);
    int dest = findCity(destination);

    if (src == -1 || dest == -1)
    {
        cout << "City not found!" << endl;
        return false;
    }

    if (src == dest)
    {
        cout << "Road cannot connect a city to itself!" << endl;
        return false;
    }

    if (distance <= 0)
    {
        cout << "Distance must be greater than zero!" << endl;
        return false;
    }

    if (matrix[src][dest] != 0)
    {
        cout << "Road already exists!" << endl;
        return false;
    }

    // Add road in source linked list
    Edge* newEdge = new Edge;

    newEdge->destination = dest;
    newEdge->distance = distance;
    newEdge->next = head[src];

    head[src] = newEdge;

    // Add road in destination linked list
    Edge* newEdge2 = new Edge;

    newEdge2->destination = src;
    newEdge2->distance = distance;
    newEdge2->next = head[dest];

    head[dest] = newEdge2;

    // Update adjacency matrix
    matrix[src][dest] = distance;
    matrix[dest][src] = distance;

    cout << "Road added successfully!" << endl;

    return true;
}

// Display Network
void Graph::displayNetwork() const
{
    if (cityCount == 0)
    {
        cout << "Network is empty!" << endl;
        return;
    }

    cout << "\n===== DELIVERY NETWORK =====" << endl;

    for (int i = 0; i < cityCount; i++)
    {
        cout << cities[i] << " -> ";

        Edge* temp = head[i];

        if (temp == NULL)
        {
            cout << "No roads";
        }

        while (temp != NULL)
        {
            cout << cities[temp->destination]
                 << " (" << temp->distance << " km)";

            if (temp->next != NULL)
            {
                cout << ", ";
            }

            temp = temp->next;
        }

        cout << endl;
    }
}

// BFS
void Graph::bfs(string start) const
{
    int startIndex = findCity(start);

    if (startIndex == -1)
    {
        cout << "City not found!" << endl;
        return;
    }

    bool visited[MAX] = {false};

    int queue[MAX];
    int front = 0;
    int rear = 0;

    visited[startIndex] = true;
    queue[rear++] = startIndex;

    cout << "BFS: ";

    while (front < rear)
    {
        int current = queue[front++];

        cout << cities[current] << " ";

        Edge* temp = head[current];

        while (temp != NULL)
        {
            int next = temp->destination;

            if (!visited[next])
            {
                visited[next] = true;
                queue[rear++] = next;
            }

            temp = temp->next;
        }
    }

    cout << endl;
}

// DFS Helper
void Graph::dfsRec(int index, bool visited[]) const
{
    visited[index] = true;

    cout << cities[index] << " ";

    Edge* temp = head[index];

    while (temp != NULL)
    {
        int next = temp->destination;

        if (!visited[next])
        {
            dfsRec(next, visited);
        }

        temp = temp->next;
    }
}

// DFS
void Graph::dfs(string start) const
{
    int startIndex = findCity(start);

    if (startIndex == -1)
    {
        cout << "City not found!" << endl;
        return;
    }

    bool visited[MAX] = {false};

    cout << "DFS: ";

    dfsRec(startIndex, visited);

    cout << endl;
}

// Reachability
bool Graph::isReachable(string source, string destination) const
{
    int src = findCity(source);
    int dest = findCity(destination);

    if (src == -1 || dest == -1)
    {
        return false;
    }

    bool visited[MAX] = {false};

    int queue[MAX];
    int front = 0;
    int rear = 0;

    visited[src] = true;
    queue[rear++] = src;

    while (front < rear)
    {
        int current = queue[front++];

        if (current == dest)
        {
            return true;
        }

        Edge* temp = head[current];

        while (temp != NULL)
        {
            int next = temp->destination;

            if (!visited[next])
            {
                visited[next] = true;
                queue[rear++] = next;
            }

            temp = temp->next;
        }
    }

    return false;
}

// Shortest Path using Dijkstra
void Graph::shortestPath(string source, string destination) const
{
    int src = findCity(source);
    int dest = findCity(destination);

    if (src == -1 || dest == -1)
    {
        cout << "City not found!" << endl;
        return;
    }

    double distance[MAX];
    bool visited[MAX] = {false};
    int parent[MAX];

    for (int i = 0; i < cityCount; i++)
    {
        distance[i] = 999999;
        parent[i] = -1;
    }

    distance[src] = 0;

    for (int count = 0; count < cityCount; count++)
    {
        int current = -1;
        double minimum = 999999;

        for (int i = 0; i < cityCount; i++)
        {
            if (!visited[i] && distance[i] < minimum)
            {
                minimum = distance[i];
                current = i;
            }
        }

        if (current == -1)
        {
            break;
        }

        visited[current] = true;

        for (int i = 0; i < cityCount; i++)
        {
            if (matrix[current][i] > 0 && !visited[i])
            {
                double newDistance =
                    distance[current] + matrix[current][i];

                if (newDistance < distance[i])
                {
                    distance[i] = newDistance;
                    parent[i] = current;
                }
            }
        }
    }

    if (distance[dest] == 999999)
    {
        cout << "No route exists!" << endl;
        return;
    }

    // Build path in reverse order
    int path[MAX];
    int pathCount = 0;

    int current = dest;

    while (current != -1)
    {
        path[pathCount++] = current;
        current = parent[current];
    }

    cout << "\nShortest Path: ";

    for (int i = pathCount - 1; i >= 0; i--)
    {
        cout << cities[path[i]];

        if (i > 0)
        {
            cout << " -> ";
        }
    }

    cout << "\nTotal Distance: "
         << distance[dest] << " km" << endl;
}

