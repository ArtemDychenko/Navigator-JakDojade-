#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include "nullptr.h"

using namespace std;

template <typename T>
class vector {
private:
	T* arr;
	int capacity;
	int size;
public:
	vector() {
		arr = new T[1];
		capacity = 1;
		size = 0;
	}
	~vector() { delete[] arr; }

	T& operator[](int i) {
		if (i < this->size) {
			return arr[i];
		}
		return return_null<T>();
	}

	void push(const T& data) {
		if (size == capacity) {
			T* temp = new T[capacity * 2];
			for (int i = 0; i < capacity; i++) {
				temp[i] = arr[i];
			}

			delete[] arr;
			this->capacity *= 2;
			arr = temp;
		}

		arr[size] = data;
		this->size++;
	}

	T back() {
		return arr[size - 1];
	}

	void push(T data, int index) {
		if (index == capacity)
			push(data);
			else
			arr[index] = data;
		
	}

	T& get(int index) { 
		if (index < this->size) {
		return arr[index]; } 
		return return_null<T>();
	}

	void pop() {
		size--;
	}

	void popFront() {
		T* temp = new T[capacity];
		int k = 0;
		for (int i = 1; i < capacity; i++) {
			temp[k] = arr[i];
			k++;
		}
		delete[] arr;
		arr = temp;
		this->size--;
	}

	int getSize() { return size; };
	int getCapacity() { return capacity; };
	void print() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	


};


#endif

