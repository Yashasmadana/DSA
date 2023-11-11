  Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here
       
       if(root==NULL) return NULL; // if the root is not found
       if(root->data==n1 || root->data==n2) return root; // if both are present in the same subtree
       // pre-order traversing NLR
       Node* left=lca(root->left,n1,n2);
       Node* right=lca(root->right,n1,n2);
       
       if(left==NULL) return right;
       else if(right==NULL) return left;
       
       return root; // if both are present in different subtrees
    }
