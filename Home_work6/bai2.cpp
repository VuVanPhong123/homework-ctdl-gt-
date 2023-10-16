#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int value;
    int distan;
    int real_distan;
    vector<Node*>neibor;
    bool visited;
    Node(int a){
        value=a;
        visited=false;
        distan=0;
        real_distan=10000;

    }

};
void visit(Node* a,Node* b){
    if (a==b){
        if (a->distan<b->real_distan)
            b->real_distan=a->distan;
        return ;
    }
    if (a->visited==true){
        return ;
    }
    a->visited=true;
    for (int i=0;i<a->neibor.size();i++){
        if (a->neibor[i]->visited==false){
            a->neibor[i]->distan=a->distan+1;
            visit(a->neibor[i],b);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    int place1,place2;
    cin>>place1>>place2;

    vector<Node*> nList;
    for (int i=1;i<=n;i++){
        Node* a= new Node(i);
        nList.push_back(a);
    }
    for (int i=0;i<m;i++){
        int node1,node2;
        cin>>node1>>node2;
        nList[node1-1]->neibor.push_back(nList[node2-1]);
        nList[node2-1]->neibor.push_back(nList[node1-1]);
    }
    visit(nList[place1-1],nList[place2-1]);
    for (int i=0;i<n;i++)
        cout<<nList[i]->distan;

}
