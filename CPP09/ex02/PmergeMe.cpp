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
	std::advance(mid, size / 2);

	this->mergeSortList(begin, mid);
	this->mergeSortList(mid, end);
	this->mergeList(begin, mid, end);
}

void	PmergeMe::mergeVector(int begin, int mid, int end)
{
	std::vector<int>	tmp;
	int					a = begin;
	int					b = mid;

	while (a != mid && b != end)
	{
		if (this->vector[a] > this->vector[b])
		{
			tmp.push_back(this->vector[b++]);	
			if (b != end)
				tmp.push_back(this->vector[b++]);	
		}
		else
		{
			tmp.push_back(this->vector[a++]);	
			if (a != end)
				tmp.push_back(this->vector[a++]);	
		}
	}
	while (a != mid)
	{
		tmp.push_back(this->vector[a++]);	
		if (a != end)
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

	int mid = size / 2 + begin;

	this->mergeSortVector(begin, mid);
	this->mergeSortVector(mid, end);
	this->mergeVector(begin, mid, end);
}

static void		insertionSortList()
{}

static void		insertionSortVector()
{}

void    PmergeMe::sort()
{
	if (containerType == "list")
	{
		mergeSortList(this->list.begin(), this->list.end());
		insertionSortList();
		std::cout << "list : " << this->list << std::endl;
	}
	else if (containerType == "vector")
	{
		mergeSortVector(0, this->vector.size());
		insertionSortVector();
		std::cout << "vector : " << this->vector << std::endl;
	}
	//call to merge sort function (will divide the elements into sorted pairs)
	//call to insertion sort function on 'b' elements of the pairs (the min ones)
	//        but changing the range (we know its smaller than its 'a')
	//if its an 'a' elements just push it at the end
	//youhou its sorted !
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	this->containerType = other.containerType;
	this->list = other.list;
	this->vector = other.vector;
	return (*this);
}