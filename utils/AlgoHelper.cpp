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

#include "AlgoHelper.h"
#include "../common/SatTimestamp.h"

#include <algorithm>

namespace utils
{

// ------------------------------------------------------------------------------------------------

template < class T >
void
AlgoHelper< T >::find_max_occurrences( std::vector< T >& starts,
                                       std::vector< T >& ends,
                                       T& start,
                                       T& end,
                                       uint32_t& max_occurrences )
{
    // Check whether the size of starts and ends are equal
    if ( starts.size( ) != ends.size( ) )
    {
        return;
    }

    // Sorting the starts and ends will make our life easier
    std::sort( starts.begin( ), starts.end( ) );
    std::sort( ends.begin( ), ends.end( ) );

    // Initial variables
    max_occurrences = 1;
    int32_t occurrence = 1;
    int32_t i = 1;
    int32_t j = 0;

    while ( i < starts.size( ) && j < ends.size( ) )
    {
        // If start of next element less than end of current element
        if ( starts[ i ] <= ends[ j ] )
        {
            // Increment the occurrence and set the next element
            occurrence++;

            // If the maximum occurrences less than the occurrence
            if ( occurrence > max_occurrences )
            {
                max_occurrences = occurrence;
                start = starts[ i ];
                end = std::min( ends[ i ], ends[ j ] );
            }

            i++;
        }
        else
        {
            // Decrement the occurrence and set the current with next element
            occurrence--;
            j++;
        }
    }
}

// -------------------------------------------------------------------------------------------------

template class AlgoHelper< common::SatTimestamp >;

} // utils

// End of file
