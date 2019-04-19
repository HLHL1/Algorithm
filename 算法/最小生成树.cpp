

//prim�㷨
#define USED 0    //��ʹ�ã�����U����
#define NOADJ -1  //���ڽӶ���
void Prim(MatrixGraph G)//��С������
{
    int i,j,k,min,sum=0;
    int weight[VERTEX_MAX];//Ȩֵ
    char tmpvertex[VERTEX_MAX];//��ʱ������Ϣ

    for(i=1;i<G.VertexNum;i++) //�����ڽӾ����е�һ������
    {
        weight[i]=G.Edges[0][i]; //Ȩֵ
        if(weight[i]==MAXVALUE)     //ȨֵΪ���ֵ����ʾû��������
            tmpvertex[i]=NOADJ; //���ڽӶ���
        else
            tmpvertex[i]=G.Vertex[0]; //�ڽӶ���
    }
    tmpvertex[0]=USED; //��0�Ŷ��㲢��U��
    weight[0]=MAXVALUE; //����ʹ�ö���ȨֵΪ���ֵ
    for(i=1;i<G.VertexNum;i++)
    {
        min=weight[0]; //��СȨֵ
        k=i;
        for(j=1;j<G.VertexNum;j++) //����Ȩֵ��С��һ���ڽӱ�
            if(weight[j]<min && tmpvertex[j]>0) //�ҵ����и�СȨֵ��δʹ�ñ�
            {
                min=weight[j]; //����Ȩֵ
                k=j; //�����ڽӵ����
            }
        sum+=min;//�ۼ�Ȩֵ
        printf("(%c,%c),",tmpvertex[k],G.Vertex[k]); //���������һ����
        tmpvertex[k]=USED; //�����Ϊk�Ķ��㲢��U��
        weight[k]=MAXVALUE; //��ʹ�ö����ȨֵΪ���ֵ
        for(j=0;j<G.VertexNum;j++) //����ѡ����С��
            if(G.Edges[k][j]<weight[j] && tmpvertex[j]!=0)
            {
                weight[j]=G.Edges[k][j]; //Ȩֵ
                tmpvertex[j]=G.Vertex[k]; //��һ��������Ϣ
            }
    }
    printf("\n��С����������ȨֵΪ:%d\n",sum);
}




//kruskal�㷨
typedef struct
{
    char vertex[VertexNum];                                //�����
    int edges[VertexNum][VertexNum];                       //�ڽӾ���,�ɿ����߱�
    int n,e;                                               //ͼ�е�ǰ�Ķ������ͱ���
}MGraph;

typedef struct node
{
    int u;                                                 //�ߵ���ʼ����
    int v;                                                 //�ߵ���ֹ����
    int w;                                                 //�ߵ�Ȩֵ
}Edge;

void kruskal(MGraph G)
{
    int i,j,u1,v1,sn1,sn2,k;
    int vset[VertexNum];                                    //�������飬�ж����������Ƿ���ͨ
    int E[EdgeNum];                                         //������еı�
    k=0;                                                    //E������±��0��ʼ
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
    heapsort(E,k,sizeof(E[0]));                            //�����򣬰�Ȩֵ��С��������
    for (i=0;i<G.n;i++)                                    //��ʼ����������
    {
        vset[i]=i;
    }
    k=1;                                                   //���ɵı��������Ҫ�պ�Ϊ�ܱ���
    j=0;                                                   //E�е��±�
    while (k<G.n)
    {
        sn1=vset[E[j].u];
        sn2=vset[E[j].v];                                  //�õ����������ڵļ��ϱ��
        if (sn1!=sn2)                                      //����ͬһ���ϱ���ڵĻ����ѱ߼�����С������
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
