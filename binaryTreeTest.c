#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include "binaryTree.h"
int main()
{
   binaryTree *root=NULL; 
    insert(&root, 49,"Almanya"); 
    insert(&root, 54,"Arjantin"); 
    insert(&root, 61,"Avustralya"); 
    insert(&root, 43,"Avusturya"); 
    insert(&root, 52,"Meksika"); 
    insert(&root, 32,"Belçika"); 
    insert(&root, 20,"Misir"); 
    printf("\n"); 
   
    int resp=1;
    int new_code=0;
    char name_new[15];
    while(resp){
        printf("\n WELCOME TO  MENU \n\n> ");
        printf("For addition press 1\n> ");
        printf("For deleting press 2\n> ");
        printf("For  traversal(in, post, pre, level -order) press 3\n> ");
        printf("For mimimum  press 4\n> ");
        printf("For max  press 5\n> ");
        printf("For exit  press 0\n> ");
        scanf("%d",&resp);
        switch(resp){
            case 1:
            printf("Enter new County Code: ");
            scanf("%d",&new_code);
            printf("Enter new County name: ");
            scanf("%s",name_new);
            insert(&root,new_code,name_new);
            inorder(root);
            break;
            case 2: 
            printf("Enter code of County which you want to delete: ");
            scanf("%d",&new_code);
            deleteNodeByItem(root,new_code);
            printf("\nAfter Deleting\n");
            inorder(root);
            break;
            case 3:
             printf("\n  inorder \n");
            inorder(root);
             printf("\n Preorder \n");
            preorder(root);
             printf("\n Post order \n");
            postorder(root);
            printf("\n Level order \n");
            levelorder(root);
            break;
            case 4:
            printf("Min: %d %s\n",findMin(root)->key,findMin(root)->name);
            break;
            case 5: 
            printf("Max: %d %s\n",findMax(root)->key,findMax(root)->name); 
            break;
            case 0: break;
            default : continue;
        };

    }
return 0;
}
