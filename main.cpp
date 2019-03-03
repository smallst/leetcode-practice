/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    unordered_map<Node*, Node*> copyed;
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        
        
        if(copyed.find(node) == copyed.end())
        {
            copyed[node] = new Node(node->val, {});
            for(auto i = node->neighbors.begin(); i != node->neighbors.end(); i++)
            {
                copyed[node]->neighbors.push_back(cloneGraph(*i));
            }
        }
        return copyed[node];
    }
};
