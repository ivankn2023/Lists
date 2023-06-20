
#include <iostream>


class Listok {
    struct list {
        list* pNext;
        int value;
        list(int value) {
            this->pNext = NULL;
            this->value = value;
        }
    };
    list* head = NULL;
    list* tail = NULL;
public:
    void push_back(int value) {
        list* ptr = new list(value);
        if (tail != NULL) tail->pNext = ptr;
        if (head == NULL)  head = ptr;
        tail = ptr;
    }
    void push_front(int value) {
        list* ptr = new list(value);
        if (head != NULL) {
            ptr->pNext = head;
        }
        if (tail == NULL) {
            tail = ptr;
        }
        head = ptr;
    }
    void write() {
        list* cur;
        cur = head;
        if (head == NULL) return;
        else {
            while (cur != NULL) {
                std::cout << cur->value << " ";
                cur = cur->pNext;
            }
        }
    }
};

class List {

    class Node {
    public:
        int value;
        Node* pNext, * pPrev;
        Node(int val) {
            this->value = val;
            this->pPrev = this->pNext = NULL;
        }
    };

    Node* head;
    Node* tail;
public:
    List() {
        this->head = this->tail = NULL;
    }


    void push_back(int value) {
        Node* ptr = new Node(value);
        ptr->pPrev = tail;
        if (tail != NULL) tail->pNext = ptr;
        if (head == NULL)  head = ptr;
        tail = ptr;
    }
    void push_front(int value) {
        Node* ptr = new Node(value);
        ptr->pNext = head;
        if (head != NULL) head->pPrev = ptr;
        if (tail == NULL) tail = ptr;
        head = ptr;
    }

    void pop_front() {
        if (head == NULL) return;
        Node* ptr = head->pNext;
        if (ptr != NULL) ptr->pPrev = NULL;
        else tail = NULL;
        delete head;
        head = ptr;
    }
    void pop_back() {
        if (tail == NULL) return;
        Node* ptr = tail->pPrev;
        if (ptr != NULL) ptr->pNext = NULL;
        else head = NULL;
        delete tail;
        tail = ptr;
    }

    void write() {
        if (tail == NULL) return;
        Node* ptr = head;
        while (ptr != NULL) {
            std::cout << ptr->value << " ";
            ptr = ptr->pNext;
        }
    }
    void write_at(int n) {
        if (tail == NULL) return;
        Node* ptr = head;
        int k = 0;
        while ((ptr != NULL) && (k != n)) {
            ptr = ptr->pNext;
            k++;
        }
        if (ptr != NULL) std::cout << ptr->value<< " ";
    }
};


int main()
{
    std::cout << "SINGLE" << std::endl;

    Listok listik;
    listik.push_back(5);
    listik.push_back(6);
    listik.push_front(3);
    listik.push_back(5);
    listik.push_back(6);
    listik.write();


    std::cout << std::endl << "DUAL" << std::endl;

    List list;
    list.push_back(5);
    list.push_back(6);
    list.push_front(3);
    list.push_back(5);
    list.push_back(6);
    list.pop_back();
    list.pop_front();
    list.write();
    std::cout << std::endl << "DUAL in position 1" << std::endl;
    list.write_at(1);
}

