//
// Created by Pranay Kamble on 06/08/24.
//
#include <iostream>

struct Dequeue {
	int *arr, currSize = 0, capacity, front = -1 ,rear = -1;

	Dequeue (int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
	}

	void insertFront(int data) {
		if (currSize == capacity) return ;
		if (front == -1) {
			front = rear = 0;
		}else {
			front = (front-1+capacity)%capacity;
		}
		arr[front] = data;
		++currSize;
	}

	void insertRear(int data) {
		if (currSize == capacity) return ;
		if (front == -1) {
			front = rear = 0;
		}else {
			rear = (rear + 1) % capacity;
		}
		arr[rear] = data;
		++currSize;
	}

	int deleteFront() {
		if (currSize == 0) return INT_MIN;
		int data = arr[front];

		front = (front+1)%capacity;
		--currSize;
		return data;
	}

	int deleteRear() {
		if (currSize == 0) return INT_MIN;
		int data = arr[rear];

		rear = (rear-1+capacity)%capacity;
		--currSize;
		return data;
	}

	int size() {
		return currSize;
	}

	bool empty() {
		return currSize == 0;
	}

	int getFront() {
		if (currSize == 0) return INT_MIN;
		return arr[front];
	}

	int getRear() {
		if (currSize == 0) return INT_MIN;
		return arr[rear];
	}

	void display() {
		for (int i{}; i<capacity; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
};

int main() {
	Dequeue deq(5);
	deq.insertFront(10);
	deq.insertRear(20);
	deq.insertRear(30);
	deq.deleteFront();
	deq.deleteRear();
	deq.display();
	std::cout << deq.front << " " << deq.rear << std::endl;
	return 0;
}