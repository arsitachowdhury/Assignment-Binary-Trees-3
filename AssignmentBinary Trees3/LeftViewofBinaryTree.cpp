#include <iostream>
#include <queue>
#include <climits>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *Construct(int arr[], int n)
{
    queue<Node *> q;
    Node *root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    int j = 2;
    while (q.size() > 0 && i < n)
    {
        Node *temp = q.front();
        q.pop();
        Node *l;
        Node *r;
        if (arr[i] != INT_MIN)
            l = new Node(arr[i]);
        else
            l = NULL;
        if (arr[j] != INT_MIN)
            r = new Node(arr[j]);
        else
            r = NULL;
        temp->left = l;
        temp->right = r;
        if (l != NULL)
            q.push(l);
        if (r != NULL)
            q.push(r);
        i += 2;
        j += 2;
    }
    return root;
}
void leftBoundary(Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;
    cout << root->val << " ";
    leftBoundary(root->left);
    if (root->left == NULL)
        leftBoundary(root->right);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6,7, 8, 9, INT_MIN};
    int n = sizeof(arr) / sizeof(int);
    Node *root = Construct(arr, n);
    leftBoundary(root);
    cout<<endl;
    return 0;
}