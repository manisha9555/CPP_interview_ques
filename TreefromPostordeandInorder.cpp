void createmapping(int in[],map<int,int> &nodetoindex,int n){
        for(int i=0;i<n;i++){
            nodetoindex[in[i]]=i;
       }
    }
    Node*solve(int in[], int post[],int &index,int inorderstart,int inorderend,int n,map<int,int> &nodetoindex){
          if(index<0||inorderstart>inorderend){
              return NULL;
          }
          int element=post[index--];
          Node*root=new Node(element);
          int position=nodetoindex[element];
          //recursion call
          root->right=solve(in,post,index,position+1,inorderend,n,nodetoindex);
          root->left=solve(in,post,index,inorderstart,position-1,n,nodetoindex);
          
          return root;
      }
Node *buildTree(int in[], int post[], int n) {
    int postindex = n - 1;  // Initialize the index variable
    map<int, int> nodetoindex;
    createmapping(in, nodetoindex, n);
    Node *ans = solve(in, post, postindex, 0, n - 1, n, nodetoindex);
    return ans;
}
