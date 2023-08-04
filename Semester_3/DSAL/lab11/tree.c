#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * left;
    struct node * right;
} node ;

typedef struct node Node;

Node * createNode(int x) {
    Node * new = (Node *) malloc(sizeof(Node));
    new->val = x;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void inorder(Node *tree) {
    if (tree != NULL) {
        inorder(tree->left);
        printf("%d ",tree->val);
        inorder(tree->right);
    }
}

void postorder(Node *tree) {
    if (tree != NULL) {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ",tree->val);
    }
}

void preorder(Node *tree) {
    if (tree != NULL) {
        printf("%d ",tree->val);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void createBT(Node ** tree) {
    Node * iter = (Node *) malloc(sizeof(Node));
    Node * prev = (Node *) malloc(sizeof(Node));
    Node * root = (Node *) malloc(sizeof(Node));
    iter = NULL;
    int x;
    int inp = 0;
    printf("Enter value of root ");
    scanf("%d",&x);
    iter = createNode(x);
    root = iter;
    *tree = iter;
    prev = iter;

    printf("\n1. Enter left, \n2. Enter right, \n3. Move up, \n-1. Exit");

    do {
        printf("\n\nEnter choice: ");
        scanf("%d",&inp);
        if (inp == 1) {
            printf("Enter value to insert: ");
            scanf("%d",&x);
            Node * temp = createNode(x);
            prev = iter;
            iter->left = temp;
            iter = iter->left;
            printf("Moved left");
        }
        else if (inp == 2) {
            printf("Enter value to insert ");
            scanf("%d",&x);
            Node * temp = createNode(x);
            prev = iter;
            iter->right = temp;
            iter = iter->right;
            printf("Moved right");
        }
        else if (inp == 3) {
            if (iter == root) {
                printf("Already at root");
            }
            else {
                iter = prev;
                printf("Moved up");
            }
        }
        else 
            inp = -1;
    } while(inp != -1);
}