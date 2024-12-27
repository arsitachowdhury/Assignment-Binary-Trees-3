#include<iostream>
#include<climits>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
 bool hasPathSum(Node* root, int targetSum) {
        if (root == nullptr) return false; 
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
int main()
{
    Node* a=new Node(5);
    Node* b=new Node(4);
    Node* c=new Node(8);
    Node* d=new Node(11);
    Node* e=new Node(13);
    Node* f=new Node(4);
    Node* g=new Node(7);
    Node* h=new Node(2);
    Node* i=new Node(1);
     a->left=b;
     a->right=c;
     b->left=d;
     d->left=g;
     d->right=h;
     c->left=e;
     c->right=f;
     f->right=i;
     int target=22;
     if(hasPathSum(a,target)) cout<<"True";
     else cout<<"False";
    return 0;
}
