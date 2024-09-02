/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:42:43 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/23 17:00:43 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}
        
PmergeMe::PmergeMe(std::string const &containerType, std::vector<int> const &original) : containerType(containerType)
{
	if (this->containerType == "list")
		this->list.assign(original.begin(), original.end()); 
	else if (this->containerType == "vector")
		this->vector.assign(original.begin(), original.end()); 
}
        
PmergeMe::PmergeMe(PmergeMe const &other) : containerType(other.containerType), list(other.list), vector(other.vector)
{}
       
PmergeMe::~PmergeMe()
{}

void	PmergeMe::mergeList(listIt begin, listIt mid, listIt end)
{
	std::list<int>	tmp;
	listIt			a = begin;
	listIt			b = mid;
	listIt			pairBegin;

	while (a != mid && b != end)
	{
		if (*a > *b)
		{
			pairBegin = b;
			if (++b != end)
				b++;
			tmp.insert(tmp.end(), pairBegin, b);
		}
		else
		{
			pairBegin = a;
			if (++a != mid)
				a++;
			tmp.insert(tmp.end(), pairBegin, a);
		}
	}
	while (a != mid)
	{
		pairBegin = a;
		if (++a != mid)
			a++;
		tmp.insert(tmp.end(), pairBegin, a);
	}
	std::copy(tmp.begin(), tmp.end(), begin);
}

void	PmergeMe::mergeSortList(listIt begin, listIt end)
{	
	int	size = std::distance(begin, end);
	
	if (size <= 2)
	{
		if (size == 2 && *begin < *--end)
			std::iter_swap(begin, end);
		return;
	}

	std::list<int>::iterator mid = begin;
	std::advance(mid, size / 2 + size / 2 % 2);

	this->mergeSortList(begin, mid);
	this->mergeSortList(mid, end);
	this->mergeList(begin, mid, end);
}

static listIt 	insertionList(listIt begin, listIt end, int value)
{
	if (begin == end)
        return (begin);
	
	std::list<int>::iterator mid = begin;
	std::advance(mid, std::distance(begin, end) / 2);

    if (value < *mid)
        return (insertionList(begin, mid, value));
    else if (value > *mid)
        return (insertionList(++mid, end, value));
    else
        return (mid);
}

void	PmergeMe::insertionSortList()
{
	std::list<int>	tmp;
	listIt			curr = this->list.begin();

	for (size_t i = 0; i < this->list.size(); i++)
	{
		if (curr == --this->list.end() || i % 2)
			tmp.insert(insertionList(tmp.begin(), tmp.end(), *curr), *curr);
		else
			tmp.push_back(*curr);
		curr++;
	}
	this->list = tmp;
}

void	PmergeMe::mergeVector(int begin, int mid, int end)
{
	std::vector<int> tmp;
	int a = begin;
	int b = mid;

	while (a < mid && b < end)
	{
		if (this->vector[a] < this->vector[b])
		{
			tmp.push_back(this->vector[a++]);
			if (a < mid) 
				tmp.push_back(this->vector[a++]);
		}
		else
		{
			tmp.push_back(this->vector[b++]);
			if (b < end) 
				tmp.push_back(this->vector[b++]);
		}
	}
	while (a < mid)
	{
		tmp.push_back(this->vector[a++]);	
		if (a < mid)
			tmp.push_back(this->vector[a++]);
	}
	std::copy(tmp.begin(), tmp.end(), this->vector.begin() + begin);
}

void		PmergeMe::mergeSortVector(int begin, int end)
{
	int	size = end - begin;
	
	if (size <= 2)
	{
		if (size == 2 && this->vector[begin] < this->vector[--end])
			std::swap(this->vector[begin], this->vector[end]);
		return;
	}

	int mid = begin + size / 2 + size / 2 % 2;

	this->mergeSortVector(begin, mid);
	this->mergeSortVector(mid, end);
	this->mergeVector(begin, mid, end);
}

int 	PmergeMe::insertionVector(int begin, int end, int value, std::vector<int> tmp)
{
	if (begin == end)
        return (begin);

	int mid = begin + (end - begin) / 2;

    if (value < tmp[mid])
        return (insertionVector(begin, mid, value, tmp));
    else if (value > tmp[mid])
        return (insertionVector(++mid, end, value, tmp));
	else
		return (mid);
}

void	PmergeMe::insertionSortVector()
{
	std::vector<int>	tmp;
	size_t				size = this->vector.size();

	for (size_t i = 0; i < size; i++)
	{
		if (i + 1 == size || i % 2)
			tmp.insert(tmp.begin() + insertionVector(0, tmp.size(), this->vector[i], tmp), this->vector[i]);
		else
			tmp.push_back(this->vector[i]);
	}
	this->vector = tmp;
}

void    PmergeMe::sort()
{
	struct timespec beginTime, endTime;

	clock_gettime(CLOCK_REALTIME, &beginTime);
	if (containerType == "list")
	{
		listIt end = this->list.end();

		if (this->list.size() % 2)
			end--;
		this->mergeSortList(this->list.begin(), end);
		this->insertionSortList();
		//std::cout << "list   : " << this->list << std::endl;
	}
	else if (containerType == "vector")
	{
		int	end = this->vector.size();

		if (end % 2)
			end--;
		this->mergeSortVector(0, end);
		this->insertionSortVector();
		//std::cout << "vector : " << this->vector << std::endl;
	}
	clock_gettime(CLOCK_REALTIME, &endTime);
	long nanoseconds = endTime.tv_nsec - beginTime.tv_nsec;
	elapsedTime =  (static_cast<double>(nanoseconds));
}

double	PmergeMe::getElapsedTime()
{
	return (this->elapsedTime);
}

std::vector<int>	&PmergeMe::getVector()
{
	return (this->vector);
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	this->containerType = other.containerType;
	this->list = other.list;
	this->vector = other.vector;
	return (*this);
}