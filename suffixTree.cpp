#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

template <typename T>
class SLL{
    class Node{
    public:
    T data;
    Node*next;
};
public:
    Node*head,*tail;
    int size;
    SLL(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    template <typename T>
    void inserAtHead(T item){
        Node*newNode=new Node;
        newNode->data=item;
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
            
        }
        size++;
    }
    template <typename T>
    void insertAtTail(T item){
          Node*newNode=new Node;
        newNode->data=item;
        newNode->next=NULL;
        if(tail==NULL){
            tail=newNode;
            head=newNode;
        }
        else{
            tail->next=newNode;
            tail=tail->next;
            
        }  
        size++;    
    }
    template <typename T>
    void insertAt(int pos,int item){
        if(pos<0 || pos>size){
            cout<<"invalid pos";
        }
        else{
           
         if(pos ==0){
            inserAtHead(item);
        }
        else if(pos==size-1){
            insertAtTail(item);
        }
        else{
             Node*newnode=new Node;
            newnode->data=item;
            Node*curr=head;
            for(int i=1;i<pos;i++){
                
                curr=curr->next;
            }
            newnode->next=curr->next;
            curr->next=newnode;
            size++;
        }
    }
    }
    void swapNode(int firstItemIdx, int secondItemIdx) {
        if (firstItemIdx == secondItemIdx) {
            return;
        }
        Node* prevX = nullptr;
        Node* currX = head;
        int i = 0;
        while (currX != nullptr && i < firstItemIdx) {
            prevX = currX;
            currX = currX->next;
            i++;
        }
        Node* prevY = nullptr;
        Node* currY = head;
        i = 0;
        while (currY != nullptr && i < secondItemIdx) {
            prevY = currY;
            currY = currY->next;
            i++;
        }
        if (currX == nullptr || currY == nullptr) {
            cout << "Index out of range!" << endl;
            return;
        }
        if (prevX != nullptr) {
            prevX->next = currY;
        }
        else {
            head = currY;
        }
        if (prevY != nullptr) {
            prevY->next = currX;
        }
        else {
            head = currX;
        }
        Node* temp = currX->next;
        currX->next = currY->next;
        currY->next = temp;
    }
    void removeAt(int pos){
         if(pos<0 || pos>size){
            cout<<"invalid pos";
        }
        else{
           
         if(pos ==0){
            removeAtHead();
        }
        else if(pos==size-1){
            removeAtTail();
        }
        else{
             
            Node*curr=head->next;
            Node*prev=head;
            for(int i=1;i<pos;i++){
                
                prev=curr;
                curr=curr->next;
            }
            prev->next=curr->next;
            free(curr);
            size--;
        }
    }   
    }
    template <typename T>
    bool isItemAtEqual(T element,int pos){
                    if(pos<0 || pos>size){
            cout<<"invalid pos";
            return 0;
        }
        else{
        if(pos==0){
            return element==head->data;
        }
        else if(pos==size-1){
            return element==tail->data;
        }
            else{
            Node*curr=head->next;
            Node*prev=head;
            for(int i=1;i<pos;i++){
                
                prev=curr;
                curr=curr->next;
            }
            
        return element==curr->data;
    } 
     }  
    }
    int retrieveAt(int pos){
    
             if(pos<0 || pos>size){
            cout<<"invalid pos";
            return 0;
        }
        else{
        if(pos==0){
            return head->data;
        }
        else if(pos==size-1){
            return tail->data;
        }
            else{
            Node*curr=head->next;
            Node*prev=head;
            for(int i=1;i<pos;i++){
                
                prev=curr;
                curr=curr->next;
            }
            
        return curr->data;
    } 
     }  
    }
    void removeAtTail(){
                  Node*curr=head->next;
                  Node*prev=head;
        while(curr!=tail){
            prev=curr;
            curr=curr->next;
        }
       free(curr);
       prev->next=NULL;
       tail=prev;
            
        size--;  
    }
    template <typename T>
    void replaceAt(T element,int pos){
             if(pos<0 || pos>size){
            cout<<"invalid pos";
            
        }
        else{
        if(pos==0){
            head->data=element;
        }
        else if(pos==size-1){
           tail->data=element;
        }
            else{
            Node*curr=head->next;
            Node*prev=head;
            for(int i=1;i<pos;i++){
                
                prev=curr;
                curr=curr->next;
            }
            
       curr->data=element;
    } 
     }
    }
    template <typename T>
    bool isExist(T element){
                   if(head->data==element){
            return true;}
            else{
                 Node*curr=head->next;
            Node*prev=head;
            int flag=0;
            for(int i=1;i<size-2;i++){
                if(curr->data==element){
                    flag=1;
                    break;
                }
                else{
                prev=curr;
                curr=curr->next;

                }
            }
            if(flag==1){
                return true;
            }
            else{
                if(tail->data==element){
                    return true;
                }
                else{
                    return false;
                }
            }
            
            }
       


    }
    void removeAtHead(){
            Node*curr=new Node;
        if(curr==NULL){
            head=NULL;
            tail=NULL;
        }
        else{
            curr=head;
            head=head->next;
            free(curr);
            
        }
            
        size--;
    }
    void print(){
        Node*curr=head;
        while (curr!=NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
     bool isEmpty(){
        return size==0;
    } 
     void clear(){
        size=0;
    }
    int listsize(){
        return size;
    }
};


class TreeNode {
public:
    SLL<TreeNode> list;
    int id;
    int st;
TreeNode(SLL<TreeNode> list,int id,int st){
this->list=list;
this->id=id;
this->st=st;

}

};
#include <cstring>

class SuffixTree {
    TreeNode * root;
public:
    SuffixTree(const char* str) {
        int length = strlen(str);

        for (int i = 0; i < length; i++) {
            int result = strncmp(str + i, str, 2);
            cout<<result<<" ";
        }
    }
};

int main() {
    const char* exampleString = "banana$";
    SuffixTree suffixTree(exampleString);

    return 0;
}
