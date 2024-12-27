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
Node* build(vector<int>&post,int plo,int phi,vector<int>in,int ilo,int ihi){
         if(plo>phi)return NULL;
         Node* root=new Node(post[phi]);
         if(plo==phi) return root;
         int i=ilo;
         while(i<=ihi){
            if(in[i]==post[phi]) break;
            i++;
         }
         int lcnt=i-ilo;
         int rcnt=ihi-i;
         root->left=build(post,plo,plo+lcnt-1,in,ilo,i-1);
         root->right=build(post,phi-rcnt,phi-1,in,i+1,ihi);
         return root;
   }
    Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        return build(postorder,0,n-1,inorder,0,n-1);
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
    vector<int>inorder={9,3,15,20,7};
    vector<int>postorder={9,15,7,20,3};
    Node* a =buildTree(inorder,postorder);
    display(a);
    return 0;
}
