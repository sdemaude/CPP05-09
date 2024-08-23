/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:42:41 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/23 17:48:06 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#define BASE 10

int	*toIntArray(int size, char **argv)
{
	int		*array = new int[size];
	char	*endPtr;

	for (int i = 0; i < size; i++)
	{
		array[i] = strtol(argv[i], &endPtr, BASE);
		if (endPtr == argv[i])
			throw (std::invalid_argument("Error: Incorrect value passed as input!"));
		if (array[i] < 0)
			throw (std::invalid_argument("Error: Negative value passed as input!"));
	}
	return (array);
}

double	getTimeToSort(std::string const &container, int *array)
{
	struct timespec begin, end;
	clock_gettime(CLOCK_REALTIME, &begin);

	if (container == "list")
	{
		(void)array;
		//to container
		//call sorting function

	}
	else if (container == "vector")
	{
		//to container
		//call sorting function

	}

	clock_gettime(CLOCK_REALTIME, &end);
	long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;

    return (static_cast<double>(seconds + nanoseconds*1e-9));
}

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cerr << "Error: Incorrect use of program, you should pass at least two numbers as arguments!" << std::endl;
		return (1);
	}

	int *array = NULL;
	try
	{
		array = toIntArray(argc--, argv++);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		delete [] array;
		return (1);
	}

	//double	elapsedTimeList = getTimeToSort("list");
	//double	elapsedTimeVect = getTimeToSort("vector");

	//display all infos
	//before and after ?
	//
	//std::cout << "Before: " << [3 5 9 7 4] << std::endl;
	//std::cout << "After: " << [3 4 5 7 9] << std::endl;
	//std::cout << "Time to process a range of " << argc << " elements with std::list : " << elapsedTimeList << " us" << std::endl;
	//std::cout << "Time to process a range of " << argc << " elements with std::vector : " << elapsedTimeVect << " us" << std::endl;
	
	delete [] array;

	return (0);
}
