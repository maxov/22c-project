//
//  HashTable.h
//  Hashtables
//
//  Created by Ori Klein on 6/14/16.
//  Copyright (c) 2016 Ori Klein. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include "Food.h"
#include <string>
#include <iostream>

using namespace std;

template<class Type>
class LinkedListNode{
private:
	Type data;
public:
	LinkedListNode* next;
	int key;
	LinkedListNode(Type t, int k){
		data = t;
		next = nullptr;
		key = k;
	}

	void setData(Type d){ data = d; }

	int getKey() { return key; }

	Type getData(){ return data; }
};

/*
Template class that creates a singly linked list with the ability to add a node anywhere, remove from anywhere,
empty, extract data from node.
head is an LinkedListNode pointer that points to the first node in the list, without holding data
rear is an LinkedListNode pointer that points to the last node in the list, without holding data
index of first node is 0, index of last node is size -1.
*/
template<class Type>
class SinglyLinkedList{
private:
	int size;
	LinkedListNode<Type>* head;
	LinkedListNode<Type>* rear;
public:
	/**
	Creates an instance of a SinglyLinkedList
	*/
	SinglyLinkedList(){
		size = 0;
		head = nullptr;
		rear = nullptr;
	}
	/**
	adds a node to beginning of the list, head will point to that node
	*/
	void addFirst(Type data){
		LinkedListNode<Type>* newNode = new LinkedListNode<Type>(data);
		newNode->next = head;
		head = newNode;
		size++;
		if (size == 1)
			rear = newNode;
	}
	/**
	adds a node after the node specified at that index
	*/
	void addAfter(Type data, int index){
		LinkedListNode<Type>* newNode = new LinkedListNode<Type>(data);
		if (index > size){
			return;
		}
		if (index == size){
			addLast(newNode);
			return;
		}
		if (index == 0){
			addFirst(newNode);
			return;
		}
		int i = 0;
		LinkedListNode<Type>* pPre = nullptr;
		newNode->next = head;
		while (newNode->next != nullptr && i < index){
			pPre = newNode;
			newNode = newNode->next;
		}
		pPre->next = newNode;
		size++;
	}
	/**
	adds a node at the size index
	*/
	void addLast(Type data, int key){
		LinkedListNode<Type>* newNode = new LinkedListNode<Type>(data, key);
		if (size == 0){
			head = newNode;
			rear = newNode;
			newNode->next = nullptr;
			size++;
			return;
		}
		rear->next = newNode;
		newNode->next = nullptr;
		rear = newNode;
		size++;
	}
	/**
	deletes node from existance
	*/
	void removeFirst(){
		if (size < 1)
			return;
		LinkedListNode<Type>* pLoc = head;
		head = head->next;
		delete pLoc;
		size--;
		if (size == 1)
			rear = head;
	}
	/**
	deletes node from existance at indicated index
	*/
	bool remove(int key){
		if (size <= 0){
			return false;
		}
		LinkedListNode<Type>* pLoc = head;
		LinkedListNode<Type>* pPre = nullptr;
		while (pLoc->next != nullptr && pLoc->getKey() != key){
			pPre = pLoc;
			pLoc = pLoc->next;
		}
		if (pLoc->getKey() != key)
			return false;
		if (pLoc == head){
			head = pLoc->next;
			size--;
			return true;
		}
		pPre->next = pLoc->next;
		if (pPre->next == nullptr)
			rear = pPre;
		delete pLoc;
		size--;
		return true;
	}
	/**
	extracts data from node at specified index
	*/
	Type get(int key){
		LinkedListNode<Type>* pLoc = head;
		while (pLoc->next != nullptr && pLoc->getKey() != key){
			pLoc = pLoc->next;
		}
		return pLoc->getData();
	}
	int find(Type data){

	}
	void print(){
		if (size == 0)
		{
			cout << "\n{ }\n";
			return;
		}
		LinkedListNode<Type>* p = head;
		LinkedListNode<Type>* q = head;
		cout << "\n{ ";
		cout << head->getData();
		if (head->next)
			cout << ", ";
		else
			cout << " ";
		while (q)
		{
			p = q;
			if (p != head)
			{
				cout << p->getData();
				if (p->next)
					cout << ", ";
				else
					cout << " ";
			}
			q = p->next;
		}
		cout << "}\n";
	}
	/**
	returns size
	*/
	int getSize(){
		return size;
	}
	/**
	deletes all nodes
	*/
	void empty(){
		int s = size;
		for (int i = 0; i < s; i++){
			removeFirst();
		}
		head = nullptr;
		rear = nullptr;
	}

};


//*****************************************************************
// Hash Table objects store a fixed number of Linked Lists.
//*****************************************************************
template <class Type>
class HashTable
{
private:
    
    // Array is a reference to an array of Linked Lists.
    SinglyLinkedList<Type> * array;

    // Length is the size of the Hash Table array.
    int length;
    
    // Returns an array location for a given item key.
    int hash( int key );
    
public:
    
    HashTable();
    
    // Constructs the empty Hash Table object.
    // Array length is set to 991 by default.
    HashTable(int tableLength);
    
    // Adds an item to the Hash Table.
    void insertItem(int key, Type newItem );
    
    // Deletes an Item by key from the Hash Table.
    // Returns true if the operation is successful.
    bool removeItem( int key );
    
    // Returns an item from the Hash Table by key.
    // If the item isn't found, a null pointer is returned.
    Type getItemByKey( int key );
    
    // Display the contents of the Hash Table to console window.
    void printTable();
    
    // Prints a histogram illustrating the Item distribution.
    void printHistogram();
    
    // Returns the number of locations in the Hash Table.
    int getLength();
    
    // Returns the number of Items in the Hash Table.
    int getNumberOfItems();
    
    // De-allocates all memory used for the Hash Table.
    ~HashTable();
};

template class HashTable<int>;
template class HashTable<Food>;

#endif // !HashTable_h
