#ifndef SEQ_H
#define SEQ_H

#include <Item.h>

class Sequence {
public:
    // Constructor to initialize the sequence with a given capacity
    Seq(int capacity);

    // Destructor to release memory used by the sequence
    ~Seq();

    // Insert an item at the specified index
    void insert(int index, Item item);

    // Remove an item from the sequence at the specified index
    void remove(int index);

    // Get the item at the specified index
    Item get(int index) const;

    // Get the number of items in the sequence
    int size() const;

    // Sort the sequence using selection sort
    void sort();

    // Overloaded comparison operators for sorting
private:
    // Private helper functions for sorting
    int findMax(int start, int end) const;
    void swap(int i, int j);

    // Private data members
    Item* items;    // Array to hold the items (if using an array representation)
    int capacity;   // Maximum number of items that can be stored in the sequence
    int count;      // Number of items currently in the sequence (if using an array representation)
    
    // Linked-list specific data members
    struct Node {
        Item item;
        Node* prev;
        Node* next;
    };
    Node* first;    // Pointer to the first node in the linked-list (if using a linked-list representation)
};

#endif

