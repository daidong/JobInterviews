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

int findMaxSubTree(tNode *root, tNode **p, int flag){
  if (flag == 1){
    int contain = 0;
    return findMaxPosSubTree(root, p, &contain);
  } else {
    return findMaxAllSubTree(root, p);
  }
}
int findMaxPosSubTree(tNode *root, tNode **p, int *contain){
  if (root == NULL)
    return 0;

  tNode *tp = NULL, *tq = NULL;
  int lf = 0, rf = 0;
  int lv = (root->lChild == NULL)?0:findMaxPosSubTree(root->lChild, &tp, &lf);
  int rv = (root->rChild == NULL)?0:findMaxPosSubTree(root->rChild, &tq, &rf);
  (*contain) = (lf || rf || (root->value < 0));
  int localMax = (lv > rv)?lv:rv;
  tNode *maxP = (lv > rv)?tp:tq;

  if (lf){
    localMax = rv;
    maxP = tq;
  }
  if (rf){
    localMax = lv;
    maxP = tp;
  }

  int sum = lv + rv + root->value;
  if (!(*contain) && sum > localMax){
    (*p) = root;
    return sum;
  } else {
    (*p) = maxP;
    return localMax;
  }
}
int findMaxAllSubTree(tNode *root, tNode **p){
  if (root == NULL)
    return 0;

  tNode *tp = NULL, *tq = NULL;
  int lv = (root->lChild == NULL)?0:findMaxAllSubTree(root->lChild, &tp);
  int rv = (root->rChild == NULL)?0:findMaxAllSubTree(root->rChild, &tq);

  int localMax = (lv > rv)?lv:rv;
  tNode *maxP = (lv > rv)?tp:tq;

  int sum = lv + rv + root->value;

  if (sum  > localMax)
    (*p) = root;
  else
    (*p) = maxP;

  return sum;
}
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

int main(int argc, char **argv){
  tNode *r = constructTestTree(3);
  tNode *max = NULL;
  findMaxSubTree(r, &max, 0);
  findMaxSubTree(r, &max, 1);
  return 1;
}

