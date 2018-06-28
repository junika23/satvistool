/*
// -------------------------------------------------------------------------------------------------
//
// Copyright (C) Juniarto Saputra (juniarto.wongso@gmail.com). All rights reserved.
//
// This software, including documentation, is protected by copyright controlled by
// the contributor(s). All rights are reserved. Copying, including reproducing, storing,
// adapting or translating, any or all of this material requires the prior written
// consent of the contributor(s).
//
// -------------------------------------------------------------------------------------------------
*/

#ifndef ALGOHELPER_H
#define ALGOHELPER_H

#include <vector>
#include <cstdint>

namespace utils
{

template < class T >
class AlgoHelper
{
public:

    /**
     * @brief Finds the maximum number of occurrences within time range(s) using sort.
     * Complexity: O (n log n)
     *
     * @param starts A vector of start time element
     * @param ends A vector of end time element
     * @param start A start time
     * @param end An end time
     * @param max_occurrences Number of maximum occurrences
     */
    static void find_max_occurrences( std::vector< T >& starts,
                                      std::vector< T >& ends,
                                      T& start,
                                      T& end,
                                      uint32_t& max_occurrences );
};

} // utils

#endif // ALGOHELPER_H
