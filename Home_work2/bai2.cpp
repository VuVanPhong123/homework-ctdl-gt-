
#include<bits/stdc++.h>
using namespace std;
struct node{
    int value;
    node* next;
};
node* add_element(node*a,int val){
    if (a==NULL){
        node*temp=new node;
        temp->value=val;
        temp->next=NULL;
        a=temp;
    }
    else {
        node*b=a;
        while (b->next!=a){
            b=b->next;
        }
        node*temp=new node;
        b->next=temp;
        temp->value=val;
        temp->next=NULL;
    }
    return a;
}
node* insert_head(node* a,int val){
    node*temp =new node;
    if(a==NULL)
        a=add_element(a,val);
    else {
        node*temp=new node;
        temp->value=val;
        temp->next=a;
        a=temp;
    }
    return a;
}
node* insert_tail(node* a,int val){
    node*temp=new node;
    temp->value=val;
    temp->next =NULL;
    node*b=a;
    while (b->next!=NULL){
        b=b->next;
    }
    b->next=temp;
    return a;

}
node* insert_place(node* a,int val,int k){
    node*temp=new node;
    node*b=a;
    for (int i=0;i<k-1;i++){
        b=b->next;
    }
    temp->value=val;
    temp->next=b->next;
    b->next=temp;
    return a;
}
node* delete_head(node* a){
    if (a!=NULL){
        node*temp=a;
        a=a->next;
        delete(temp);
    }
    return a;
}
node* delete_tail(node*a){
    if (a!=NULL){
        node*temp=a;
        while((temp->next)->next!=NULL){
            temp=temp->next;
        }
        delete(temp->next);
        temp->next=NULL;
    }
    return a;
}
node* delete_place(node*a,int k){
    if (a!=NULL){
        node* temp=a;
        for (int i=0;i<k-1;i++){
            temp=temp->next;
        }
        node* b=temp->next;
        temp->next=(temp->next)->next;
        delete(b);
        return a;
    }
}
int main(){
    int n;
    cin>>n;
    int b,c;
    int num=0;
    node* a=NULL;
    for (int i=0;i<n;i++){
        string line;
        cin>>line;
        if (line=="insert"){
            cin>>b>>c;
            if (b==0){
                a=insert_head(a,c);
                num++;
            }
            else if (b==num){
                a=insert_tail(a,c);
                num++;
            }
            else {
                a=insert_place(a,c,b);
                num++;
            }
        }
        else if (line=="delete"){
            cin>>b;
            if (b==0){
                a=delete_head(a);
                num--;
            }
            else if (b==num-1){
                a=delete_tail(a);
                num--;
            }
            else {
                a=delete_place(a,b);
                num--;
            }
        }

    }
    while (a!=NULL){
        cout<<a->value<<" ";
        a=a->next;
    }
}
