#include <iostream>
#include "Deque.h"


int main()
{
	Deque<int> int_d1;

	int_d1.push_back(1);
	int_d1.push_back(2);
	int_d1.push_front(3);
	int_d1.push_back(4);
	int_d1.push_front(5);
	int_d1.printNormal(std::cout);
	int_d1.printReverse(std::cout);
	std::cout << int_d1.size() << '\n';
	std::cout << '\n';

	Deque<int> int_d2(int_d1);
	int_d2.printNormal(std::cout);

	std::cout << '\n';
	int_d1.pop_back();
	int_d2.pop_front();
	int_d1.printNormal(std::cout);
	int_d2.printNormal(std::cout);

	std::cout << '\n';
	int_d2.push_back(6);
	int_d1 = int_d2;
	int_d1.printNormal(std::cout);
	int_d2.printNormal(std::cout);

	std::cout << '\n';
	int_d1.pop_back();
	int_d2.pop_front();
	int_d1.printNormal(std::cout);
	int_d2.printNormal(std::cout);

	std::cout << "\n\n\n";

	Deque<double> double_d1;

	double_d1.push_back(1.1);
	double_d1.push_back(2.2);
	double_d1.push_front(3.3);
	double_d1.push_back(4.4);
	double_d1.push_front(5.5);
	double_d1.printNormal(std::cout);
	double_d1.printReverse(std::cout);
	std::cout << double_d1.size() << '\n';
	std::cout << '\n';

	Deque<double> double_d2(double_d1);
	double_d2.printNormal(std::cout);

	std::cout << '\n';
	double_d1.pop_back();
	double_d2.pop_front();
	double_d1.printNormal(std::cout);
	double_d2.printNormal(std::cout);

	std::cout << '\n';
	double_d2.push_back(6.6);
	double_d1 = double_d2;
	double_d1.printNormal(std::cout);
	double_d2.printNormal(std::cout);

	std::cout << '\n';
	double_d1.pop_back();
	double_d2.pop_front();
	double_d1.printNormal(std::cout);
	double_d2.printNormal(std::cout);

	std::cout << "\n\n\n";

	Deque<const char*> char_d1;

	char_d1.push_back("a");
	char_d1.push_back("b");
	char_d1.push_front("c");
	char_d1.push_back("d");
	char_d1.push_front("e");
	char_d1.printNormal(std::cout);
	char_d1.printReverse(std::cout);
	std::cout << char_d1.size() << '\n';
	std::cout << '\n';

	Deque<const char*> char_d2(char_d1);
	char_d2.printNormal(std::cout);

	std::cout << '\n';
	char_d1.pop_back();
	char_d2.pop_front();
	char_d1.printNormal(std::cout);
	char_d2.printNormal(std::cout);

	std::cout << '\n';
	char_d2.push_back("f");
	char_d1 = char_d2;
	char_d1.printNormal(std::cout);
	char_d2.printNormal(std::cout);

	std::cout << '\n';
	char_d1.pop_back();
	char_d2.pop_front();
	char_d1.printNormal(std::cout);
	char_d2.printNormal(std::cout);


}
