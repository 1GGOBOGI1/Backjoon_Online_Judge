#include <iostream>
#include <set>
using namespace std;

struct Node
{
    int value;
    Node *leftChild = nullptr;
    Node *rightChild = nullptr;

    Node(int n) : value(n) {}
};
struct BST
{
    Node *root = nullptr;

    void insert(Node *input)
    {
        if (root == nullptr)
        {
            root = input;
            return;
        }
        Node *tmp = root;

        while (true)
        {
            if (tmp->value > input->value)
            {
                if (tmp->leftChild == nullptr)
                {
                    tmp->leftChild = input;
                    break;
                }
                tmp = tmp->leftChild;
            }
            else if (tmp->value < input->value)
            {
                if (tmp->rightChild == nullptr)
                {
                    tmp->rightChild = input;
                    break;
                }
                tmp = tmp->rightChild;
            }
        }
    }

    string startPreOrder()
    {
        string output = "s";

        output += preOrder(root);

        return output;
    }

    string preOrder(Node *tmp)
    {
        string output = "";

        if (tmp->leftChild != nullptr)
            output = output + "L" + preOrder(tmp->leftChild) + "l";

        if (tmp->rightChild != nullptr)
            output = output + "R" + preOrder(tmp->rightChild) + "r";

        return output;
    }
};

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    set<string> ans;

    while (n--)
    {
        int input;
        BST bst;
        for (int i = 0; i < k; i++)
        {
            cin >> input;
            Node *tmp = new Node(input);
            bst.insert(tmp);
        }
        ans.insert(bst.startPreOrder());
    }

    printf("%d", (int)ans.size());
}