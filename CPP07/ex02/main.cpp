#include <iostream>
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750

#define SIZE 5

int main()
{
	Array<int> arr(SIZE);

	for (int i = 0; i < SIZE; i++)
		arr[i] = i;

	for (int i = 0; i < SIZE; i++)
		std::cout << arr[i] << " ";

	std::cout << std::endl;

	Array<int> arrCpy(arr);
	arrCpy[0] = 42;

	try
	{
		arr[21] = 21;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "arr[0] = " << arr[0] << std::endl;
	std::cout << "arrCpy[0] = " << arrCpy[0] << std::endl;
	std::cout << "size : " << arr.size() << std::endl;
}
