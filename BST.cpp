#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        cout << "Duplicate value not allowed.\n";
    }
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int value) {
    if (root == nullptr) {
        cout << "Value not found.\n";
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node to delete found
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        } else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void displayMenu() {
    cout << "\n=== Binary Search Tree Operations ===\n";
    cout << "1. Create BST\n";
    cout << "2. Insert\n";
    cout << "3. Delete\n";
    cout << "4. Inorder Traversal\n";
    cout << "5. Preorder Traversal\n";
    cout << "6. Postorder Traversal\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Node* root = nullptr;
    int choice, value, n;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "How many elements to insert initially? ";
                cin >> n;
                cout << "Enter elements: ";
                for (int i = 0; i < n; i++) {
                    cin >> value;
                    root = insert(root, value);
                }
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;
            case 4:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 6:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
