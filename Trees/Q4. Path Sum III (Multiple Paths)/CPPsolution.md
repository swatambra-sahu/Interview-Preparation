PROBLEM PATH SUM III (CPP SOLUTION)
<img width="1895" height="860" alt="image" src="https://github.com/user-attachments/assets/ee249701-f1c1-4e35-b13a-6e359c322c01" />


SOLUTION CODE


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefix;
        prefix[0] = 1;  // Base case
        
        return dfs(root, 0, targetSum, prefix);
    }
    
private:
    int dfs(TreeNode* node, long long currSum, int targetSum, 
            unordered_map<long long, int>& prefix) {
        
        if (!node) return 0;
        
        currSum += node->val;
        
        int count = 0;
        
        // Check if there exists a prefix sum we can remove
        if (prefix.find(currSum - targetSum) != prefix.end()) {
            count += prefix[currSum - targetSum];
        }
        
        // Add current sum to map
        prefix[currSum]++;
        
        // Recurse left & right
        count += dfs(node->left, currSum, targetSum, prefix);
        count += dfs(node->right, currSum, targetSum, prefix);
        
        // Backtrack
        prefix[currSum]--;
        
        return count;
    }
};
