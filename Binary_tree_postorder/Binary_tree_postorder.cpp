/* p
* Given a binary tree, return the postorder traversal of its nodes' values.
* 
* For example:
* Given binary tree {1,#,2,3},
*    1
*      \
* 	  2
* 	 /
* 	3
* return [3,2,1].
* 
* Note: Recursive solution is trivial, could you do it iteratively?
* Definition for binary tree
* struct TreeNode {
*     int val;
*      TreeNode *left;
*      TreeNode *right;
*      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
* class Solution {
* public:
* 	vector<int> postorderTraversal(TreeNode *root) {
* 			        
* 	}
* };
*/

#include<iostream>
#include<vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	vector<int> value;

	void RecursivePostOrder(TreeNode *root){
		if(root != NULL){
			postorderTraversal(root->left);
			postorderTraversal(root->right);
			value.push_back(root->val);
		}
	}

	vector<int> postorderTraversal(TreeNode *root){
		RecursivePostOrder(root);
		return value;
	}
};


int main(){
	Solution s;
	int i = 0;

	TreeNode *t = new TreeNode(1);
	t->right = new TreeNode(2);
	t->right->left = new TreeNode(3);
	
	vector<int> v = s.postorderTraversal(t);

	for(i = 0; i < v.size(); i++){
		cout<<v[i]<<endl;
	}
	return 0;
}
