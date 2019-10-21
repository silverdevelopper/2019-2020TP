#include "binaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

binaryTree* newNode(int item,char name[size]){
    binaryTree *tmp=malloc(sizeof(binaryTree));
    tmp->key=item;
    tmp->left=NULL;
    tmp->right=NULL;
    strcpy(tmp->name,name);
    return tmp;
}
void insert(binaryTree **head,int key,char name[size]){
    if(*head==NULL)
    {
        *head=newNode(key,name);
        return;
    }
    if((*head)->key<key){
        insert(&(*head)->right,key,name);
    }
    else
    {
        insert(&(*head)->left,key,name);   
    }
}
//left root right
void inorder(binaryTree *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf(" %d: %s ->", root->key,root->name); 
        inorder(root->right); 
    } 
} 
//Root Left Right
void preorder(binaryTree *root) 
{ 
    if (root != NULL) 
    { 
        printf("%d : %s\n", root->key,root->name); 
        preorder(root->left); 
        preorder(root->right); 
    } 
}
//Ledt right root
void postorder(binaryTree *root) 
{ 
    if (root != NULL) 
    { 
        postorder(root->left); 
        postorder(root->right); 
        printf("%d : %s \n", root->key,root->name); 
    } 
}
binaryTree *findMin(binaryTree *root){
    binaryTree * min=root;
    if(root->left!=NULL)
    {
       min= findMin(root->left);
    }
    return min;
}
binaryTree *findMax(binaryTree *root){
    binaryTree * max=root;
    if(root->right!=NULL)
    {
       max= findMax(root->right);
    }
    return max;
}
binaryTree *deleteNodeByItem(binaryTree *root,int item){

   if(root==NULL)
   {
       printf("List dont conain: %d",item);
       return root;
       }
   if(item<root->key)
   {
       root->left=deleteNodeByItem(root->left,item);
   }else if (item>root->key)
   {
        root->right=deleteNodeByItem(root->right,item);
   }else
   {
       if(root->left==NULL)
       {
            binaryTree *tmp=root->right;
            free(root);
            return tmp;
       }else if (root->right==NULL)
       {
            binaryTree *tmp=root->left;
            free(root);
            return tmp;
       }

       binaryTree *tmp=findMin(root->right);
       root->key = tmp->key;
       root->right = deleteNodeByItem(root->right, tmp->key); 

   }
   
    return root;
}
int height(binaryTree *root){
    if(root==NULL)
    return 0;
    else
    {
       int lhg=height(root->left);
       int rhg= height(root->right);
       if(lhg>rhg)
       return (lhg+1);
       else
       {
           return (rhg+1);
       }
       
    }
    
}
void levelorder(binaryTree *root){
    int h = height(root); 
    int i; 
    for (i=1; i<=h; i++) 
        currentLevel(root, i); 
}
void currentLevel(binaryTree *root, int level){
    if(root==NULL)
    return;
    if(level==1)
    {
        printf("%d : %s\n", root->key,root->name); 
    }else if (level>1)
    {
        currentLevel(root->left,level-1);
        currentLevel(root->right,level-1);
    }
    
}