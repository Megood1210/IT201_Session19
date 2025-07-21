#include <stdio.h>
#include <stdlib.h>

// Định nghĩa Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Tạo Node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Loi cap phat \n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Duyệt theo thứ tự Inorder
void inorder(Node* root) {
    if (root == NULL){
        return;
    }

    inorder(root->left);    // Duyêt cây trái
    printf("%d \n", root->data); // Duyệt cây gốc
    inorder(root->right);   // Duyệt cây phải
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    printf("Duyet then thu tu (Inorder): \n");
    inorder(root);  // Gọi hàm duyệt cây

    // Giải phóng bộ nhớ
    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
