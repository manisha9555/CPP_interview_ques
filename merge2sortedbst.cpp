void inorder(TreeNode<int> *root,vector<int>&in){
    if (root==NULL){
        return ;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
vector<int>mergearray(vector<int>&a,vector<int>&b){
    vector<int>ans(a.size()+b.size());    
int i=0,j=0,k=0;
while(i<a.size()&&j<b.size()){
    if(a[i]<b[j]){
       
        ans[k++]=a[i];
        i++;
    }
    else{
        ans[k++]=b[j];
        j++;
    }
}
while(i<a.size()){
ans[k++]=a[i];
        i++;
}
while(j<b.size()){
    ans[k++]=b[j];
        j++;
}
return ans;
}
TreeNode<int>*inorderbst(int s,int e,vector<int>in){
    if(s>e)
        return NULL;
    
    int mid=(s+e)/2;
    TreeNode<int>*root=new TreeNode<int>(in[mid]);
    root->left=inorderbst(s,mid-1,in);
    root->right=inorderbst(mid+1,e,in);
    return root;
    
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
  vector<int>bst1,bst2;
  inorder(root1,bst1);
  inorder(root2,bst2);
  vector<int>mergearrays=mergearray(bst1,bst2);
  int s=0,e=mergearrays.size()-1;
  return inorderbst(s,e,mergearrays);
}


TC:O(M+N)
  SC:O(M+N)
