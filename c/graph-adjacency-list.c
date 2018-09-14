#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define OK 1
#define MAX_VERTEX_NUM 10

typedef int Status;
typedef int VRType; //VRType: vertex relation type
typedef int VertexType;
typedef char InfoType;

//DG:有向图 DN:有向网 UDG:无向图 UDN:无向网
typedef enum {DG,DN,UDG,UDN} GraphKind; 

typedef struct VerCell{
    VRType data; //无权(有向图/无向图)：用来表示边的关系 1或0
                // 有权(有向网/无向网)：用来表示权值
    InfoType *info; //该弧相关信息指针
}VerCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct{
    VertexType vertex[MAX_VERTEX_NUM]; //顶点向量
    AdjMatrix matrix; //邻接矩阵
    int vernum,arcnum; //图的当前顶点数和弧数
    GraphKind kind; //图的类型
}MGraph;
