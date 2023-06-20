
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
    void pop_back(int value) {
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

int main()
{
    Listok listik;
    listik.push_back(5);
    listik.push_back(6);
    listik.pop_back(3);
    listik.push_back(5);
    listik.push_back(6);
    listik.write();

}

