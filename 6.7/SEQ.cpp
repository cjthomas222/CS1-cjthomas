#include "SEQ.h"
#include <iostream>

using namespace std;
 
 
 SEQ::Seq(int capacity)
 {
    this->capacity = capacity;
    this->count = 0;
    this->items = new Item[capacity];
 }

SEQ::~Seq()
{
    delete[] items;
}

void SEQ::arrayInsert(int index, Item item)
{
    if (index < 0 || index > count)
    {
        cout << "Index out of bounds" << endl;
        return;
    }
    if (count == capacity)
    {
        cout << "Sequence is full" << endl;
        return;
    }
    for (int i = count; i > index; i--)
    {
        items[i] = items[i - 1];
    }
    items[index] = item;
    count++;   
}

void SEQ::listInsert(int index, Item item)
{
    if (index < 0 || index > count)
    {
        cout << "Index out of bounds" << endl;
        return;
    }
    if (count == capacity)
    {
        cout << "Sequence is full" << endl;
        return;
    }
    Node* newNode = new Node;
    newNode->item = item;
    if (index == 0)
    {
        newNode->prev = NULL;
        newNode->next = first;
        first = newNode;
    }
    else
    {
        Node* prevNode = first;
        for (int i = 1; i < index; i++)
        {
            prevNode = prevNode->next;
        }
        newNode->prev = prevNode;
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
    count++;
}

void SEQ::arraySort()
{
int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
          if (arr[j] < arr[min_idx])
              min_idx = j;
        }
        if (min_idx!=i)
            swap(&arr[min_idx], &arr[i]);
    }
}

void SEQ::listSort(node* head)
{
node* temp = head;

while (temp) {
    node* min = temp;
    node* r = temp->next;
  
    while (r) {
        if (min->data > r->data)
            min = r;
  
            r = r->next;
        }

        int x = temp->data;
        temp->data = min->data;
        min->data = x;
        temp = temp->next;
    }
}

bool operator<(const Sequence& other) const
{

}

bool operator<=(const Sequence& other) const
{

}

bool operator>(const Sequence& other) const
{

}

bool operator>=(const Sequence& other) const
{

}

int findMax(int start, int end) const
{

}

void swap(int i, int j)
{

}
