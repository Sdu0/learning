#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 2147483647 //最大值∞
#define ERROR -1
#define OK 1
#define MAX_VERTEX_NUM 10

typedef int Status;
typedef int VRType; //VRType: vertex relation type
typedef char VertexName;
typedef char InfoType;

//DG:有向图 DN:有向网 UDG:无向图 UDN:无向网
typedef enum {DG,DN,UDG,UDN} GraphKind; 

typedef struct VerCell{
    VRType data; //无权(有向图/无向图)：用来表示边的关系 1或0
                // 有权(有向网/无向网)：用来表示权值
    InfoType *info; //该弧相关信息指针
}VerCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct{
    VertexName vertex[MAX_VERTEX_NUM]; //顶点向量
    AdjMatrix matrix; //邻接矩阵
    int vernum,arcnum; //图的当前顶点数和弧数
    GraphKind kind; //图的类型
}MGraph;

void printAdjMatrix(MGraph *mg){
    for(int i=0; i<mg->vernum; i++){
        for(int j=0; j<mg->vernum; j++){
            if(mg->matrix[i][j].data == INT_MAX){
                printf("∞ ");
            }else{
                printf("%d  ", mg->matrix[i][j].data);
            }
        }
        printf("\n");
    }
}

//创建有向图
Status createDG(MGraph *mg){
    printf("=============LINE============\n");
    printf("请输入顶点数:\n");
    scanf("%d", &mg->vernum);
    getchar();
    if(mg->vernum > MAX_VERTEX_NUM) return ERROR;
    printf("请输入弧数:\n");
    scanf("%d", &mg->arcnum);
    getchar();
    if(mg->arcnum > MAX_VERTEX_NUM) return ERROR;

    //init vertex
    printf("请输入顶点向量:\n");
    for(int i=0; i<mg->vernum; i++) {
        scanf("%c", &mg->vertex[i]); 
        getchar();
    }
    
    //init adjacency list
    for(int i=0; i<mg->vernum; i++){
        for(int j=0; j<mg->vernum; j++){
            if(i == j){
                mg->matrix[i][j].data = 0;
                continue;
            }
            printf("向量%c是否指向向量%c?[1:是 0:否]\n", mg->vertex[i], mg->vertex[j]);
            scanf("%d", &mg->matrix[i][j].data);
            getchar();
        }
        printf("\n");
    }
    printf("=============LINE============\n");
    printf("Digrahp:\n");
    printAdjMatrix(mg);

    return OK;
}

//创建有向网
Status createDN(MGraph *mg){
    printf("=============LINE============\n");
    printf("请输入顶点数:\n");
    scanf("%d", &mg->vernum);
    getchar();
    if(mg->vernum > MAX_VERTEX_NUM) return ERROR;
    printf("请输入弧数:\n");
    scanf("%d", &mg->arcnum);
    getchar();
    if(mg->arcnum > MAX_VERTEX_NUM) return ERROR;

    //init vertex
    printf("请输入顶点向量:\n");
    for(int i=0; i<mg->vernum; i++) {
        scanf("%c", &mg->vertex[i]); 
        getchar();
    }
    
    //init adjacency list
    for(int i=0; i<mg->vernum; i++){
        for(int j=0; j<mg->vernum; j++){
            if(i == j){
                mg->matrix[i][j].data = INT_MAX;
                continue;
            }
            printf("向量%c到向量%c的权(无:-1 有:具体值):\n", mg->vertex[i], mg->vertex[j]);
            scanf("%d", &mg->matrix[i][j].data);
            getchar();
            if(mg->matrix[i][j].data == -1){
                mg->matrix[i][j].data = INT_MAX;
            }
        }
        printf("\n");
    }
    printf("=============LINE============\n");
    printf("Direct net:\n");
    printAdjMatrix(mg);

    return OK;

}

//创建无向图
Status createUDG(MGraph *mg){
    printf("=============LINE============\n");
    printf("请输入顶点数:\n");
    scanf("%d", &mg->vernum);
    getchar();
    if(mg->vernum > MAX_VERTEX_NUM) return ERROR;
    printf("请输入弧数:\n");
    scanf("%d", &mg->arcnum);
    getchar();
    if(mg->arcnum > MAX_VERTEX_NUM) return ERROR;

    //init vertex
    printf("请输入顶点向量:\n");
    for(int i=0; i<mg->vernum; i++) {
        scanf("%c", &mg->vertex[i]); 
        getchar();
    }
    
    //init adjacency list
    for(int i=0; i<mg->vernum; i++){
        for(int j=0; j<mg->vernum; j++){
            if(i == j){
                mg->matrix[i][j].data = 0;
                continue;
            }
            printf("向量:%c与向量:%c有无关联?[1:有 0:无]\n", mg->vertex[i], mg->vertex[j]);
            scanf("%d", &mg->matrix[i][j].data);
            getchar();
        }
        printf("\n");
    }
    printf("=============LINE============\n");
    printf("UnDigrahp:\n");
    printAdjMatrix(mg);

    return OK;
}

//创建无向网
Status createUDN(MGraph *mg){
    printf("=============LINE============\n");
    printf("请输入顶点数:\n");
    scanf("%d", &mg->vernum);
    getchar();
    if(mg->vernum > MAX_VERTEX_NUM) return ERROR;
    printf("请输入弧数:\n");
    scanf("%d", &mg->arcnum);
    getchar();
    if(mg->arcnum > MAX_VERTEX_NUM) return ERROR;

    //init vertex
    printf("请输入顶点向量:\n");
    for(int i=0; i<mg->vernum; i++) {
        scanf("%c", &mg->vertex[i]); 
        getchar();
    }
    
    //init adjacency list
    for(int i=0; i<mg->vernum; i++){
        for(int j=0; j<mg->vernum; j++){
            if(i == j){
                mg->matrix[i][j].data = INT_MAX;
                continue;
            }
            printf("向量%c与向量%c间的权(无:-1 有:具体值):\n", mg->vertex[i], mg->vertex[j]);
            scanf("%d", &mg->matrix[i][j].data);
            getchar();
            if(mg->matrix[i][j].data == -1){
                mg->matrix[i][j].data = INT_MAX;
            }
        }
        printf("\n");
    }
    printf("=============LINE============\n");
    printf("Undirect net:\n");
    printAdjMatrix(mg);

    return OK;
}

Status createGraph(MGraph *mg){
    printf("Choise Graph kind:\n1.Digraph\n2.Direct net\n3.Undigraph\n4.Undirect net\n");
    scanf("%d", &mg->kind);
    getchar();//接收多余字符
    if(mg->kind == 1){
        createDG(mg);
    }else if(mg->kind == 2){
        createDN(mg);
    }else if(mg->kind == 3){
        createUDG(mg);
    }else if(mg->kind == 4){
        createUDN(mg);
    }else{
        return ERROR;
    }
}

int main(){
    MGraph mg;
    createGraph(&mg);
    return 0;
}
