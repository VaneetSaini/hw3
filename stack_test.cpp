#include "stack.h"
#include <iostream> 
//basic tests 
int main(){
	Stack<int> test;
	
	std::cout << std::boolalpha << test.empty() << std::endl;
	for (unsigned int i = 0; i < 5; ++i)
	{
		test.push(i);
	}
	if (!test.empty()){
		std::cout << "stack isnt empty" << std::endl;
	}
	test.pop();
	test.push(20);
	test.push(100);
	std::cout << "size: " << test.size() << std::endl;
	std::cout << "top: " << test.top() << std::endl;


	return 0;
}