#pragma once
#include<string>
#include<sstream>
#include"MyVector.h"
#include"SequenceGenerator.h"
#include"SequencePrinter.h"

class SqrtGenerator: public SequenceGenerator
{
	int firstQuadr;
	int secondQuadr;
public:
	SqrtGenerator::SqrtGenerator(int firstQuadr, int secondQuadr);
	MyVector<double> sqrtList(const int firstQuadr, const int secondQuadr);
	int getVectorIndex(const int firstQuadr, const int secondQuadr);
	std::string printoString( );
	int getFirst();
	int getSecond();
	
};
SqrtGenerator::SqrtGenerator(int firstQuadr, int secondQuadr) :firstQuadr(firstQuadr),
secondQuadr(secondQuadr)
{

}

int SqrtGenerator::getFirst(){
	return this->firstQuadr;
}
int SqrtGenerator::getSecond() {
	return this->secondQuadr;
}


MyVector<double> SqrtGenerator::sqrtList(const int firstQuadr, const int secondQuadr)
{
	MyVector<double> sqr;
	double first = 1;

	int count = 1;
	while (count <= secondQuadr) {
		sqr.push_back(sqrt(count));
		count++;
	}

	return sqr;
}

int SqrtGenerator::getVectorIndex(const int firstQuadr, const int secondQuadr)
{
	MyVector<double> sqr = sqrtList(firstQuadr, secondQuadr);
	int vectorSize = sqr.size();
	for (int i = 0; i < vectorSize; i++) {
		if (i == firstQuadr) {
			return i;
		}
	}

}

std::string SqrtGenerator::printoString()
{
	std::ostringstream stream;
	int firstQuadr = getFirst();
	int secondQuadr = getSecond();
	MyVector<double> sqr = sqrtList(firstQuadr, secondQuadr);
	int firstIndex = getVectorIndex(firstQuadr, secondQuadr);
	for (int i = firstIndex; i < sqr.size() - 1; i++) {
		stream << "Sqrt(" << sqr[i] << ") ";
	}
	return stream.str();
}

 
