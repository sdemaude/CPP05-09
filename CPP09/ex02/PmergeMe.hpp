/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:42:44 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/23 17:00:48 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <limits.h>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>
#include <time.h>
#include <set>
#include <list>

typedef std::list<int>::iterator listIt;

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(std::string const &containerType, std::vector<int> const &original);
        PmergeMe(PmergeMe const &other);
        ~PmergeMe();

        void        sort();
        PmergeMe    &operator=(PmergeMe const &other);

    private:
        std::string         containerType;
        std::list<int>      list;
        std::vector<int>    vector;
        void	            mergeList(listIt begin, listIt mid, listIt end);
        void	            mergeSortList(listIt begin, listIt end);
        void	            mergeVector(int begin, int mid, int end);
        void		        mergeSortVector(int begin, int end);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& c)
{
    typename std::vector<T>::const_iterator    it;
    for (it = c.begin(); it != c.end(); it++)
        os << *it << " ";
    return (os);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& c)
{
    typename std::list<T>::const_iterator    it;
    for (it = c.begin(); it != c.end(); it++)
        os << *it << " ";
    return (os);
}