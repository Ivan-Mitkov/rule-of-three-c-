#pragma once
#include<iostream>

template <typename ElemType>
class MyVector
{
	friend class FibonacciGenerator;
public:
	MyVector();
	~MyVector();
	MyVector(const MyVector& other);

	MyVector<ElemType>& operator=(const MyVector & other);
	int size();
	void push_back(ElemType s);
	ElemType getAt(int index);
	void setAt(int index, ElemType s);
	void insertAt(int index, ElemType e);
	ElemType& operator[](int index);
	void copyData(ElemType * source, int sourceLength, ElemType * dest, int destLength);

private:
	ElemType *arr;
	int numUsed, numAllocated;
	void doubleCapacity();
};

template <typename ElemType>
MyVector<ElemType>::MyVector()
{
	//std::cout << "Constructor\n";
	arr = new ElemType[4];
	numAllocated = 4;
	numUsed = 0;
}

template <typename ElemType>
MyVector<ElemType>::~MyVector()
{
	//std::cout << "Destructor\n";
	delete[] arr;
}

template <typename ElemType>
MyVector<ElemType>::MyVector(const MyVector& other)
{
	this->numAllocated = other.numAllocated;
	this->arr = new ElemType[numAllocated];
	this->numUsed = other.numUsed;
	copyData(other.arr, other.numUsed, this->arr, this->numUsed);
	//std::cout << "Copy constructor" << std::endl;
}

template<typename ElemType>
MyVector<ElemType>& MyVector<ElemType>::operator=(const MyVector & other) {
	if (this != &other) {
		delete[] this->arr;
		this->numAllocated = other.numAllocated;
		this->numUsed = other.numUsed;
		this->arr = new ElemType[numAllocated];
		copyData(other.arr, other.numUsed, this->arr, this->numUsed);

	}
	//std::cout << "Copy assignement" << std::endl;
	return *this;
}


template <typename ElemType>
int MyVector<ElemType>::size()
{
	return numUsed;
}

template <typename ElemType>
ElemType MyVector<ElemType>::getAt(int index)
{
	if (index < 0 || index >= size())
		throw "Out of bounds";
	return arr[index];
}

template <typename ElemType>
void MyVector<ElemType>::setAt(int index, ElemType e)
{
	if (index < 0 || index >= size())
		throw "Out of bounds";
	arr[index] = e;
}

template <typename ElemType>
void MyVector<ElemType>::insertAt(int index, ElemType e)
{
	if (index < 0 || index >= size())
		throw "Out of bounds";
	if (numUsed == numAllocated)
		doubleCapacity();
	for (int i = size() - 1; i >= index; i--)
		arr[i + 1] = arr[i];
	arr[index] = e;
	numUsed++;
}

template<typename ElemType>
ElemType& MyVector<ElemType>::operator[](int index)
{
	if (index < 0 || index >= size())
		throw "Out of bounds";
	return this->arr[index];;
}

template<typename ElemType>
void MyVector<ElemType>::copyData(ElemType * source, int sourceLength, ElemType * dest, int destLength)
{
	for (int i = 0; i < sourceLength && i < destLength; i++) {
		dest[i] = source[i];
	}
}


template <typename ElemType>
void MyVector<ElemType>::push_back(ElemType s)
{
	if (numUsed == numAllocated)
		doubleCapacity();
	arr[numUsed++] = s;
}

template <typename ElemType>
void MyVector<ElemType>::doubleCapacity()
{
	ElemType *bigger = new ElemType[numAllocated * 2];

	for (int i = 0; i < numUsed; i++)
		bigger[i] = arr[i];
	delete[] arr;
	arr = bigger;
	numAllocated *= 2;
}
