#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *lc;
    struct node *rc;
};
void build_tree(struct node *ptr, int d);
void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);
int main() {
    int rootdata;
    struct node *root = (struct node*)malloc(sizeof(struct node));
    printf("Enter the root element: ");
    scanf("%d", &rootdata);
    build_tree(root, rootdata);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    return 0;
}
void build_tree(struct node *ptr, int d) {
    int op;
    ptr->data = d;
    ptr->lc = NULL;
    ptr->rc = NULL;
    printf("If %d has a left subtree, Enter 1 else 0: ", ptr->data);
    scanf("%d", &op);
    if (op == 1) {
        int lsc;
        ptr->lc = (struct node*)malloc(sizeof(struct node));
        printf("Enter the value of Left child node: ");
        scanf("%d", &lsc);
        build_tree(ptr->lc, lsc);
    }
    printf("If %d has a right subtree, Enter 1 else 0: ", ptr->data);
    scanf("%d", &op);
    if (op == 1) {
        int rsc;
        ptr->rc = (struct node*)malloc(sizeof(struct node));
        printf("Enter the value of Right child node: ");
        scanf("%d", &rsc);
        build_tree(ptr->rc, rsc);
    }
}
void preorder(struct node *root) {  
    if (root != NULL) {
        printf("%d\t", root->data);
        preorder(root->lc);
        preorder(root->rc);
    }
}
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->lc);
        printf("%d\t", root->data);
        inorder(root->rc);
    }
}
void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->lc);
        postorder(root->rc);
        printf("%d\t", root->data);
    }
}