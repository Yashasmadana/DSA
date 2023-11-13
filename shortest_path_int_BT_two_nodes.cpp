#include <iostream>
using namespace std;

// Structure of Tree
class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val2)
	{
		val = val2;
		left = NULL;
		right = NULL;
	}
};

// Function to find LCA of two nodes
  TreeNode* lca(TreeNode* root ,int n1 ,int n2 )
    {
       //Your code here
       
       if(root==NULL) return NULL; // if the root is not found
       if(root->val==n1 || root->val==n2) return root; // if both are present in the same subtree
       // pre-order traversing NLR
       TreeNode* left=lca(root->left,n1,n2);
       TreeNode* right=lca(root->right,n1,n2);
       
       if(left==NULL) return right;
       else if(right==NULL) return left;
       
       return root; // if both are present in different subtrees
    }
bool getPath(TreeNode* root,
			int value, 
			string& path)
{

	// Base Cases
	if (!root)
		return false;
	if (root->val == value)
		return true;

	path += 'L';
	auto res = getPath(root->left, 
					value, path);
	if (res)
		return true;
	path.pop_back();
	path += 'R';
	res = getPath(root->right,
				value, path);
	if (res)
		return true;
	path.pop_back();
	return false;
}

// Function to get directions
string getDirections(TreeNode* root, 
					int startValue,
					int destValue)
{
	// Find the LCA first
	root = lca(root, startValue, destValue);

	string p1, p2;

	// Get the path
	getPath(root, startValue, p1);
	getPath(root, destValue, p2);
	for (auto& c : p1)
		c = 'U';

	// Return the concatenation
	return p1 + p2;
}

// Driver Code
int main()
{

	/*
			5
		/ \
		1	 2
		/	 / \
	3	 6 4

*/
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(1);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(4);

	int startValue = 3;
	int endValue = 4;

	// Function Call
	string ans = getDirections(
	root, startValue, endValue);

	// Print answer
	cout << ans;
}
