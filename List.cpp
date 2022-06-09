//
// Created by c0sta on 09.06.2022.
//

#include <iostream>
#include "List.h"
using namespace std;
List::~List()
{
    while (HEAD != nullptr) // Пока по адресу хоть что-то есть
    {
        Reader *temp = HEAD -> next; // Запишем указатель на адрес следующего элемента структуры
        delete HEAD; // Освобождаем память по месту начала списка
        HEAD = temp; // Меняем адрес начала списка
    }
}

bool List::is_empty() {
    return HEAD == nullptr;
}

void List::add(Reader mass)
{
    Reader *p = new Reader(mass); // Выделяем память под новую структуру
    size++;
    if (is_empty()) {
        HEAD = p;
        TAIL = p;
        return;
    }
    TAIL->next = p;
    p->next = nullptr;
    TAIL = p;

}

struct Reader* swap(struct Reader* ptr1, struct Reader* ptr2)
{
    struct Reader* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

/* Function to sort the list */
int List::sort()
{
    struct Reader** head = &HEAD;
    int count = size;
    struct Reader** h;
    int i, j, swapped;

    for (i = 0; i <= count; i++)
    {

        h = head;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++)
        {

            struct Reader* p1 = *h;
            struct Reader* p2 = p1->next;

            if (p1->get_number() > p2->get_number())
            {

                /* update the link after swapping */
                *h = swap(p1, p2);
                swapped = 1;
            }

            h = &(*h)->next;
        }
        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
}


/* Function to sort the list */
int List::sort_by_two()
{
    struct Reader** head = &HEAD;
    int count = size;
    struct Reader** h;
    int i, j, swapped;

    for (i = 0; i <= count; i++)
    {

        h = head;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++)
        {

            struct Reader* p1 = *h;
            struct Reader* p2 = p1->next;

            if (p1->get_number() > p2->get_number())
            {

                /* update the link after swapping */
                *h = swap(p1, p2);
                swapped = 1;
            }
            else if (p1->get_number() == p2->get_number() && p1->get_number() > p2->get_number())
            {
                *h = swap(p1, p2);
                swapped = 1;
            }

            h = &(*h)->next;
        }
        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
}

void List::add_sorted(Reader mass)
{
    Reader *p = new Reader(mass); // Выделяем память под новую структуру
    if (is_empty()) {
        HEAD = p;
        TAIL = p;
        return;
    }
    if ( (HEAD->next == nullptr) && (HEAD->get_fio() >= mass.get_fio()) ){
        p->next = HEAD;
        HEAD = p;
        return;
    }
    Reader *temp=HEAD->next, *temp_prev=HEAD;
    while(temp){
        if (temp->get_fio() >= mass.get_fio()){
            temp_prev->next = p;
            p->next = temp;
            return;
        }
        temp_prev = temp;
        temp = temp->next;
    }
    temp_prev->next = p;
    p->next = nullptr;
    TAIL = p;
}

void List::print()
{
    if (is_empty()) return;
    Reader *temp = HEAD; // объявляем указатель и пусть он указывает на начало списка
    while (temp){ // пока есть на что указывать
        cout << *temp;
        temp = temp->next;
    }
}

void List::print_names()
{
    if (is_empty()) return;
    Reader *temp = HEAD; // объявляем указатель и пусть он указывает на начало списка
    while (temp){ // пока есть на что указывать
        cout << temp->get_fio() << " ";
        temp = temp->next;
    }
    cout << endl;
}

Reader* List::find(string _val) {
    Reader* p = HEAD;
    while (p && p->get_fio() != _val) p = p->next;
    return (p && p->get_fio() == _val) ? p : nullptr;
}

void List::remove_first() {
    if (is_empty()) return;
    Reader* p = HEAD;
    HEAD = p->next;
    delete p;
}


void List::remove_last() {
    if (is_empty()) return;
    if (HEAD == TAIL) {
        remove_first();
        return;
    }
    Reader* p = HEAD;
    while (p->next != TAIL) p = p->next;
    p->next = nullptr;
    delete TAIL;
    TAIL = p;
}

void List::remove(string _val) {
    size--;
    if (is_empty()) return;
    if (HEAD->get_fio() == _val) {
        remove_first();
        return;
    }
    else if (TAIL->get_fio() == _val) {
        remove_last();
        return;
    }
    Reader* slow = HEAD;
    Reader* fast = HEAD->next;
    while (fast && fast->get_fio() != _val) {
        fast = fast->next;
        slow = slow->next;
    }
    if (!fast) {
        cout << "This element does not exist" << endl;
        return;
    }
    slow->next = fast->next;
    delete fast;
}

