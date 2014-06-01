/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node) {
            return clone(node);
        }
        return NULL;
    }
private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> visited;
    UndirectedGraphNode *clone(UndirectedGraphNode *node) {
        UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
        visited[node] = copy;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            if (visited.find(node->neighbors[i]) == visited.end()) {
                copy->neighbors.push_back(clone(node->neighbors[i]));
            } else {
                copy->neighbors.push_back(visited[node->neighbors[i]]);
            }
        }
        return copy;
    }
};

