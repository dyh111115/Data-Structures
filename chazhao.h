//线性表查找
typedef struct{
     int length;
     int *a;
}table;
int shunxuchazhao1(table t,int p);
int shunxuchazhao2(table t,int p);
int zhebanchazhao(table t,int p);
int fenkuaichazhao(table t,int p); 

//树表查找
typedef struct Node{
     int a;
     struct Node *l,*r; 
}Node;
Node* erchachazhao(Node *n,int key);
Node* erchacharu(Node *n,int key);
void insert(Node* &n, int key);
Node* erchashengcheng(Node *n,int key[],int a);
