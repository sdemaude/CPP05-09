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

void    PmergeMe::sort()
{
    
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
    this->containerType = other.containerType;
    this->list = other.list;
    this->vector = other.vector;
    return (*this);
}