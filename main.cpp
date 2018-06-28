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

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#ifdef WITH_DURATION
#include <chrono>
#endif

#include "common/SatTimestamp.h"
#include "utils/FileHelper.h"
#include "utils/AlgoHelper.h"


// ------------------------------------------------------------------------------------------------

int main( int argc, char* argv[ ] )
{
    // Parameters:
    // <appname> <path to log file>
    std::string log_filepath;

    switch( argc )
    {
        case 1:
        {
            std::cout << "Please specify path to a log file.\n"
                         "Usage: satvistool <path to a log file> <options>\n"
                         "For example: \"satvistool /var/log/sat.dat\""
                      << std::endl;
            return 0;
        }
        case 2:
        {
            log_filepath = argv[ 1 ];
            break;
        }
    }

    std::string absolute_path;
    // Check whether the file is a valid file and does exist
    if ( utils::FileHelper::canonical_path( log_filepath, absolute_path) )
    {
        if ( !utils::FileHelper::file_exists(absolute_path) )
        {
            std::cout << "File: \"" << log_filepath <<
                         "\" does not exist or is not a valid file" << std::endl;
            return 0;
        }
    }
    else
    {
        std::cout << "File: \"" << log_filepath << "\" does not exist" << std::endl;
        return 0;
    }

    std::vector< common::SatTimestamp > starts;
    std::vector< common::SatTimestamp > ends;
    std::string line;
    std::ifstream file( absolute_path );

    // Prepare the vectors of start and end times
    while ( std::getline( file, line ) )
    {
        size_t pos = line.find( ',' );
        if ( pos != std::string::npos )
        {
            common::SatTimestamp start( line.substr( 0, pos ) );
            common::SatTimestamp end( line.substr( pos + 1 ) );

            if ( start.is_valid( ) && end.is_valid( ) && end >= start )
            {
                starts.push_back( start );
                ends.push_back( end );
            }
        }
    }

    common::SatTimestamp start;
    common::SatTimestamp end;
    uint32_t maximum = 0;

#ifdef WITH_DURATION
    std::chrono::high_resolution_clock::time_point s =
            std::chrono::high_resolution_clock::now( );
#endif

    utils::AlgoHelper< common::SatTimestamp >::find_max_occurrences(
                starts, ends, start, end, maximum );

#ifdef WITH_DURATION
    std::chrono::high_resolution_clock::time_point e =
            std::chrono::high_resolution_clock::now( );
#endif

    std::cout << start.to_string( ) << "-" << end.to_string( ) << ";" << maximum << std::endl;

#ifdef WITH_DURATION
    std::cout << "Duration in microseconds: " <<
                 std::chrono::duration_cast< std::chrono::microseconds >( e - s ).count( ) <<
                 std::endl;
#endif

    return 0;
}

// -------------------------------------------------------------------------------------------------

// End of file
