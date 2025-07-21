#include <stdio.h>
#include <stdlib.h>

// Cấu trúc node cây nhị phân
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
#define MAX 100

typedef struct {
    Node* data[MAX];
    int front, rear;
} Queue;

// Khởi tạo queue
void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

// Kiểm tra queue rỗng
int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// Thêm node vào queue
void enqueue(Queue* q, Node* node) {
    if (q->rear < MAX) {
        q->data[q->rear++] = node;
    }
}

// Lấy node ra khỏi queue
Node* dequeue(Queue* q) {
    if (!isEmpty(q)) {
        return q->data[q->front++];
    }
    return NULL;
}

// Hàm thêm phần tử vào cây
void insertNode(Node* root, int value) {
    // Kiểm tra cây rỗng
    if (root == NULL){
        return;
    }
    // Khởi tạo hàng đợi
    Queue q;
    initQueue(&q);
    // Duyệt từ root
    enqueue(&q, root);
    // Duyệt từng phần tử trong cây
    while (!isEmpty(&q)) {
        // Lấy ra node đầu
        Node* current = dequeue(&q);
        // Kiểm tra node chưa có phần tử trái
        if (current->left == NULL) {
            current->left = createNode(value); // Tạo phần tử trái
            return;
        } else {
            // Thêm phần tử trái vào hàng
            enqueue(&q, current->left);
        }
        // Kiểm tra node chưa có phần tử phải
        if (current->right == NULL) {
            current->right = createNode(value); // Tạo phần tử phải
            return;
        } else {
            // Thêm phần tử phải vào hàng
            enqueue(&q, current->right);
        }
    }
}

// Duyệt tiền thứ tự để in cây
void preorderTraversal(Node* root) {
    if (root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    // Tạo cây ban đầu
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    // Nhập giá trị cần thêm từ người dùng
    int value;
    printf("Nhap so can them vao cay: ");
    scanf("%d", &value);

    // Thêm giá trị vào cây
    insertNode(root, value);

    // In kết quả
    printf("Cay sau khi them:\n");
    preorderTraversal(root);
    printf("\n");

    return 0;
}

