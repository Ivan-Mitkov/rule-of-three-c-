#pragma once
#include"MyVector.h"


class SequenceGenerator
{
	int first;
	int second;
public:
	int SequenceGenerator::getFirst() {
		return this->first;
	}
	int SequenceGenerator::getSecond() {
		return this->second;
	}
	virtual int getVectorIndex(const int firstnum, const int secondnum) = 0;
	virtual std::string printoString( )=0;
};


