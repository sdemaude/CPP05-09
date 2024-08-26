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

static void    mergeSortList()
{}

static void    mergeSortVector()
{}

static void    insertionSortList()
{}

static void    insertionSortVector()
{}

void    PmergeMe::sort()
{
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