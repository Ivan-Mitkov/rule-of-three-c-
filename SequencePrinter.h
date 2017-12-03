#pragma once
#include"SequenceGenerator.h"
#include<string>
#include<sstream>
#include<fstream>

class SequencePrinter {

public:
	virtual void setSequence(SequenceGenerator& sequence) = 0;
};

class SequencePrinterToConsole :public SequencePrinter {
	std::string res;
public:
	void setSequence(SequenceGenerator & o) {
		this->res = o.printoString();
		std::cout <<res << std::endl;
	}
};
class SequencePrinterToFile : public SequencePrinter {
	std::ofstream fileStream;
public:
	SequencePrinterToFile(std::string filename) :
		fileStream(filename) {
	}

	void setSequence( SequenceGenerator & o) {
		fileStream << o.printoString() << std::endl;
	}
};


