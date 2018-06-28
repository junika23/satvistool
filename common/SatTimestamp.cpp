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

#include "SatTimestamp.h"

#include <cstdarg>
#include <cstdio>

namespace common
{

// -------------------------------------------------------------------------------------------------

int
secure_sprintf( char* buffer, size_t size, const char* format, ... )
{
    if ( buffer == nullptr || format == nullptr )
    {
        return -1;
    }

    int result = -1;
    va_list arg_list;
    va_start( arg_list, format );
    result = vsnprintf( buffer, size, format, arg_list );
    va_end( arg_list );
    return result;
}

// -------------------------------------------------------------------------------------------------

SatTimestamp::SatTimestamp( )
    : m_hour( UINT8_MAX )
    , m_minute( UINT8_MAX )
    , m_second( UINT8_MAX )
    , m_millisecond( UINT16_MAX )
{
}

// -------------------------------------------------------------------------------------------------

SatTimestamp::SatTimestamp( uint8_t hour, uint8_t minute, uint8_t second, uint16_t millisecond )
    : m_hour( hour )
    , m_minute( minute )
    , m_second( second )
    , m_millisecond( millisecond )
{
}

// -------------------------------------------------------------------------------------------------

SatTimestamp::SatTimestamp( const std::string& timestamp_string )
    : m_hour( INT8_MAX )
    , m_minute( INT8_MAX )
    , m_second( INT8_MAX )
    , m_millisecond( INT16_MAX )
{
    from_string( timestamp_string );
}

// -------------------------------------------------------------------------------------------------

SatTimestamp::SatTimestamp( const SatTimestamp& other )
{
    m_hour = other.m_hour;
    m_minute = other.m_minute;
    m_second = other.m_second;
    m_millisecond = other.m_millisecond;
}

// -------------------------------------------------------------------------------------------------

bool
SatTimestamp::is_valid( ) const
{
    return ( ( m_hour >= 0 && m_hour <= 23 ) &&
             ( m_minute >= 0 && m_minute <= 59 ) &&
             ( m_second >= 0 && m_second <= 59 ) &&
             ( m_millisecond >= 0 && m_millisecond <= 999 ) );
}

// -------------------------------------------------------------------------------------------------

bool
SatTimestamp::from_string( const std::string& timestamp_string )
{
    uint8_t hour = UINT8_MAX;
    uint8_t minute = UINT8_MAX;
    uint8_t second = UINT8_MAX;
    uint16_t millisecond = UINT16_MAX;

    if ( std::sscanf( timestamp_string.c_str( ),
                      "%hhu:%hhu:%hhu.%hu",
                      &hour, &minute, &second, &millisecond ) < 4 )
    {
        return false;
    }

    m_hour = hour;
    m_minute = minute;
    m_second = second;
    m_millisecond = millisecond;

    return is_valid( );
}

// -------------------------------------------------------------------------------------------------

std::string
SatTimestamp::to_string( ) const
{
    const size_t buf_size = 16;
    char buf[ buf_size ];

    secure_sprintf( buf, buf_size, "%02hhu:%02hhu:%02hhu.%03hu",
                    m_hour, m_minute, m_second, m_millisecond );

    return std::string( buf );
}

// -------------------------------------------------------------------------------------------------

bool
SatTimestamp::operator==( const SatTimestamp& rhs ) const
{
    return is_valid( )
        && rhs.is_valid( )
        && m_hour == rhs.m_hour
        && m_minute == rhs.m_minute
        && m_second == rhs.m_second
        && m_millisecond == rhs.m_millisecond;
}

// -------------------------------------------------------------------------------------------------

bool
SatTimestamp::operator!=( const SatTimestamp& rhs ) const
{
    return !( *this == rhs );
}

// -------------------------------------------------------------------------------------------------

bool
SatTimestamp::operator>( const SatTimestamp& rhs ) const
{
    if ( is_valid( ) && rhs.is_valid( ) )
    {
        if ( m_hour > rhs.m_hour )
        {
            return true;
        }
        else if ( m_hour == rhs.m_hour )
        {
            if ( m_minute > rhs.m_minute )
            {
                return true;
            }
            else if ( m_minute == rhs.m_minute )
            {
                if ( m_second > rhs.m_second )
                {
                    return true;
                }
                else if ( m_second == rhs.m_second )
                {
                    return m_millisecond > rhs.m_millisecond;
                }
            }
        }
    }

    return false;
}

// -------------------------------------------------------------------------------------------------

bool
SatTimestamp::operator<( const SatTimestamp& rhs ) const
{
    return !( *this >= rhs );
}

// -------------------------------------------------------------------------------------------------

bool
SatTimestamp::operator<=( const SatTimestamp& rhs ) const
{
    return !( *this > rhs );
}

// -------------------------------------------------------------------------------------------------

bool
SatTimestamp::operator>=( const SatTimestamp& rhs ) const
{
    return ( *this == rhs || *this > rhs );
}

// -------------------------------------------------------------------------------------------------

} // common

// End of file
