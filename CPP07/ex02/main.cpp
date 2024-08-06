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
/*
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}*/
