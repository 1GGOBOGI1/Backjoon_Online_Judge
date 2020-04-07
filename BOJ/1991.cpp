#include <iostream>
#include <vector>
using namespace std;

struct childNode
{
    int leftChild = -1;
    int rightChild = -1;
};

void preOrder(vector<childNode> &graph, int node)
{
    cout << static_cast<char>(node + 'A' - 1);

    if (graph[node].leftChild != -1)
        preOrder(graph, graph[node].leftChild);

    if (graph[node].rightChild != -1)
        preOrder(graph, graph[node].rightChild);
}

void inOrder(vector<childNode> &graph, int node)
{
    if (graph[node].leftChild != -1)
        inOrder(graph, graph[node].leftChild);

    cout << static_cast<char>(node + 'A' - 1);

    if (graph[node].rightChild != -1)
        inOrder(graph, graph[node].rightChild);
}

void postOrder(vector<childNode> &graph, int node)
{
    if (graph[node].leftChild != -1)
        postOrder(graph, graph[node].leftChild);

    if (graph[node].rightChild != -1)
        postOrder(graph, graph[node].rightChild);

    cout << static_cast<char>(node + 'A' - 1);
}

int main()
{
    int N;
    cin >> N;

    vector<childNode> graph(N + 1);

    while (N--)
    {
        char node, leftChild, rightChild;
        cin >> node >> leftChild >> rightChild;

        if (leftChild != '.')
            graph[node - 'A' + 1].leftChild = leftChild - 'A' + 1;
        if (rightChild != '.')
            graph[node - 'A' + 1].rightChild = rightChild - 'A' + 1;
    }

    preOrder(graph, 1);
    cout << "\n";
    inOrder(graph, 1);
    cout << "\n";
    postOrder(graph, 1);
}