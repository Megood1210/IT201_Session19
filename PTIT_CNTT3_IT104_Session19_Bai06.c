#include <stdio.h>
#include <stdlib.h>

// Định nghĩa Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Loi cap phat\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Tìm kiếm sử dụng BFS
int searchDFS(Node* root, int value) {
    // Kiểm tra key rỗng
    if (root == NULL){
        return 0;
    }
    // Kiểm tra giá trị nhập trùng với giá trị trong cây
    if (root->data == value){
        return 1;
    }
    return searchDFS(root->left, value) || searchDFS(root->right, value); // Nếu tìm bên phải không thấy thì
    //tìm bên trái. Nếu có ở 1 trong 2 th true. Nếu không ngược lại
}

int main() {
    // Tạo node
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    // Nhập số càn tìm
    int target;
    printf("Nhap so can tim: ");
    scanf("%d", &target);
    // In kết quả
    if (searchDFS(root, target))
        printf("true");
    else
        printf("false");

    // Giải phóng bộ nhớ
    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}