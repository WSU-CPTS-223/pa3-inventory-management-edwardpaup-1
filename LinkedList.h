#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Node {
private:
    Node<T>* pNext;
    T Data;
public:
    Node();
    Node(T newData);
    Node<T>* getPNext();
    void setPNext(Node<T>* newNext);
    T getData();
    void setData(T newData);
};

template <typename T>
class List {
private:
    Node<T>* pHead;

public: 
    List();
    ~List();

    Node<T>* getPHead();
    void setPHead(Node<T>* pHead_new);

    void insertAtFront(T newData);
    void insertInOrder(T newData);
    int removeNode(std::string command);
    void storeList(std::string file);
    void printList();

    friend ostream& operator<<(ostream& lhs, List rhs){
        Node<T>* current = new Node<T>();
        while(current != NULL){
            lhs << current->getData() << ",";
            current = current->getPNext();
        }
        return lhs;
    }
};


template <typename T>
Node<T>::Node() {      //Constructor initializing pNext
    pNext = nullptr;
}

template <typename T>
Node<T>::Node(T newData) {   //Constructor that uses data input to make new node
    pNext = nullptr;
    Data = newData;
}

template <typename T>
Node<T>* Node<T>::getPNext() {
    return pNext;
}

template <typename T>
void Node<T>::setPNext(Node<T>* newNext) {
    pNext = newNext;
}

template <typename T>
T Node<T>::getData() {
    return Data;
}

template <typename T>
void Node<T>::setData(T newData) {
    Data = newData;
}


template <typename T>
List<T>::List() {
    pHead = nullptr;
}

template <typename T>
List<T>::~List() {
    Node<T>* current = pHead;   //pointer starts at node
    Node<T>* next;
    while (current != nullptr) { //while not at end of list
        next = current->getPNext(); //set next pointer to keep track
        delete current; //delete current pointer
        current = next; //set current to nex pointer
    }
    pHead = nullptr; //set pHead to null
}

template <typename T>
Node<T>* List<T>::getPHead() {
    return pHead;
}

template <typename T>
void List<T>::setPHead(Node<T>* pHead_new) {
    pHead = pHead_new;
}

//Function name: insertAtFront
//Purpose: Inserts new node at front of list
//Parameters: newData to be added to new node
//Return value: none
//Date: 09/18/2025

template <typename T>
void List<T>::insertAtFront(T newData) {
    Node<T>* pNew = new Node<T>(newData); //initialize new node
    if (pHead != nullptr) { //if there is stuff in the list
        pNew->setPNext(pHead);
    }
    pHead = pNew; //set head to new node
}

//Function name: insertInOrder
//Purpose: Inserts new node in descending order based on score
//Parameters: newData to be added to new node
//Return value: none
//Date: 09/18/2025

template <typename T>
void List<T>::insertInOrder(T newData) {
    Node<T>* pNew = new Node<T>(newData); //initialize new node

    if (pHead == nullptr || pHead->getData() <= newData) { //if list is empty or it should be inserted at front
        pNew->setPNext(pHead);
        pHead = pNew;
        return;
    }

    Node<T>* pCur = pHead; //make tracking pointer
    while (pCur->getPNext() != nullptr && pCur->getPNext()->getData() > newData) { //while you arent at end of list and your data is greater than current node data
        pCur = pCur->getPNext(); //keep moving
    }

    pNew->setPNext(pCur->getPNext()); //once youre at the right spot, set the new pnext to the next node, then set current node to new node
    pCur->setPNext(pNew);
}

//Function name: removeNode
//Purpose: Removes node with specified command from list
//Parameters: string representing command to remove
//Return value: 1 if node removed, 0 if not found
//Date: 09/18/2025

template <typename T>
int List<T>::removeNode(std::string command)
{
    if (pHead == nullptr) return 0; //list is empty

    Node<T>* temp = pHead; //initialize tracking pointer
    if (pHead->getData().getPrompt() == command) { //if head is the right node
        pHead = pHead->getPNext(); //set head to next node and remove current node
        delete temp;
        return 1;
    }

    Node<T>* current = pHead;
    while (current->getPNext() != nullptr) { //while not at end of list
        if (current->getPNext()->getData().getPrompt() == command) { //if you found correct next node
            temp = current->getPNext(); //set temp to next node
            current->setPNext(temp->getPNext());//set current next to temp next
            delete temp; //remove node
            return 1;
        }
        current = current->getPNext();//keep moving along the list
    }
    return 0;
}

//Function name: storeList
//Purpose: Stores list data in file
//Parameters: string representing file name
//Return value: none
//Date: 09/18/2025

template <typename T>
void List<T>::storeList(std::string file)
{
    std::ofstream outfile(file); //storage file
    if (outfile.is_open()) { //if file opens
        Node<T>* current = pHead;
        while (current != nullptr) { //while not at end of list
            outfile << current->getData() << std::endl; //output node data to file
            current = current->getPNext(); //move to next node
        }
        outfile.close();
    }
}

//Function name: printList
//Purpose: Prints list
//Parameters: none
//Return value: none
//Date: 09/18/2025

template <typename T>
void List<T>::printList() {
    Node<T>* pCur = pHead;
    while (pCur != nullptr) { //while not at end of list
        std::cout << pCur->getData() << std::endl; //output node to terminal
        pCur = pCur->getPNext(); //move to next node
    }
}