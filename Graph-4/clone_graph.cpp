#include<bits/stdc++.h>
using namespace std;
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
  Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        unordered_map<Node*,Node*> clone;
        queue<Node*> q;
        Node* ans=new Node(node->val);
        q.push(node);
        clone[node] = new Node(node->val);
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
           
           for (Node* neighbor : curr->neighbors) {
                if (!clone.count(neighbor)) {
                   
                    clone[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                clone[curr]->neighbors.push_back(clone[neighbor]);
           }
        }
        return clone[node];
    }
int main(){
       Node* node=new Node(1);
       node->neighbors={new Node(2),new Node(4)};
       node->neighbors[0]->neighbors={new Node(3)};
       node->neighbors[0]->neighbors[0]->neighbors={new Node()};
       node->neighbors[1]->neighbors[0]->neighbors={new Node()};
      
       Node * ans=cloneGraph(node);
       
        return 0;
}
    
