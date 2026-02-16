class Solution {
public:
    Node* dfs(Node* cur, unordered_map<Node*, Node*>& mp) {
        if (mp.find(cur) != mp.end())
            return mp[cur];

        Node* clone = new Node(cur->val);
        mp[cur] = clone;

        for (auto it : cur->neighbors) {
            clone->neighbors.push_back(dfs(it, mp));
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;

        unordered_map<Node*, Node*> mp;
        return dfs(node, mp);
    }
};
