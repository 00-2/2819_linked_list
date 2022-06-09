//
// Created by c0sta on 09.06.2022.
//

#ifndef INC_2819_LINKED_LIST_LIST_H
#define INC_2819_LINKED_LIST_LIST_H

#include <string>

class Reader {
    private:
        std::string fio;
        unsigned int number;
        std::string title;
        std::string date_of_return;
    public:
        Reader * next;
        Reader(std::string fio_, unsigned int number_, std::string title_, std::string date_):
            fio(fio_), number(number_), title(title_), date_of_return(date_){};
        Reader(){};
        friend std::ostream& operator<<(std::ostream&os, Reader& reader)
        {
            os << reader.fio << std::endl << reader.number << std::endl << reader.title << std::endl << reader.date_of_return << std::endl;
            return os;
        }
        friend std::istream& operator>>(std::istream&is, Reader& reader)
        {
            is >> reader.fio >> reader.number >> reader.title >> reader.date_of_return;
            return is;
        }
        std::string get_fio(){
            return fio;
        }
        int get_number(){
            return number;
        }
};

class List
    // Односвязный список (он же List)
{
private:
    Reader *HEAD, *TAIL; // указатель на начало списка
    int size; // размер массива
public:
    List():HEAD(nullptr){
        this->HEAD = nullptr;
        this->TAIL = nullptr;
        this->size = 0;
    };
    ~List();
    bool is_empty();
    void add(Reader reader); // функция добавления элемента
    void add_sorted(Reader reader); // функция добавления элемента
    int sort();
    int sort_by_two();
    void print(); // функция распечатки списка
    void print_names();
    Reader* find(std::string fio);
    void remove_first();
    void remove_last();
    void remove(std::string _val);
    friend std::ostream& operator<<(std::ostream&os, List& list)
    {
        Reader *temp = list.HEAD;
        while (temp != nullptr) // Пока по адресу хоть что-то есть
        {
            os << *temp;
            temp = temp->next; // Запишем указатель на адрес следующего элемента структуры
        }
        return os;
    }
    friend std::istream& operator>>(std::istream&is, List& list)
    {
        while (is){
            Reader r;
            is>>r;
            list.add(r);
        }
        return is;
    }
};


#endif //INC_2819_LINKED_LIST_LIST_H
