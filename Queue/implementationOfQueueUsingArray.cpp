//
// Created by Pranay Kamble on 03/08/24.
//
#include <iostream>

/*
//Simple Implementation of Queue
struct Queue{
   int *arr,rear = -1, capacity;

   Queue(int data) {
      this->capacity = data;
      arr = new int[data];
   }

   void enqueue(int data) {
      if (rear == capacity-1)
         return;
      arr[++rear] = data;
   }

   int dequeue() {  //Time Complexity = O(n)
      if (rear == -1)
         return INT_MIN;
      int ret = arr[0];
      for (int i{}; i<rear; ++i)
         arr[i] = arr[i+1];
      rear--;
      return ret;
   }

   bool isEmpty() {
      return rear == -1;
   }

   int getFront() {
      if (isEmpty()) {
         return INT_MIN;
      }
      return arr[0];
   }

   int getRear() {
      if (isEmpty())
         return INT_MIN;
      return arr[rear];
   }

   bool isFull() {
      return rear == capacity-1;
   }
};
*/
//Efficient Implementation - Using circular array
//circular array can be implemented by incrementing index by (index+1)%capacity
struct Queue {
   int *arr,front = -1, rear = -1, capacity, currSize = 0;

   Queue(int size) {
      this->capacity = size;
      arr = new int[capacity];
   }

   void enqueue(int data) {
      if (front == -1) ++front;
      if (currSize == capacity) {
         std::cout << "Overflow" << std::endl;
         return;
      }
      rear = (rear+1)%capacity;
      arr[rear] = data;
      ++currSize;
   }

    void dequeue() {
      if (isEmpty()) //underflow, empty queue
         return ;
      front = (front+1)%capacity;
      --currSize;
   }

   int size() {
      return currSize;
   }
   int isEmpty() {
      return currSize == 0;
   }

};