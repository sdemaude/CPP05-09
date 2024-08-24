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
};

template <typename S>
std::ostream& operator<<(std::ostream& os, const std::vector<S>& vec)
{
    for (size_t i = 0; i < vec.size(); i++)
        os << vec[i] << " ";
    return (os);
}