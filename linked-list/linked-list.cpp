#include <iostream>
using namespace std;

class SingleNode{
    public:
        int data;
        SingleNode* next;

        SingleNode(int value){
            data = value;
            next = nullptr;
        }
};

class SinglyLinkedList{
    private:
        SingleNode* head;
        int size;

    public:
        SinglyLinkedList(){
            head = nullptr;
            size = 0;
        }

        void addFirst(int value){
            SingleNode* node = new SingleNode(value);
            node -> next = head;
            head = node;
            size++;
        }

        void addLast(int value){
            SingleNode* node = new SingleNode(value);
            if(head == nullptr){
                head = node;
                return;
            }
            SingleNode* current = head;
            while(current -> next != nullptr){
                current = current -> next;
            }current -> next = node;
            size++;
        }

        void remove(int value){
            SingleNode* current = head;
            SingleNode* previous = nullptr;

            while(current != nullptr && current -> data != value){
                previous = current;
                current = current -> next;
            }

            if(current != nullptr){
                if(previous != nullptr){
                    previous -> next = current -> next;
                }else{
                    head = current -> next;
                }delete current;
                size--;
            }
        }

        void search(int value){
            SingleNode* current = head;
            int count = 0;
            while(current != nullptr){
                if(current -> data == value){
                    cout<<count<<endl;
                    return;
                }current = current -> next;
                count++;
            }cout<<-1<<endl;
        }

        void get(int index){
            if(index > size-1){
                cout<<"index out of bound!"<<endl;
                return;
            }SingleNode* current = head;
            int count = 0;
            while(index > count){
                current = current -> next;
                count++;
            }cout<<current -> data<<endl;
        }

        void display(){
            SingleNode* current = head;
            if(current == nullptr){
                cout<<"Linked List is empty!"<<endl;
                return;
            }
            while(current != nullptr){
                cout<<current -> data<<" ";
                current = current -> next;
            }cout<<endl;
        }

        void length(){
            cout<<size<<endl;
        }
};

int main(){
    SinglyLinkedList list;
    list.addFirst(3);
    list.addFirst(4);
    list.addFirst(1);
    list.addFirst(2);
    list.addFirst(14);
    list.addFirst(17);
    list.addLast(6);
    list.addFirst(20);
    list.addLast(9);
    list.get(6);
    list.display();
    list.length();
    return 0;
}

