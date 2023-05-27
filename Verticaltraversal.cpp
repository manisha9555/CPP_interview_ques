class Solution {
public:
void traversalleft(Node*root,vector<int> &ans){
    if((root==NULL)|| (root->left==NULL && root->right==NULL ))
         return;
    ans.push_back(root->data);
     if(root->left)
        traversalleft(root->left,ans);
        else
            traversalleft(root->right,ans);
}
void traversaleaf(Node*root,vector<int>&ans){
    if(root==NULL)
    return;
    if(root->left==NULL && root->right==NULL){
    ans.push_back(root->data);
    return;
}
    traversaleaf(root->left,ans);
   traversaleaf(root->right,ans);
}
void traversaright(Node*root,vector<int>&ans){
    if(root==NULL)
        return;
     if((root==NULL)||(root->left==NULL && root->right==NULL)){
            return;
        }
        if(root->right)
                        traversaright(root->right,ans);
                else
                        traversaright(root->left,ans);
                        
                        
                        ans.push_back(root->data);
            
}
    vector <int> boundary(Node *root)
    {
       vector<int>ans;
       if(root==NULL)
       return ans;
       ans.push_back(root->data);
       traversalleft(root->left,ans);
       //traverse leaf
          traversaleaf(root->left,ans);
             traversaleaf(root->right,ans);
             traversaright(root->right,ans);
         return ans;
       }
};
