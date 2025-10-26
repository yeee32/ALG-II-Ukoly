#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height; // výška uzlu

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(Node* node) {
    if (node == nullptr) return 0;
    return node->height;
}

void upadteHeight(Node* node){
    if(node == nullptr){
        return;
    }
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// TODO 1: napište funkci, která spočítá balance faktor uzlu
int getBalance(Node* node) {
    if(node == nullptr){
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// TODO 2: implementujte pravotočivou rotaci
Node* rightRotate(Node* y) {
    Node* center = y->left;
    Node* r = center->right;

    center->right = y;
    y->left = r;

    upadteHeight(y);
    upadteHeight(center);

    return center;
}

// TODO 3: implementujte levotočivou rotaci
Node* leftRotate(Node* x) {
    Node* center = x->right;
    Node* l = center->left;

    center->left = x;
    x->right = l;

    upadteHeight(x);
    upadteHeight(center);

    return center;
}

// Vložení do AVL stromu
Node* insert(Node* node, int key) {
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // duplicity ignorujeme

    // TODO 4: přepočítejte výšku uzlu
    // node->height = ...
    upadteHeight(node);

    // TODO 5: získejte balance faktor a proveďte potřebné rotace
    int balance = getBalance(node);

    // Levý-levý případ
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Pravý-pravý případ
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Levý-pravý případ
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Pravý-levý případ
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// TODO 6: napište funkci pro spočítání počtu uzlů v podstromu
int countNodes(Node* root) {
    if(root == nullptr){
        return 0;   
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Výpis inorder
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder průchod AVL stromem: ";
    inorder(root);
    cout << endl;

    cout << "Pocet uzlu ve stromu: " << countNodes(root) << endl;
    cout << "Vyska stromu (root): " << getHeight(root) << endl;
}