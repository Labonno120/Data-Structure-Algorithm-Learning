#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;      // stores the data of this node
    Node* next;    // pointer to the next node

    // constructor 1: allows creating a node with data + pointer
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // constructor 2: allows creating a node with only data
    Node(int data1) {
        data = data1;
        next = nullptr;   // by default, no next node
    }
};

Node* ConvertArr2LL(vector<int> &arr) {
    Node* head = new Node(arr[0]); // create first node
    Node* mover = head;            // 'mover' points to last node we created

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]); // create new node
        mover->next = temp;            // link previous node to new one
        mover = temp;                  // move 'mover' forward
    }
    return head;  // return head pointer (start of linked list)
}
void print(Node* head)
{
    Node* temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;

    }
    cout<<endl;
}
Node* deleteHead(Node* head)
{

    if(head== NULL)
        return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node* deleteTail(Node* head)
{

    if(head==NULL || head->next == NULL)
    {

        return NULL;
    }
    else{
        Node* temp = head;
        while(temp->next->next != NULL)
        {

            temp = temp->next;
        }
        free(temp->next);
        temp->next = nullptr;
        return head;
    }
}
Node* deletekthElement(Node* head,int k)
{

    if(head == NULL)return NULL;
    if(k==1)
    {

        Node* temp;
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* prev= NULL;
    Node* temp = head;
    int cnt =0;
    while(temp!= NULL)
    {

        cnt++;
        if(cnt==k)
        {

            prev->next = prev->next->next;
            free(temp);
            break;
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }
    return head;


}
Node* deletekthElement(Node* head,int k)
{

    if(head == NULL)return NULL;
    if(k==1)
    {

        Node* temp;
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* prev= NULL;
    Node* temp = head;
    int cnt =0;
    while(temp!= NULL)
    {

        cnt++;
        if(cnt==k)
        {

            prev->next = prev->next->next;
            free(temp);
            break;
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }
    return head;


}
/////inerstion into the first position

Node* insertHead(Node* head, int val)
{

    Node* newnode = new Node(val);
    newnode->next = head;
    return newnode;
}

Node* insertTail(Node* head, int val)
{

    Node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;

    }
    Node* newnode = new Node(val);
    temp->next = newnode;
    return head;
}
Node* insertkthelement(Node* head, int val,int k)
{
    if(head==NULL)
    {
        if(k==1)return new Node(val);
        else return NULL;
    }
    else if(k==1)
    {
        return new Node(val,head);
    }
    Node* temp = head;
    int cnt=0;
    while(temp!=NULL)
    {
        cnt++;
        if(cnt == k-1){
        Node* newnode = new Node(val);
        newnode->next = temp->next;
        temp->next = newnode;
        break;
        }
        temp= temp->next;
    }
    return  head;
}

Node* insertBeforeValue(Node* head, int val,int k)
{
    if(head == NULL)
    {
        return new Node(val);
    }
    if(head->data == k)
    {
        return new Node(val,head);
    }
    Node* temp = head;
    Node* prev = NULL;


    while(temp!=NULL)
    {

        if(temp->data == k){
        Node* newnode = new Node(val);
        newnode->next = temp;
        prev->next = newnode;
        break;
        }
        else{
        prev = temp;
        temp= temp->next;
        }
    }
    return  head;
}

int main()
{
    vector<int> arr={2,5,12,34,56,6,3};

    Node* head = ConvertArr2LL(arr);
    print(head);

    head = deleteHead(head);
    head = deleteTail(head);
    head = deletekthElement(head,4);
    print(head);

    //insertion
    head = insertHead(head,10);
    print(head);
    head = insertTail(head,10);
    print(head);
    head = insertkthelement(head,100,4);
    print(head);
    head = insertBeforeValue(head,200,12);
    print(head);



}
