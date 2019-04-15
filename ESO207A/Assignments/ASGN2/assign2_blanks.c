#include <stdio.h>
#include <stdlib.h>
#define N 200005
int TOBALANCE=1; // TOBALANCE is 1 when the condition is Perfectly balanced, 0 otherwise. By changing this constant you can change balance condition.
int NEARLY_BALANCED = 0;
int PERFECTLY_BALANCED = 1;
double BALANCE_RATIO = 0.75; //You may change this ratio.

/* structure of a node of the binary tree.
val: value at the node
size: size of subtree rooted at node
left,right:pointers to right and left sub tree 
*/
struct Node{
  int val;
  int size;
  struct Node *left,*right;  
};

/*
This function takes a value and initialises and returns a new node whose value is set to the given parameter.
*/
Node* init(int val){
  Node *curr = (Node *)malloc(sizeof(Node));
  curr->val=val;
  curr->size=1;
  curr->left=curr->right=NULL;
  return curr;
}


/*
SortedArrayFromBST: This function takes as input a node, pointer to an array, and an integer that denotes the next free position in the array.
This function fills in the array all the values in the tree whose root is the given node i.e. output array finally contains the elements in 
increasing order.
This function must return the number of array positions it has filled. i.e. if initial value of parameter fst = p, then after returning from the function the final value must increase by the size of subtree i.e p+curr->size.
*/
int SortedArrayFromBST(Node *curr,int output[],int fst){

}

/*
This function creates a BST from an array. It takes as parameters input array and the length of array. It returns the root of the BST
that is formed by the array
*/
Node *BSTFromSortedArray(int input[], int len){

}

/*
This function recursively deletes all the nodes in the tree whose root in pointed by curr
*/

void deleteNode(struct Node *curr){
  if(curr==NULL) return;
  deleteNode(curr->left); 
  deleteNode(curr->right);
  free(curr);
}

/*
This function returns 1 if the current node satisfies the nearly balanced condition and 0 otherwise
*/
int checkNearBalance(Node *curr){
}

/*
This function returns 1 if the current node satisfies the perfectly balanced condition and 0 otherwise
*/
int checkPerfectBalance(Node *curr){
}

/*
This function takes as input a pointer to a node and inserts a node in the subtree of the node depending on the value.
out[] array is used as a helper array which will be used when the BST does not satisfy the balanced condition.

-when the insert returns then the tree must satisfy the balanced condition
*/
void insert(Node **curr,int val,int out[]){
  Node *new = (Node *)malloc(sizeof(Node));
  new = init(val) ;
  Node *x = (Node *)malloc(sizeof(Node));
  Node *par_x = (Node *)malloc(sizeof(Node));
  par_x = curr ;
  x = curr ;
  while(x != NULL){
    par_x = x ;
    if(x.val > val){
      x.size = x.size +1 ;
      x = x->left ;  
    }else{
      x.size = x.size +1 ;
      x = x->right ;
   }
  }
  if(par_x.val < val){
    par_x->right = new ;
  }
  else{
    par_x->left = new ;
  }
}

/*
This function takes as input a node pointer and a val and searches for a node which has value val in the subtree of node.
It returns 1 if the value is found, 0 otherwise.
*/
int search(Node *curr,int val){

}

int main(){
  Node *root = NULL;
  int out[N];
  int queries; scanf("%d",&queries);
  while(queries--){
    int c,val; scanf("%d%d",&c,&val);
    if(c==1){
      //insert
      if(root){
        insert(&root,val,out);
      }else{
        root = init(val);
      }
    }else{
      //search query
      if(search(root,val)) printf("Yes\n"); else printf("No\n");
    }
  }
  return 0;
}