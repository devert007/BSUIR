#include <iostream>
#include <string>

struct Node {
public:
    std::string data;
    int key;
    Node* left;
    Node* right;

    Node(std::string value, int k) 
    {
        data = value;
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

//функция вставки элемента в дерево
void insert(Node*& root, std::string value, int key) {
    if (root == nullptr) {
        root = new Node(value, key);
        return;
    }

    if (key < root->key) {
        insert(root->left, value, key);
    }
    else {
        insert(root->right, value, key);
    }
}

//"конструктор"
Node* constructBST(std::string arr[], int keys[], int size) {
    Node* root = nullptr;

    for (int i = 0; i < size; i++) {
        insert(root, arr[i], keys[i]);
    }

    return root;
}

//заход от меньшего к большему ключу слева ,справа
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}
//заход от большего ключа к меньшему слева,справа
void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
//заход от меньшего к большему слева(без корня) и в конце корень
void postorderTraversal(Node* root) {
    if (root == nullptr)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->data << " ";
}
//вывод дерева
void printTree(Node* root, int level = 0) {
    if (root == nullptr) {
        return;
    }

    printTree(root->right, level + 1);

    for (int i = 0; i < level; i++) {
        std::cout << "    ";
    }

    std::cout << root->data << " (" << root->key << ")" << std::endl;

    printTree(root->left, level + 1);
}

//поиск конкретного элемента по ключу
Node* search(Node* root, int key) {
    if (root == nullptr || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    }
    else {
        return search(root->right, key);
    }
}

//поиск минимального узла
Node* minValueNode(Node* node) {
    Node* current = node;

    while (current && current->left != nullptr) {
        current = current->left;
    }

    return current;
}
//удалить узел
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}
//найти количество узлов с буквой А
int countNodesStartingWithLetter(Node* root, char letter) {
    if (root == nullptr) {
        return 0;
    }

    int count = 0;

    if (root->data[0] == letter) {
        count++;
    }

    count+= countNodesStartingWithLetter(root->left, letter);
    count+= countNodesStartingWithLetter(root->right, letter);

    return count;
}

int main() {
    std::string arr[] = { "John", "Alice", "Aob", "David", "Eve" };
    int keys[] = { 123, 100, 789, 87, 654 };
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* root = constructBST(arr, keys, size);

    std::cout << "Inorder traversal of the constructed BST: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Preorder traversal of the constructed BST: ";
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Postorder traversal of the constructed BST: ";
    postorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Tree: " << std::endl;
    printTree(root);

    int newKey = 111;
    std::string newData = "New Person";
    insert(root, newData, newKey);

    std::cout << "Inorder traversal after inserting new record: ";
    inorderTraversal(root);
    std::cout << std::endl;

    int searchKey = 789;
    Node* searchResult = search(root, searchKey);

    if (searchResult != nullptr) {
        std::cout << "Information for key " << searchKey << ": " << searchResult->data << std::endl;
    }
    else {
        std::cout << "No information found for key " << searchKey << std::endl;
    }

    int deleteKey = 123;
    root = deleteNode(root, deleteKey);

    std::cout << "Inorder traversal after deleting record with key " << deleteKey << ": ";
    inorderTraversal(root);
    std::cout << std::endl;

    char letter = 'A';
    int count = countNodesStartingWithLetter(root, letter);

    std::cout << "Number of records starting with letter " << letter << ": " << count << std::endl;

    return 0;
}