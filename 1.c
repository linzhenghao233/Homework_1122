#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct Node {
    DataType data;
    struct Node* Lchild;
    struct Node* Rchild;
} BTNode, * BTree;

#define MAX_STACK_SIZE 100

// ��������ĵݹ��㷨
void preorderRecursive(BTree root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderRecursive(root->Lchild);
        preorderRecursive(root->Rchild);
    }
}

// ��������ĵݹ��㷨
void inorderRecursive(BTree root) {
    if (root != NULL) {
        inorderRecursive(root->Lchild);
        printf("%d ", root->data);
        inorderRecursive(root->Rchild);
    }
}

// ��������ĵݹ��㷨
void postorderRecursive(BTree root) {
    if (root != NULL) {
        postorderRecursive(root->Lchild);
        postorderRecursive(root->Rchild);
        printf("%d ", root->data);
    }
}

// ��������ķǵݹ��㷨
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

// ��������ķǵݹ��㷨
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

// ��������ķǵݹ��㷨
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

// ����һ���򵥵Ķ�����
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

// ���Ժ���
int main(void) {
    BTree root = createSampleTree();

    printf("��������ݹ��㷨: ");
    preorderRecursive(root);
    printf("\n");

    printf("��������ݹ��㷨: ");
    inorderRecursive(root);
    printf("\n");

    printf("��������ݹ��㷨: ");
    postorderRecursive(root);
    printf("\n");

    printf("��������ǵݹ��㷨: ");
    preorder(root);
    printf("\n");

    printf("��������ǵݹ��㷨: ");
    inorder(root);
    printf("\n");

    printf("��������ǵݹ��㷨: ");
    postorder(root);
    printf("\n");

    return 0;
}
