#include <stdio.h>

typedef struct TREE_NODE{
  int value;
  struct TREE_NODE *lChild;
  struct TREE_NODE *rChild;
} tNode;

/**
   Given a tree with +/- value on its nodes,
   find the maximum subtree.
 */

tNode *currMax = NULL;
int currMaxValue = (1<<31);
int gError = 0;

int findMaxSubTree(tNode *root){
  if (root == NULL)
    return 0;
  int l = 0;
  int r = 0;
  if (root->lChild != NULL)
    l = findMaxSubTree(root->lChild);
  if (root->rChild != NULL)
    r = findMaxSubTree(root->rChild);
  int c = root->value;

  if ( (c + r + l) > currMaxValue ){
    currMaxValue = c + r + l;
    currMax = root;
  }
  return c+r+l;
}

int main(int argc, char **argv){
  tNode *r = constructTestTree(3);
  printTree(r);
  printf("\n");
  findMaxSubTree(r);
  if (currMax != NULL && gError == 0){
    printf("Max Value is: %d\n", currMaxValue);
  }
  return 1;
}

/**
tNode* constructTestTree(int level){
  if (level == 0)
    return NULL;
  tNode * r = (tNode *) malloc (sizeof(tNode));
  r -> value = (rand() % 2 == 0 ? 1 : -1) * rand() % 10;
  r->lChild = constructTestTree(level - 1);
  r->rChild = constructTestTree(level - 1);
  return r;
}

void printTree(tNode *r){
  if (r == NULL)
    return;
  printTree(r->lChild);
  printf("%d ", r->value);
  printTree(r->rChild);
}
 */
