#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int value;
    vector<Node*>neibor;
    bool visited;
    Node(int a){
        value=a;
        visited=false;

    }

};
void visit(Node*a){

    if (a->visited==true){
        return ;
    }
    a->visited=true;
    for (int i=0;i<a->neibor.size();i++){
        visit(a->neibor[i]);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    if (n==0)
        cout<<0;
    else if (n==1)
        cout<<1;
    else{
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
        int amou=0;
        for (int i=0;i<nList.size();i++){
            if (nList[i]->visited==true)
                continue;
            else {
                if (nList[i]->neibor.size()==0){
                    amou++;
                    nList[i]->visited=true;
                }
                else {
                    amou++;
                    visit(nList[i]);
                }
            }



        }
        cout<<amou;
    }
}
