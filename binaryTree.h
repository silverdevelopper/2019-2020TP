#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#define size 15

typedef struct btree {
    char name[size];
    int key;
    struct  btree *left,*right;
}binaryTree;
binaryTree* newNode(int item,char name[size]);
void inorder(binaryTree *root);
void insert(binaryTree **head,int key,char name[size]);
void preorder(binaryTree *root);
void postorder(binaryTree *root);
binaryTree *findMin(binaryTree *root);
binaryTree *findMax(binaryTree *root);
binaryTree *deleteNodeByItem(binaryTree *root,int item);
int height(binaryTree *root);
void levelorder(binaryTree *root);
void currentLevel(binaryTree *root, int level);
#endif