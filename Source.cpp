#include<iostream>
#include"MyVector.h"
#include"FibonacciGenerator.h"
#include"SqrtGenerator.h"
#include"SequenceGenerator.h"
#include"SequencePrinter.h"
using namespace std;

int main() {
	SequenceGenerator* fib = new FibonacciGenerator(90,100);
	SequenceGenerator* sq = new SqrtGenerator(1,10);
	fib->printoString();
	sq->printoString();
	std::string t = fib->printoString();
	std::string h = sq->printoString();
	/*std::cout << t;
	std::cout << h;
*/
	SequencePrinter* a = new SequencePrinterToConsole;
	a->setSequence(*fib);
	SequencePrinter*b = new SequencePrinterToConsole;
	b->setSequence(*sq);

	system("pause");
}