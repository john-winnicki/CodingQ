/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return node;
        unordered_map<int, Node*> hash;
        unordered_set<int> seen;
        
        queue<Node*> myq;
        myq.push(node);
        seen.insert(node->val);
        
        Node* node_clone = new Node(node->val);
        hash[node->val] = node_clone;
        
        while(!myq.empty()){
            Node* curr = myq.front();
            myq.pop();
            // cout<<curr->val<<endl;
            Node* curr_clone = hash[curr->val];
            for(Node* fredo : curr->neighbors){
                if(hash.find(fredo->val)==hash.end()){
                    Node* temp = new Node(fredo->val);
                    hash[fredo->val] = temp;
                }
                (curr_clone->neighbors).push_back(hash[fredo->val]);
                if(seen.find(fredo->val)==seen.end()){
                    seen.insert(fredo->val);
                    myq.push(fredo);
                }
            }
        }
        return hash[node->val];
    }
};