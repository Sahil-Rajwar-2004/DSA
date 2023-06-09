#include <iostream>
using namespace std;

class DoublyNode{
    public:
        int data;
        DoublyNode* next;
        DoublyNode* previous;

        DoublyNode(int value){
            data = value;
            next = nullptr;
            previous = nullptr;
        }
};

class DoublyLinkedList{
    private:
        DoublyNode* head;
        DoublyNode* tail;
        int size;

    public:
        DoublyLinkedList(){
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        void addFirst(int value) {
            DoublyNode* newNode = new DoublyNode(value);
            if (head == nullptr){
                head = newNode;
                tail = newNode;
            } else {
                newNode -> next = head;
                head -> previous = newNode;
                head = newNode;
            }size++;
        }

        void addLast(int value){
            DoublyNode* newNode = new DoublyNode(value);
            if (tail == nullptr){
                head = newNode;
                tail = newNode;
            } else {
                tail -> next = newNode;
                newNode -> previous = tail;
                tail = newNode;
            }size++;
        }

        void showForward(){
            DoublyNode* current = head;
            while(current != nullptr){
                cout<<current -> data<<" ";
                current = current -> next;
            }cout<<endl;
        }

        void showBackward(){
            DoublyNode* current = tail;
            while(current != nullptr){
                cout<<current -> data<<" ";
                current = current -> previous;
            }cout<<endl;
        }

        void remove(int value){
            DoublyNode* current = head;
            while(current != nullptr){
                if(current -> data == value){
                    if(current == head){
                        head = current -> next;
                        if(head != nullptr){
                            head -> previous = nullptr;
                        }
                    }else if(current == tail){
                        tail = current -> previous;
                        if(tail != nullptr){
                            tail -> next = nullptr;
                        }
                    }else{
                        current -> previous -> next = current -> next;
                        current -> next -> previous = current -> previous;
                    }
                    DoublyNode* nodetoremove = current;
                    current = current -> next;
                    delete nodetoremove;
                    size--;
                }else{
                    current = current -> next;
                }
            }
        }

        void display(){
            DoublyNode* current = head;
            if(current == nullptr){
                cout<<"Linked List is empty!"<<endl;
                return;
            }
            while(current != nullptr){
                cout<<current -> data<<" ";
                current = current -> next;
            }
            cout<<endl;
        }

        void search(int value){
            DoublyNode* current = head;
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
            if(index < 0||index >= size){
                cout<<"invalid index"<<endl;
                return;
            }
            DoublyNode* current = head;
            int count = 0;
            while(index > count){
                current = current -> next;
                count++;
            }
            cout<<current -> data<<endl;
        }

        void length(){
            cout<<size<<endl;
        }
};

int main(){
    DoublyLinkedList list;
    list.addFirst(3);
    list.addFirst(4);
    list.addFirst(1);
    list.addFirst(2);
    list.addFirst(14);
    list.addFirst(17);
    list.addLast(6);
    list.addFirst(20);
    list.addLast(9);
    list.display();
    list.get(5);
    list.search(14);
    list.length();
    return 0;
}
