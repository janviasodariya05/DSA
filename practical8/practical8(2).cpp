#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Insert a value into BST
Node* insert(Node* root, int value)
{
    // If tree is empty
    if (root == NULL)
        return new Node(value);

    // Smaller value goes to left
    if (value < root->data)
        root->left = insert(root->left, value);

    // Larger value goes to right
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Inorder traversal
void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node* root = NULL;

    int n;

    cout << "Enter number of book codes: ";
    cin >> n;

    cout << "Enter book codes: ";

    for (int i = 0; i < n; i++)
    {
        int code;
        cin >> code;

        root = insert(root, code);
    }

    cout << "Inorder sequence: ";
    inorder(root);

    return 0;
}