class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;
        for (auto &word : words) {
            for (char c : word) {
                indegree[c] = 0;
            }
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string &w1 = words[i];
            string &w2 = words[i + 1];
            if (w1.size() > w2.size() && w1.substr(0, w2.size()) == w2) {
                return "";
            }
            
            for (int j = 0; j < min(w1.size(), w2.size()); j++) {
                if (w1[j] != w2[j]) {
                    if (!graph[w1[j]].count(w2[j])) {
                        graph[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }
        queue<char> q;
        for (auto &p : indegree) {
            if (p.second == 0) {
                q.push(p.first);
            }
        }
        string result;
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            result.push_back(c);
            for (char next : graph[c]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        if (result.size() != indegree.size()) {
            return "";
        }
        return result;
    }
};
