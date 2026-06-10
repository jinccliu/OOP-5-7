#include <iostream>
#include <string>    
#include <cctype>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;
    
    TreeNode* insertNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        
        if (value < node->value) {
            node->left = insertNode(node->left, value);
        } else if (value > node->value) {
            node->right = insertNode(node->right, value);
        }
        
        return node;
    }
    
    TreeNode* searchNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }
        
        if (value == node->value) {
            return node;
        } else if (value < node->value) {
            return searchNode(node->left, value);
        } else {
            return searchNode(node->right, value);
        }
    }
    
public:
    BinarySearchTree() : root(nullptr) {}
    
    void insert(int value) {
        root = insertNode(root, value);
    }
    
    TreeNode* search(int value) {
        return searchNode(root, value);
    }
};

int main() {
    BinarySearchTree bst;
    
    // 第一行：輸入一組正整數
    string line;
    getline(cin, line);
    
    // 解析輸入的數字
    int num;
    size_t pos = 0;
    while (pos < line.length()) {
        // 跳過空格
        while (pos < line.length() && isspace(line[pos])) {
            pos++;
        }
        
        if (pos < line.length()) {
            int start = pos;
            while (pos < line.length() && !isspace(line[pos])) {
                pos++;
            }
            num = stoi(line.substr(start, pos - start));
            bst.insert(num);
        }
    }
    
    // 第二行：輸入要搜索的數值
    int searchValue;
    cin >> searchValue;
    
    // 搜索並輸出結果
    TreeNode* foundNode = bst.search(searchValue);
    
    if (foundNode != nullptr) {
        // 輸出左右子節點的值
        int leftVal = (foundNode->left != nullptr) ? foundNode->left->value : -1;
        int rightVal = (foundNode->right != nullptr) ? foundNode->right->value : -1;
        
        cout << leftVal << " " << rightVal << endl;
    } else {
        cout << "The value is not in this binary search tree." << endl;
    }
    
    return 0;
}
