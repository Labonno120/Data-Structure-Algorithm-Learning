#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node* back;
    Node(int data1, Node* next1, Node* back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
Node* ConvertArr2DLL(vector<int> arr)
{
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;

    }
    return head;
}
Node* deleteHead(Node* head)
{
    if(head==NULL || head->next ==NULL)return NULL;
    Node* temp = head;
    head = head->next;
    temp->next = nullptr;
    head->back = nullptr;
    delete temp;
    return head;
}
Node* deleteTail(Node* head)
{
    if(head==NULL || head->next ==NULL)return NULL;
    Node* temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    Node* newtail = temp->back;
    temp->back = nullptr;
    newtail->next = nullptr;
    delete temp;
    return head;
}
Node* deletekthElement(Node* head,int k)
{
    if(head==NULL)return NULL;
    int cnt =0;
    Node* temp = head;
    while(temp!=NULL)
    {
        cnt++;
        if(cnt==k)break;
        temp = temp->next;
    }
    if(temp->back==NULL)
    {
        head = deleteHead(temp);
        return head;
    }
    if(temp->next==NULL)
    {
        head = deleteTail(temp);
        return head;
    }
    Node* prev = temp->back;
    Node* front = temp->next;

    prev->next = front;
    front->back = prev;
    temp->back = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}
void deleteNode(Node* node)
{
    Node* prev = node->back;
    Node* front = node->next;
    if(front == NULL)
    {
        prev->next = nullptr;
        node->back = nullptr;
        delete node;
        return;
    }

    prev->next = front;
    front->back = prev;
    node->back = nullptr;
    node->next = nullptr;
    delete node;

}
//insertion before head
Node* insertionBeforeHead(Node* head,int val)
{
    Node* temp = head;
    Node* newnode = new Node(val);
    newnode->next = temp;
    temp->back = newnode;
    return newnode;
}
Node* insertionBeforeTail(Node* head,int val)
{
    if(head->next == NULL)
    {
        return insertionBeforeHead(head,val);
    }
    Node* temp = head;
    Node* newnode = new Node(val);
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    Node* prev = temp->back;
    prev->next = newnode;
    newnode->back = prev;
    newnode->next = temp;
    temp->back = newnode;


    return head;
}
Node* insertBeforekthElement(Node* head,int k,int val)
{
    if(k==1)return insertionBeforeHead(head,val);

    int cnt =0;
    Node* temp = head;
    while(temp!=NULL)
    {
        cnt++;
        if(cnt==k)break;
        temp = temp->next;
    }

    Node* newnode = new Node(val);

    Node* prev = temp->back;
    prev->next = newnode;
    newnode->back = prev;
    newnode->next = temp;
    temp->back = newnode;
    return head;
}
void insertionBeforeNode(Node* node,int val)
{
    Node* newnode = new Node(val);
    Node* prev = node->back;
    prev->next = newnode;
    newnode->back = prev;
    newnode->next = node;
    node->back = newnode;
}
void print(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    vector<int> arr={1,2,3,6,7,8,9,4,5};
    Node* head = ConvertArr2DLL(arr);


    print(head);
    head = deleteHead(head);

    cout<<"After deleting the Head:"<<endl;
    print(head);
    head = deleteTail(head);
    cout<<"After deleting the tail:"<<endl;
    print(head);

    head = deletekthElement(head,5);
    cout<<"After deleting the kth element:"<<endl;
    print(head);

    cout<<"After deleting the node:"<<endl;
    deleteNode(head->next->next);
    print(head);

    cout<<"After inserting before the head:"<<endl;
    head = insertionBeforeHead(head,20);
    print(head);

    cout<<"After inserting before the tail:"<<endl;
    head = insertionBeforeTail(head,20);
    print(head);


    cout<<"After inserting before the kth element:"<<endl;
    head = insertBeforekthElement(head,5,100);
    print(head);


    cout<<"After inserting before the node:"<<endl;
    insertionBeforeNode(head->next->next,1000);
    print(head);
}
