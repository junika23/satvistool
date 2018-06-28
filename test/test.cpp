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

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../utils/FileHelper.h"
#include "../utils/AlgoHelper.h"
#include "../common/SatTimestamp.h"

#include <string>

TEST_CASE( "utils::FileHelper", "file_exists" )
{
    SECTION( "Not existing filepath" )
    {
        const std::string path = "/foo/foo/doo/boo.foo";

        bool res = utils::FileHelper::file_exists( path );

        REQUIRE_FALSE( res );
    }

    SECTION( "Empty filepath" )
    {
        const std::string path = "";

        bool res = utils::FileHelper::file_exists( path );

        REQUIRE_FALSE( res );
    }
}

TEST_CASE( "utils::AlgoHelper", "find_max_occurrences" )
{
    SECTION( "Empty times" )
    {
        std::vector< common::SatTimestamp > starts;
        std::vector< common::SatTimestamp > ends;
        common::SatTimestamp start;
        common::SatTimestamp end;
        uint32_t max;

        utils::AlgoHelper< common::SatTimestamp >::find_max_occurrences( starts, ends, start, end, max );

        REQUIRE_FALSE( start.is_valid( ) );
        REQUIRE_FALSE( end.is_valid( ) );
        REQUIRE( max == 1 );
    }

    SECTION( "two from three same times" )
    {
        std::vector< common::SatTimestamp > starts;
        starts.push_back( common::SatTimestamp( 01, 10, 23, 100 ) );
        starts.push_back( common::SatTimestamp( 01, 10, 23, 100 ) );
        starts.push_back( common::SatTimestamp( 02, 10, 23, 100 ) );
        std::vector< common::SatTimestamp > ends;
        ends.push_back( common::SatTimestamp( 01, 12, 23, 100 ) );
        ends.push_back( common::SatTimestamp( 01, 12, 23, 100 ) );
        ends.push_back( common::SatTimestamp( 03, 12, 23, 100 ) );
        common::SatTimestamp start;
        common::SatTimestamp end;
        uint32_t max;

        utils::AlgoHelper< common::SatTimestamp >::find_max_occurrences( starts, ends, start, end, max );

        REQUIRE( start.is_valid( ) == true );
        REQUIRE( end.is_valid( ) == true );
        REQUIRE( max == 2 );
    }
}

TEST_CASE( "common::SatTimestamp", "Default" )
{
    SECTION( "Empty object" )
    {
        common::SatTimestamp test;

        REQUIRE_FALSE( test.is_valid( ) );
        REQUIRE( test.get_hour() == UINT8_MAX );
        REQUIRE( test.get_millisecond() == UINT16_MAX );
    }

    SECTION( "Wrong time" )
    {
        common::SatTimestamp test( 24, 00, 00, 000 );

        REQUIRE_FALSE( test.is_valid( ) );
    }

    SECTION( "Compare times" )
    {
        common::SatTimestamp test1( 23, 00, 00, 000 );
        common::SatTimestamp test2( 23, 00, 00, 000 );

        REQUIRE( test1 == test2 );
        REQUIRE( test2 >= test2 );
    }
}
