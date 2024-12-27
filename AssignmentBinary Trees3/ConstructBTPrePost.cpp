#include<iostream>
#include<climits>
#include<vector>
#include<queue>
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
  Node* build(vector<int>& pre, int prlo, int prhi, vector<int> post, int pslo, int pshi) {
        if (prlo > prhi || pslo > pshi)
            return NULL;
        Node* root = new Node(pre[prlo]);
        if (prlo == prhi)
            return root;
        int lrv = pre[prlo + 1];
        int lridx = pslo;
        while (post[lridx] != lrv)
            lridx++;
        int lrsize = lridx - pslo + 1;
        root->left = build(pre,prlo+1,prlo+lrsize,post,pslo,lridx);
        root->right = build(pre,prlo+lrsize+1,prhi,post,lridx+1,pshi-1);
        return root;
    }
    Node* constructFromPrePost(vector<int>& preorder,vector<int>& postorder) {
        int n = preorder.size();
        return build(preorder, 0, n - 1, postorder, 0, n - 1);
    }
void display(Node* root){
    if(root==NULL){
      return ;  
    } 
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}
int main()
{
    vector<int>preorder={1,2,4,5,3,6,7};
    vector<int>postorder={4,5,2,6,7,3,1};
    Node* a =constructFromPrePost(preorder,postorder);
    display(a);
    return 0;
}
