#pragma once
#include<string>
#include<sstream>
#include"MyVector.h"
#include"SequenceGenerator.h"
#include"SequencePrinter.h"

class FibonacciGenerator:public SequenceGenerator {
	int secondFibo;
	int firstFib;

public:
	FibonacciGenerator(int firstFib, int secondFibo);
	MyVector<unsigned long long> fiboList(const int firstFib, const int secondFibo);
	int getVectorIndex(const int firstFib, const int secondFibo);
	std::string printoString( );
	int FibonacciGenerator::getFirst();
	int FibonacciGenerator::getSecond();

};
FibonacciGenerator::FibonacciGenerator(int firstFib, int secondFibo):firstFib(firstFib),
secondFibo(secondFibo)
{

}

int FibonacciGenerator::getFirst() {
	return this->firstFib;
}
int FibonacciGenerator::getSecond() {
	return this->secondFibo;
}
MyVector<unsigned long long> FibonacciGenerator::fiboList(const int firstFib, const int secondFibo)
{
	MyVector<unsigned long long> fibos;
	long long first = 1;
	long long second = 1;
	long long  third = first + second;
	fibos.push_back(1);
	fibos.push_back(1);
	fibos.push_back(2);
	int count = 2;
	while (count < secondFibo) {
		first = second;
		second = third;
		third = first + second;
		count++;
		fibos.push_back(third);
	}

	return fibos;
}

int FibonacciGenerator::getVectorIndex(const int firstFib, const int secondFibo)
{
	MyVector<unsigned long long> fibos = fiboList(firstFib, secondFibo);
	size_t vectorSize = fibos.size();
	for (size_t i = 0; i < vectorSize; i++) {
		if (i == firstFib - 1) {
			return i;
		}
	}


}

std::string FibonacciGenerator::printoString()
{
	int firstFib = getFirst();
	int secondFibo = getSecond();
	std::ostringstream stream;
	MyVector<unsigned long long> fibos = fiboList(firstFib, secondFibo);
	int firstIndex = getVectorIndex(firstFib, secondFibo);
	for (int i = firstIndex; i < fibos.size() - 1; i++) {
		stream << "Fibonacci " << fibos[i] << " ";
	}
	return stream.str();
}

