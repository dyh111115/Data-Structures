#include<iostream>
#include "chazhao.h"
using namespace std;
int shunxuchazhao1(table t,int p){
    for(int i=t.length;i>=1;i--){
        if(t.a[i]==p) return i;
    }
    return 0;
}
int shunxuchazhao2(table t,int p){
    t.a[0]=p;
    for(int i=t.length;;i--){
        if(t.a[i]==p)
        return i;
    }
}
//ASL=(n+1)/2

//数组必须有序
int zhebanchazhao(table t,int p){
    int low=1;
    int high=t.length;
    while(low<=high){
        int mid=(low+high)/2;
        if(p==t.a[mid]){
            return mid;
        }else if(p>=t.a[mid]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
}
//ASL=log₂(n + 1) - 1

//块间有序，块内无序
int fenkuaichazhao(table t,int p){

}
//ASL_bs ≈ log₂(n/s + 1) + s/2

Node* erchachazhao(Node *n,int key){
     if(!n||key==n->a){
          return n;
     }else if(key<n->a){
          return erchachazhao(n->l,key);
     }else{
          return erchachazhao(n->r,key);
     }
}
//最好ASL=[log₂n]-1  最差ASL=(n+1)/2

//二叉树插入
Node* erchacharu(Node *n,int key){
     if(key==n->a){
        return 0;
     }else if(key<=n->a){
        return erchacharu(n->l,key);
     }else{
        return erchacharu(n->r,key);
     }
};

//二叉树构造
void insert(Node* &n, int key) {
    if (n == NULL) {
        n = new Node;
        n->a = key;
        n->l = NULL;
        n->r = NULL;
        return;
    }
    if (key < n->a) {
        insert(n->l, key);
    } else if (key > n->a) {
        insert(n->r, key);
    }
}
Node* erchashengcheng(Node *n,int key[],int a){
    n=NULL;
    int i=0;
    while(i<a){
        insert(n,key[i]);
        i++;
    }
    return n;
};
int main() {
    
}