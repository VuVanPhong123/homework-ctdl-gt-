#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
    int value;
    vector<TreeNode*>children;
    TreeNode(int val){
        value=val;
    }
};
void* adding_node(TreeNode* father, TreeNode* child){

    father->children.push_back(child);
}
int calculate_height(TreeNode* head){
    if (head->children.size()==0){
        return 0;
    }
    else {
        int max_height=0;
        for (int i=0;i<head->children.size();i++){
            int child_height=calculate_height(head->children[i]);
            max_height=max(child_height,max_height);
        }
        return 1+max_height;
    }

}
void preoder_traversal(TreeNode* head){
    if (head->children.size()==0){
        cout<<head->value<<" ";
        return ;
    }
    cout<<head->value<<" ";
    for (int i=0;i<head->children.size();i++){
        preoder_traversal(head->children[i]);
    }
}
void postoder_traversal(TreeNode* head){
    if (head->children.size()==0){
        cout<<head->value<<" ";
        return ;
    }
    for (int i=0;i<head->children.size();i++){
        postoder_traversal(head->children[i]);
    }
    cout<<head->value<<" ";
}
void in_order(TreeNode* head){
    if (head->children.size()==0){
        cout<<head->value<<" ";
        return ;
    }
    in_order(head->children[0]);
    cout<<head->value<<" ";
    in_order(head->children[1]);

}
void check_tree(vector<TreeNode*> Tree){
    bool check=1;
    for (int i=0;i<Tree.size();i++){
        if (Tree[i]->children.size()>2){
            cout<<"NOT BINARY TREE";
            check=0;
            break;
        }
    }
    if (check==1){
        in_order(Tree[0]);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<TreeNode*> Tree(n);
    for (int i=0;i<n;i++){
        Tree[i]=new TreeNode(i+1);
    }
    for (int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adding_node(Tree[u-1],Tree[v-1]);
    }
    cout<<calculate_height(Tree[0])<<endl;
    preoder_traversal(Tree[0]);
    cout<<endl;
    postoder_traversal(Tree[0]);
    cout<<endl;
    check_tree(Tree);

}
