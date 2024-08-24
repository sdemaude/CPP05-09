/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:42:41 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/24 12:18:33 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#define BASE 10

bool containsDuplicates(std::vector<int> const &vec)
{
	std::set<int>	seen;

	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
		seen.insert(*it);
	}

	return false;
}

void toVector(int size, char **argv, std::vector<int> &vec)
{
	char	*endPtr;

	for (int i = 0; i < size; i++)
	{
		long	value = strtol(argv[i], &endPtr, BASE);
		if (endPtr == argv[i] or *endPtr != '\0')
			throw (std::invalid_argument("Error: Incorrect value passed as input!"));
		if (value < 0)
			throw (std::invalid_argument("Error: Negative value passed as input!"));
		if (value > INT_MAX)
			throw (std::invalid_argument("Error: All values must be integers!"));
		if (std::find(vec.begin(), vec.end(), static_cast<int>(value)) != vec.end())
			throw (std::invalid_argument("Error: Duplicates found!"));
		vec.push_back(value);
	}
}

double	getTimeToSort(std::string const &container, std::vector<int> const &vec)
{
	struct timespec begin, end;
	clock_gettime(CLOCK_REALTIME, &begin);

	PmergeMe merge(container, vec);
	//merge.sort();

	clock_gettime(CLOCK_REALTIME, &end);
	long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;

    return (static_cast<double>(seconds + nanoseconds*1e-9));
}

void	displayInfos(int argc, int ETL, int ETV, std::vector<int> const &before)
{
	std::cout << "Before: " << before << std::endl;
	std::cout << "After: " << before << std::endl;
	std::cout << "Time to process a range of " << argc << " elements with std::list : " << ETL << " s" << std::endl;
	std::cout << "Time to process a range of " << argc << " elements with std::vector : " << ETV << " s" << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cerr << "Error: Incorrect use of program, you should pass at least two numbers as arguments!" << std::endl;
		return (1);
	}

	std::vector<int>	vec;
	try
	{
		toVector(--argc, ++argv, vec);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	double	elapsedTimeList = getTimeToSort("list", vec);
	double	elapsedTimeVect = getTimeToSort("vector", vec);

	displayInfos(argc, elapsedTimeList, elapsedTimeVect, vec);
	
	return (0);
}
