#include<bits/stdc++.h>
using namespace std;
struct node{
    int value;
    node* next;
    node* pre;
};
struct dou_List{
    node* head;
    node* tail;
};
dou_List* add_element(dou_List* l,int val){
    if (l->head==NULL){
        node* temp=new node;
        temp->value=val;
        temp->next=NULL;
        temp->pre=NULL;
        l->head=temp;
        l->tail=temp;
    }
    else {
        node* temp=new node;
        temp->next=NULL;
        temp->pre=l->tail;
        temp->value=val;
        l->tail->next=temp;
        l->tail=temp;
    }
    return l;
}
int main(){
    int n,x;
    cin>>n;
    dou_List* l=new dou_List;
    l->head=NULL;
    for (int i=0;i<n;i++){
        cin>>x;
        l=add_element(l,x);

    }
    int sum=0;
    int pos1,pos2,pos3;
    node* temp=l->head;
    while (temp!=NULL){
        if (temp->pre==NULL){
            pos1=0;
        }
        else pos1=(temp->pre)->value;
        pos2=temp->value;
        if (temp->next==NULL){
            pos3==0;
        }
        else pos3=(temp->next)->value;
        if ((pos1+pos2+pos3)==0)
            sum++;
        temp=temp->next;
    }
    cout<<sum;
}
