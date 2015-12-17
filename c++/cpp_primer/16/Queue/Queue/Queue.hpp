//
//  Queue.hpp
//  Queue
//
//  Created by nichola on 15/12/6.
//  Copyright © 2015年 nichola. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp
#include <iostream>
template <class Type> class Queue;
template <class Type>
class QueueItem {
    friend class Queue<Type>;
    QueueItem(const Type &t):item(t),next(0) {
    }
    Type item;
    QueueItem *next;
};

template <class Type> std::ostream& operator<<(std::ostream &os,const Queue<Type> &q);
template <class Type> std::istream& operator>>(std::istream &is, Queue<Type> &q);

template <class Type>
class Queue {
    friend std::ostream& operator<< <Type> (std::ostream &,const Queue<Type> &);//也可以operator<<<Type>(，但是可读性很差
    friend std::istream& operator>> <Type> (std::istream &is,Queue<Type> &q);
public:
    Queue():head(0),tail(0) {}
    template <class It>
    Queue(It beg,It end):head(0),tail(0) {
        copy_element(beg,end);
    }
    Queue(const Queue &q):head(0),tail(0) {
        copy_element(q);
    }
    Queue& operator=(const Queue &);
    ~Queue() {
        destroy();
    }
    template <class Iter> void assign(Iter, Iter);
    Type& front() { return head->item; }
    const Type& front() const { return head->item; }
    void push(const Type &);
    void pop();
    bool empty() const {
        return head == 0;
    }
private:
    QueueItem<Type> *head;
    QueueItem<Type> *tail;
    void destroy();
    void copy_element(const Queue&);
    template <class Iter> void copy_element(Iter,Iter);
};

template <class Type> std::ostream& operator<<(std::ostream &os,const Queue<Type> &q) {
    os << "< ";
    QueueItem<Type> *p;
    for (p = q.head; p; p = p->next)
        os << p->item << " ";
    os <<">";
    return os;
}
template <class Type> std::istream& operator>>(std::istream &is, Queue<Type> &q) {
    Type tmp;
    while (is >> tmp) {
        q.push(tmp);
    }
    return is;
}


//#include "Queue.cpp"

template <class Type> Queue<Type>& Queue<Type>::operator=(const Queue &orig) {
    destroy();
    copy_element(orig);
    
    return *this;
}


template <class Type> void Queue<Type>::destroy() {
    while (!empty()) {
        pop();
    }
}

template <class Type>
void Queue<Type>::pop() {
    QueueItem<Type>* p = head;
    if (p != 0) {
        head = head->next;
        delete p;
    }
}
template <class Type> template <class Iter> void Queue<Type>::assign(Iter beg, Iter end) {
    destroy();
    copy_element(beg, end);
}

template <class Type>
void Queue<Type>::push(const Type &val) {
    QueueItem<Type> *p = new QueueItem<Type>(val);
    
    if (empty()) {// empty list
        head = p;
        tail = p;
    }
    else {//next tail
        tail->next = p;
        tail = p;
    }
    
}

template <class Type>
void Queue<Type>::copy_element(const Queue &orig) {
    for (QueueItem<Type> *p = orig.head; p; p = p->next) {
        push(p->item);
    }
}
template <class Type> template <class Iter> void Queue<Type>::copy_element(Iter beg,Iter end) {
    while (beg != end) {
        push(*beg);
        ++beg;
    }
}

/*
template <>
class Queue<const char*> {
public:
    void push(const char *);
    void pop() { real_queue.pop(); };
    bool empty() const { return real_queue.empty(); };
    std::string &front() { return real_queue.front(); };
    const std::string &front() const { return real_queue.front(); };
private:
    Queue<std::string> real_queue;
};
void Queue<const char*>::push(const char *s) {
    return real_queue.push(s);
}
*/

template <>
void Queue<const char*>::push(const char * const &s) {
    char* new_item = new char[strlen(s) + 1];
    strncpy(new_item, s, strlen(s) + 1);
    QueueItem<const char*> *pt = new QueueItem<const char*>(new_item);
    if (empty())
        head = tail = pt;
    else {
        tail->next = pt;
        tail = pt;
    }
}

template <>
void Queue<const char*>::pop() {
    QueueItem<const char*> *p = head;
    delete head->item;
    head = head->next;
    delete p;
}
#endif /* Queue_hpp */
