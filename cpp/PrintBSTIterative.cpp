#include <iostream>
#include <stack>

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

void PrintBSTIterative(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::stack<Node*> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty())
    {
        Node *currNode =  nodeStack.top();
        nodeStack.pop();
        
        std::cout << currNode->val << std::endl;
        
        if(currNode->right)
        {
            nodeStack.push(currNode->right);
        }
        if(currNode->left)
        {
            nodeStack.push(currNode->left);
        }
    }
}


int main() {
    // Create your Binary Search Tree here
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    // Call the iterative printing function
    PrintBSTIterative(root);

    return 0;
}

