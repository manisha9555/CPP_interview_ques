class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int>result;
    	if(root==NULL){
    	    return result;
    	}
    	
    	queue<Node*>q;
    	q.push(root);
    	
    	bool lefttoright=true;
    	
    	while(!q.empty()){
    	    
    	    int size=q.size();
    	    //temprary array store ans
    	    vector<int>ans(size);
    	    
    	    //level process
    	    for(int i=0;i<size;i++){
    	        Node*frontnode=q.front();
    	        q.pop();
    	        int index=lefttoright?i:size-i-1;
    	        ans[index]=frontnode->data;
    	        if(frontnode->left){
    	            q.push(frontnode->left);
    	        }
                if(frontnode->right){
    	            q.push(frontnode->right);
    	        }
    	    }
    	    //direction change krna
    	    lefttoright=!lefttoright;
    	        for(auto i:ans){
    	        result.push_back(i);
    	      
    	        }
    	    }
    	    return result;
    }
};
