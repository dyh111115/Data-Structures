#include<iostream>
#include<queue> // 补充队列头文件
using namespace std;
#define MVNum 100       // 最大顶点数

// 1. 邻接矩阵图的结构体定义
typedef struct {
    int vexs[MVNum];            // 顶点表（一维数组），存顶点数据
    int arcs[MVNum][MVNum];     // 邻接矩阵（二维数组），存边信息
    int vexnum, arcnum;         // 图的当前顶点数(vertex)和边数(arc)
} AMGraph;

// 2. 辅助函数：查找顶点 v 在顶点表中的下标
int LocateVex(AMGraph &G, int v) {
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vexs[i] == v) {
            return i;
        }
    }
    return -1; // 找不到返回 -1
}

// 3. 初始化并创建邻接矩阵（无向图）
void CreateUDN(AMGraph &G) {
    // 第一步：输入总顶点数和总边数
    cout << "请输入顶点数和边数: ";
    cin >> G.vexnum >> G.arcnum;

    // 第二步：建立顶点表
    cout << "请依次输入 " << G.vexnum << " 个顶点的值: ";
    for (int i = 0; i < G.vexnum; i++) {
        cin >> G.vexs[i];
    }

    // 第三步：初始化邻接矩阵（全部置为 0）
    for (int i = 0; i < G.vexnum; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            G.arcs[i][j] = 0; 
        }
    }

    // 第四步：构造邻接矩阵（输入边）
    cout << "请依次输入 " << G.arcnum << " 条边 (例如: 1 2): " << endl;
    for (int k = 0; k < G.arcnum; k++) {
        int v1, v2;
        cin >> v1 >> v2;
        
        // 找到两个顶点在数组中的下标
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);

        // 因为是无向图，所以是对称的
        G.arcs[i][j] = 1; 
        G.arcs[j][i] = 1; // 无向图必须加上反向的边
    }
    cout << "邻接矩阵创建成功！" << endl;
}

/*
深度优先遍历 
*/
bool visit[MVNum] = { false };
void DFS(AMGraph a, int v) {
    cout << v << " "; 
    visit[v] = true;
    for (int i = 0; i < a.vexnum; i++) {
        if (!visit[i] && a.arcs[v][i] != 0) {
            DFS(a, i);
        }
    }
}

/*
广度优先遍历(队列实现)
*/
void BFS(AMGraph G, int v) {
    bool visited[MVNum] = { false }; // BFS的局部访问标记数组
    queue<int> Q;                    // 使用C++ STL标准队列
    
    cout << v << " ";                // 访问第v个顶点
    visited[v] = true;               // 标记为已访问
    Q.push(v);                       // v进队

    while (!Q.empty()) {             // 队列非空
        int u = Q.front();           // 获取队头元素并置为u
        Q.pop();                     // 队头元素出队

        // 遍历 u 的所有邻接顶点 (在邻接矩阵中即为遍历第u行)
        for (int w = 0; w < G.vexnum; w++) {
            // 如果w是u的邻接顶点且尚未被访问
            if (G.arcs[u][w] != 0 && !visited[w]) {
                cout << w << " ";        // 访问w
                visited[w] = true;       // 标记w已访问
                Q.push(w);               // w进队
            }
        }
    }
}

