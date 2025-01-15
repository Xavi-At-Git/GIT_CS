#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data ;
  struct Node* left;
  struct Node* right;
};

struct Node* createNode(int data){
  struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));

  newnode -> data = data;
  newnode -> left = NULL;
  newnode -> right = NULL;
  return newnode;
}

struct Node* insert(struct Node* root,int data){
  if(root==NULL){
    return createNode(data);
  }
  if(data<root->data){
    root->left = insert(root->left,data);
  }else{
    root->right = insert(root->right,data);
  }
  return root;
}

struct Node* search(struct Node* root,int data){
  if (root == NULL || root->data == data){
    return root;
  }
  if(data<root->data){
    return search(root->left,data);
  }else{
    return search(root->right,data);
  }
}

void preorder(struct Node* root){
  if(root != NULL){
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void inorder(struct Node* root){
  if(root!=NULL){
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
  }
}

void postorder(struct Node* root){
  if(root != NULL ){
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
  }
}

int main (){
  struct Node* root = NULL ;
  int option , data;

  do { 
  printf("\nMenu\n1. Insert\n2. Search\n3. Pre-order Traversal\n4. In-order Traversal\n5. Post-order Traversal\n6. Exit\nEnter your choice: ");
  scanf("%d",&option);
  switch(option){
    case 1:
      printf("Enter value to add in Warehouse: ");
      scanf("%d",&data);
      root = insert(root,data); 
      break;  
    case 2:
      printf("Enter value to search in Warehouse: ");
      scanf("%d",&data);
      if(search(root,data)){;
      printf("Found %d in Warehouse",data);
      }else{
        printf("Not Found %d in Warehouse",data);
      }
      break;
    case 3:
      printf("Preorder Traversal is : [ ");
      preorder(root);
      printf("]");
      break;
    case 4:
      printf("Inorder Traversal is : [ ");
      inorder(root);
      printf("]");
      break;
    case 5:
      printf("Postorder Traversal is : [ ");
      postorder(root);
      printf("]");
      break;
    case 6:
      printf("Exiting Program ...");
      break;
    default:
      printf("Invalid Option ... Please try again. ");
      break;
  }
 }while(option != 6);
}

