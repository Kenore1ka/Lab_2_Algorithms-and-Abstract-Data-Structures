#include <algorithm>
#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (!root) return new Node(value);
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

int height(Node* node) {
    if (!node) return 0;
    return 1 + max(height(node->left), height(node->right));
}

bool is_balanced(Node* node) {
    if (!node) return true;
    int left_height = height(node->left);
    int right_height = height(node->right);
    return abs(left_height - right_height) <= 1 && is_balanced(node->left) && is_balanced(node->right);
}

void delete_tree(Node* node) {
    if (!node) return;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

int main() {
    Node* root = nullptr;
    int value;
    cout << "Enter sequence of integers ending with 0:" << endl;
    while (cin >> value && value != 0) {
        root = insert(root, value);
    }

    if (is_balanced(root)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    delete_tree(root);
    return 0;
}
