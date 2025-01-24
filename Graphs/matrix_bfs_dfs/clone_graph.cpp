#include<bits/stdc++.h>
using namespace std;

class Node{  // defination of node
public:
    int value;
    vector<Node*> neighbours; // vector which contain the address of the neighbour nodes
    Node(){
        value = 0;
        neighbours = vector<Node*>();
    }
    Node(int value){
        this->value = value;
        neighbours = vector<Node*>(); // empty 
    }
    Node(int value, vector<Node*> neighbours){
        this->value = value;
        this->neighbours = neighbours;
    }
};

vector<Node*> nodeRegister; // keep the record of the node which have created 
Node* clone_graph(Node* node);  // Leetcode-133
void dfs(Node* actual, Node* clone);

int main(){

    

    return 0;
}

Node* clone_graph(Node* node){  // Leetcode-133
    if(node == NULL) return NULL;
    Node* clone = new Node(node->value);
    nodeRegister.resize(110, NULL);   // put the address NULL for all the nodes in the nodeRegister vector
    nodeRegister[clone->value] = clone;  // this array contains refference to the created nodes
    dfs(node, clone);
    return clone;
}

void dfs(Node* actual, Node* clone){
    for(Node* n : actual->neighbours){  // traverse the neighbours of the actual node
        if(nodeRegister[n->value] == NULL){     // creat the neighbour for the first time
            Node* newNode = new Node(n->value);
            nodeRegister[newNode->value] = newNode; // update the address
            clone->neighbours.push_back(newNode);  // successfully created an edge 
            dfs(n,newNode); 
        }
        else clone->neighbours.push_back(nodeRegister[n->value]); //node already created but add edge between them
    }
}
