#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct Node {
    DataType data;
    struct Node* Lchild;
    struct Node* Rchild;
} BTNode, * BTree;

#define MAX_STACK_SIZE 100

// 先序遍历的递归算法
void preorderRecursive(BTree root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderRecursive(root->Lchild);
        preorderRecursive(root->Rchild);
    }
}

// 中序遍历的递归算法
void inorderRecursive(BTree root) {
    if (root != NULL) {
        inorderRecursive(root->Lchild);
        printf("%d ", root->data);
        inorderRecursive(root->Rchild);
    }
}

// 后序遍历的递归算法
void postorderRecursive(BTree root) {
    if (root != NULL) {
        postorderRecursive(root->Lchild);
        postorderRecursive(root->Rchild);
        printf("%d ", root->data);
    }
}

// 先序遍历的非递归算法
void preorder(BTree root) {
    if (root == NULL) {
        printf("Empty tree\n");
        return;
    }

    BTree stack[MAX_STACK_SIZE];
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        BTree node = stack[top--];
        printf("%d ", node->data);

        if (node->Rchild != NULL) {
            stack[++top] = node->Rchild;
        }

        if (node->Lchild != NULL) {
            stack[++top] = node->Lchild;
        }
    }
}

// 中序遍历的非递归算法
void inorder(BTree root) {
    if (root == NULL) {
        printf("Empty tree\n");
        return;
    }

    BTree stack[MAX_STACK_SIZE];
    int top = -1;
    BTree current = root;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->Lchild;
        }

        current = stack[top--];
        printf("%d ", current->data);

        current = current->Rchild;
    }
}

// 后序遍历的非递归算法
void postorder(BTree root) {
    if (root == NULL) {
        printf("Empty tree\n");
        return;
    }

    BTree stack1[MAX_STACK_SIZE];
    BTree stack2[MAX_STACK_SIZE];
    int top1 = -1;
    int top2 = -1;

    stack1[++top1] = root;

    while (top1 >= 0) {
        BTree node = stack1[top1--];
        stack2[++top2] = node;

        if (node->Lchild != NULL) {
            stack1[++top1] = node->Lchild;
        }

        if (node->Rchild != NULL) {
            stack1[++top1] = node->Rchild;
        }
    }

    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->data);
    }
}

// 创建一个简单的二叉树
BTree createSampleTree() {
    BTree root = (BTree)malloc(sizeof(BTNode));
    root->data = 1;

    root->Lchild = (BTree)malloc(sizeof(BTNode));
    root->Lchild->data = 2;
    root->Lchild->Lchild = NULL;
    root->Lchild->Rchild = NULL;

    root->Rchild = (BTree)malloc(sizeof(BTNode));
    root->Rchild->data = 3;
    root->Rchild->Lchild = NULL;
    root->Rchild->Rchild = NULL;

    return root;
}

// 测试函数
int main(void) {
    BTree root = createSampleTree();

    printf("先序遍历递归算法: ");
    preorderRecursive(root);
    printf("\n");

    printf("中序遍历递归算法: ");
    inorderRecursive(root);
    printf("\n");

    printf("后序遍历递归算法: ");
    postorderRecursive(root);
    printf("\n");

    printf("先序遍历非递归算法: ");
    preorder(root);
    printf("\n");

    printf("中序遍历非递归算法: ");
    inorder(root);
    printf("\n");

    printf("后序遍历非递归算法: ");
    postorder(root);
    printf("\n");

    return 0;
}
