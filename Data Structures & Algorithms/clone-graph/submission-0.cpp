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

/*
感觉这道题可以用BFS来做 对吗
I have a node -> create a copy of the node -> add the node to the bfs queue -> store the original node to new node mapping in a map
还有就是这个graph中可能是有环的 需要注意一下
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;

        Node* startRep = new Node(node->val);
        unordered_map<Node*, Node*> nodeMap;
        nodeMap[node] = startRep;

        deque<Node*> bfsQueue{node};
        while (bfsQueue.size()) {
            Node* cur = bfsQueue.front();
            bfsQueue.pop_front();

            Node* curRep = nodeMap[cur];
            for (Node* neighbor : cur->neighbors) {
                // the graph may contains cycle. How to handle that?
                // 1. For visited nodes they shouldn't in queue again
                // 2. I need to add that edge as well, even if it means adding a graph. 
                Node* neighborRep = nodeMap[neighbor];
                // This node has not been visited, create its replicate & add it to the queue
                if (!neighborRep) {
                    neighborRep = new Node(neighbor->val);
                    nodeMap[neighbor] = neighborRep;
                    bfsQueue.push_back(neighbor);
                }

                // Add the edge
                curRep->neighbors.push_back(neighborRep);
            }
        }

        return startRep;
    }
};
