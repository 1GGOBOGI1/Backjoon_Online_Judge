#include <iostream>
#include <vector>
using namespace std;

struct node
{
    node(int _value)
    {
        this->value = _value;
    }
    int value = 0;
    node *leftChild = nullptr;
    node *rightChild = nullptr;
};

struct BST
{
    node *root = nullptr;

    void addNode(node *newNode)
    {
        if (root == nullptr)
        {
            root = newNode;
        }
        else
        {
            node *next = root;
            do
            {
                if (next->value > newNode->value)
                {
                    if (next->leftChild != nullptr)
                        next = next->leftChild;
                    else
                    {
                        next->leftChild = newNode;
                        break;
                    }
                }
                else
                {
                    if (next->rightChild != nullptr)
                        next = next->rightChild;
                    else
                    {
                        next->rightChild = newNode;
                        break;
                    }
                }
            } while (true);
        }
    }

    void postOrder(node *now)
    {
        if (now->leftChild != nullptr)
        {
            this->postOrder(now->leftChild);
        }
        if (now->rightChild != nullptr)
        {
            this->postOrder(now->rightChild);
        }
        cout << now->value << "\n";
    }
};

int main()
{
    int input;
    BST bst;
    while (cin >> input)
    {
        node *tmp = new node{input};
        bst.addNode(tmp);
    }
    bst.postOrder(bst.root);
}