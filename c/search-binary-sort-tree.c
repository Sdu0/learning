#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define OVERFLOW 0

typedef int Status;
typedef int ElemType;

typedef struct TNode{
    ElemType data;
    struct TNode *lchild, *rchild;
}TNode, *BinTree;

Status init(BinTree *tree){
    (*tree) = (TNode *)malloc(sizeof(TNode));
    if(!(*tree)) exit(OVERFLOW);

    (*tree)->lchild = (*tree)->rchild = NULL;
    (*tree)->data = 0;

    return OK;
}

//create binary sort tree
Status insert(BinTree tree, ElemType e){
    if(e < tree->data){
        if(tree->lchild){
            insert(tree->lchild, e);   
        }else{
            TNode *node = (TNode *)malloc(sizeof(TNode));
            node->data = e;
            node->lchild = node->rchild = NULL;
            tree->lchild = node;
            return OK;
        }
    }else{
        if(tree->rchild){
            insert(tree->rchild, e);
        }else{
            TNode *node = (TNode *)malloc(sizeof(TNode));
            node->data = e;
            node->lchild = node->rchild = NULL;
            tree->rchild = node;
            return OK;
        }
    }
}
Status createBinSortTree(BinTree tree, int *data, int index){
    tree->data = data[index];
    for(int i=index+1; i<=data[0]; i++){
        insert(tree, data[i]);
    }
    return OK;
}

Status find(BinTree tree, ElemType key){
    if(tree){
        if(key == tree->data){
            return OK;
        }else if(key < tree->data){
            find(tree->lchild, key);
        }else{
            find(tree->rchild, key);
        }
    }
}

//midorder traversal
Status midTraversal(BinTree tree){
    if(tree){
        midTraversal(tree->lchild); 
        printf("%d->", tree->data);
        midTraversal(tree->rchild); 
    }
    return OK;
}

int main(){
    BinTree tree;
    init(&tree);
    
    int len = 9;
    int data[10] = {len, 70, 105, 115, 104, 67, 46, 99, 111, 109};

    int index = 1;
    createBinSortTree(tree, data, index);

    printf("Midorder Traversal:\n");
    midTraversal(tree);
    printf("\n");
    
    Status s;
    ElemType e = 67;
    s = find(tree, e); 
    printf("Status:%d\n", s);

    return 0;
}