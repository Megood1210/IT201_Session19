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

// Hàm duyệt theo thứ tự Postorder
void postorder(Node* root) {
    if (root == NULL){
        return;
    }

    postorder(root->left);    // Duyệt cây con trái
    postorder(root->right);   // Duyệt cây con phải
    printf("%d \n", root->data);   // Duyệt gốc
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    printf("Duyet then thu tu Postorder: \n");
    postorder(root);  // Gọi hàm duyệt cây

    // Giải phóng bộ nhớ
    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
