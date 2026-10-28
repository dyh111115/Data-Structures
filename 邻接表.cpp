#include<iostream>
using namespace std;
#define mmax 1000

struct ArcNode; // 前向声明

typedef struct VNode {
    int data;
    ArcNode *first;
} VNode;

// 为了直观，建议直接定义别名， node[mmax] 有点绕
typedef VNode node[mmax]; 

typedef struct ArcNode {
    int a;           // 邻接点在数组中的下标
    ArcNode *next;
} ArcNode;

typedef struct {
    int m, n;        // m:顶点数，n:边数
    node a;          // a 是顶点数组
} linjiebiao;

// 查找顶点 v 的下标
int locate(linjiebiao &z, int v) {
    for (int i = 0; i < z.m; i++) {
        if (z.a[i].data == v) {
            return i;
        }
    }
    return -1; 
}

/*创建邻接表*/
void create(linjiebiao &z) {
    cout << "输入顶点数m和边数n: ";
    cin >> z.m >> z.n; // 假设先输入顶点数，再输入边数

    // 1. 创建顶点表
    cout << "输入" << z.m << "个顶点的值: ";
    for (int i = 0; i < z.m; i++) { 
        cin >> z.a[i].data;         
        z.a[i].first = NULL;
    }

    // 2. 创建邻接表
    cout << "输入" << z.n << "条边(例如: 1 2): " << endl;
    for (int k = 0; k < z.n; k++) {
        int v1, v2;               
        cin >> v1 >> v2;
        
        int u = locate(z, v1);      
        int v = locate(z, v2);   
        
        if (u == -1 || v == -1) {
            cout << "输入的顶点不存在，请重新输入!" << endl;
            k--; 
            continue;
        }

        // 头插法：将 v2 插入到 v1 的边表中
        ArcNode *p1 = new ArcNode;  
        p1->a = v;
        p1->next = z.a[u].first;   
        z.a[u].first = p1;
    }
}
