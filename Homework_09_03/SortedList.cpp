#include <iostream>
using namespace std;

struct Node
{
    int item;
    Node * next;
    Node * prev;
};

struct SortedList
{
    Node * pHead;
    Node * pAss;
    

    void add(int item)
    {
        Node * fr = pHead;
        int i = 0;
        if (!pHead)
        {
            Node * node = new Node;
            node->item = item;
            node->next = 0;
            node->prev = 0;
            pHead = node;
            pAss = node;
        }
        else if (item < fr->item)
        {
            Node * node = new Node;
            node->item = item;
            fr->prev = node;
            node->next = fr;
            pHead = node;
        }
        else
        {
            while (fr)
            {
                if (item == fr->item){ break; }
                else
                {
                    if (item < fr->item)
                    {
                        Node * node = new Node;
                        node->item = item;
                        node->next = fr;
                        node->prev = fr->prev;
                        fr->prev->next = node;
                        fr->prev = node;
                        break;
                    }
                    if (fr->next){ fr = fr->next; }
                    else
                    {
                        Node * node = new Node;
                        node->item = item;
                        fr->next = node;
                        node->prev = fr;
                        pAss = node;
                        break;
                    }
                }
            }
        }
    }

    void PrintAll()
    {
        Node * fr = pHead;
        while(fr)
        {
            cout << fr->item << " ";
            if (fr->next){ fr = fr->next; }
            else{ break; }
        }
        cout << endl;
    }

    int get(int id)
    {
        int elem;
        int el = 0;
        Node * fr = pHead;
        while (fr)
        {
            el += 1; 
            if (el == id)
            {
                elem = fr->item;
                break;
            }
            if (fr->next){ fr = fr->next; }
            else{ break; }
        }
        return elem;
    }
    
    void remove(int id)
    {
        Node * fr = pHead;
        int x = 0;
        while (fr)
        {
            x += 1; 
            if (x == id)
            {
                if (fr->prev)
                {
                    if (fr->next)
                    {
                        fr->prev->next = fr->next;
                        fr->next->prev = fr->prev;
                        delete fr;
                    }
                    else{ delete fr; }
                }
                else
                {
                    pHead = fr->next;
                    delete fr;
                }
                break;
            }
            if (fr->next){ fr = fr->next; }
        }
    }

    bool If_in(int item)
    {
        bool flag = false;
        Node * fr = pHead;
        while (fr)
        { 
            if (fr->item == item)
            {
                flag = true;
                break;
            }
            if (fr->next){ fr = fr->next; }
            else{ break; }
        }
        return flag;
    }
    
    int size()
    {
        Node * fr = pHead;
        int size = 0;
        while (fr)
        {
            size += 1; 
            if (fr->next){ fr = fr->next; }
            else{ break; }
        }
        return size;
    }
};

SortedList * intersect(SortedList * a, SortedList * b)
{
    SortedList * c  = new SortedList;
    int a_s = a->size();
    int per;
    for (int i = 1; i <= a_s; i++)
    {
        per = a->get(i);
        if (!c->If_in(per))
        {
            if (b->If_in(per)){ c->add(per); }
        }
    }
    return c;
};

SortedList * Union(SortedList * a, SortedList * b)
{
    SortedList * c  = new SortedList;
    int a_s = a->size();
    int b_s = b->size();
    int per;
    for (int i = 1; i <= a_s; i++)
    {
        per = a->get(i);
        if (!c->If_in(per)){ c->add(per); }
    }
    for (int i = 1; i <= b_s; i++)
    {
        per = b->get(i);
        if (!c->If_in(per)){ c->add(per); }
    }
    return c;
};

SortedList * difference(SortedList * a, SortedList * b)
{
    SortedList * c  = new SortedList;
    int a_s = a->size();
    int b_s = b->size();
    int per;
    for (int i = 1; i <= a_s; i++)
    {
        per = a->get(i);
        if (!c->If_in(per))
        {
            if (!b->If_in(per)){ c->add(per); }
        }
    }
    return c;
};
