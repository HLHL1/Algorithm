

//prim算法
#define USED 0    //已使用，加入U集合
#define NOADJ -1  //非邻接顶点
void Prim(MatrixGraph G)//最小生成树
{
    int i,j,k,min,sum=0;
    int weight[VERTEX_MAX];//权值
    char tmpvertex[VERTEX_MAX];//临时顶点信息

    for(i=1;i<G.VertexNum;i++) //保存邻接矩阵中的一行数据
    {
        weight[i]=G.Edges[0][i]; //权值
        if(weight[i]==MAXVALUE)     //权值为最大值，表示没有这条边
            tmpvertex[i]=NOADJ; //非邻接顶点
        else
            tmpvertex[i]=G.Vertex[0]; //邻接顶点
    }
    tmpvertex[0]=USED; //将0号顶点并入U集
    weight[0]=MAXVALUE; //设已使用顶点权值为最大值
    for(i=1;i<G.VertexNum;i++)
    {
        min=weight[0]; //最小权值
        k=i;
        for(j=1;j<G.VertexNum;j++) //查找权值最小的一个邻接边
            if(weight[j]<min && tmpvertex[j]>0) //找到具有更小权值的未使用边
            {
                min=weight[j]; //保存权值
                k=j; //保存邻接点序号
            }
        sum+=min;//累加权值
        printf("(%c,%c),",tmpvertex[k],G.Vertex[k]); //输出生成树一条边
        tmpvertex[k]=USED; //将编号为k的顶点并入U集
        weight[k]=MAXVALUE; //已使用顶点的权值为最大值
        for(j=0;j<G.VertexNum;j++) //重新选择最小边
            if(G.Edges[k][j]<weight[j] && tmpvertex[j]!=0)
            {
                weight[j]=G.Edges[k][j]; //权值
                tmpvertex[j]=G.Vertex[k]; //上一个顶点信息
            }
    }
    printf("\n最小生成树的总权值为:%d\n",sum);
}




//kruskal算法
typedef struct
{
    char vertex[VertexNum];                                //顶点表
    int edges[VertexNum][VertexNum];                       //邻接矩阵,可看做边表
    int n,e;                                               //图中当前的顶点数和边数
}MGraph;

typedef struct node
{
    int u;                                                 //边的起始顶点
    int v;                                                 //边的终止顶点
    int w;                                                 //边的权值
}Edge;

void kruskal(MGraph G)
{
    int i,j,u1,v1,sn1,sn2,k;
    int vset[VertexNum];                                    //辅助数组，判定两个顶点是否连通
    int E[EdgeNum];                                         //存放所有的边
    k=0;                                                    //E数组的下标从0开始
    for (i=0;i<G.n;i++)
    {
        for (j=0;j<G.n;j++)
        {
            if (G.edges[i][j]!=0 && G.edges[i][j]!=INF)
            {
                E[k].u=i;
                E[k].v=j;
                E[k].w=G.edges[i][j];
                k++;
            }
        }
    }
    heapsort(E,k,sizeof(E[0]));                            //堆排序，按权值从小到大排列
    for (i=0;i<G.n;i++)                                    //初始化辅助数组
    {
        vset[i]=i;
    }
    k=1;                                                   //生成的边数，最后要刚好为总边数
    j=0;                                                   //E中的下标
    while (k<G.n)
    {
        sn1=vset[E[j].u];
        sn2=vset[E[j].v];                                  //得到两顶点属于的集合编号
        if (sn1!=sn2)                                      //不在同一集合编号内的话，把边加入最小生成树
        {
            printf("%d ---> %d, %d",E[j].u,E[j].v,E[j].w);
            k++;
            for (i=0;i<G.n;i++)
            {
                if (vset[i]==sn2)
                {
                    vset[i]=sn1;
                }
            }
        }
        j++;
    }
}
