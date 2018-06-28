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

#ifndef SATTIMESTAMP_H
#define SATTIMESTAMP_H

#include <cstdint>
#include <string>

namespace common
{

class SatTimestamp
{
public:

    /**
     * @brief Default constructor
     * Construct an invalid SatTimestamp object
     */
    SatTimestamp( );

    /**
     * @brief Default constructor with parameters
     * @param hour A number represents 24-hour (between 0 and 23)
     * @param minute A number represents minute (between 0 and 59)
     * @param second A number represents second (between 0 and 59)
     * @param millisecond A number represents millisecond (between 0 and 999).
     */
    SatTimestamp( uint8_t hour, uint8_t minute, uint8_t second, uint16_t millisecond );

    /**
     * @brief Construct SatTimestamp from string
     * @param timestamp_string timestamp as string
     */
    SatTimestamp( const std::string& timestamp_string );

    /**
     * @brief Copy constructor
     * @param other another SatTimestamp object to be copied.
     */
    SatTimestamp( const SatTimestamp& other );

public:

    /**
     * @brief Validates the SatTimestamp object
     * @return True if SatTimestamp is valid, false otherwise.
     */
    bool is_valid( ) const;

    /**
     * @brief Set SatTimestamp based on the given string
     * @param timestamp_string the new SatTimestamp as string. The string is expected
     * to have a format "%u:%u:%u.%u" (without " marks, for example <b>02:23:30.234</b>
     * @return True if SatTimestamp is successfully parsed and valid, false otherwise.
     */
    bool from_string( const std::string& timestamp_string );

    /**
     * @brief Returns SatTimestamp object as string
     * @return SatTimestamp as string
     */
    std::string to_string( ) const;

    /**
     * @brief Get the hour from SatTimestamp
     * @return hour
     */
    uint8_t get_hour( ) const
    {
        return m_hour;
    }

    /**
     * @brief Get the minute from SatTimestamp
     * @return minute
     */
    uint8_t get_minute( ) const
    {
        return m_minute;
    }

    /**
     * @brief Get the second from SatTimestamp
     * @return second
     */
    uint8_t get_second( ) const
    {
        return m_second;
    }

    /**
     * @brief Get the millisecond from SatTimestamp
     * @return millisecond
     */
    uint16_t get_millisecond( ) const
    {
        return m_millisecond;
    }

public:

    /**
     * Equality of SatTimestamps.
     * SatTimestamps are equal when all parts are equal.
     * This SatTimestamp and lhs need to be valid. If either is (or both!)
     * are invalid, the function returns false.
     *
     * @param lhs The SatTimestamp to compare to.
     *
     * @return True if SatTimestamps are equal.
     */
    bool operator==( const SatTimestamp& lhs ) const;

    /**
     * Inequality SatTimestamps.
     * SatTimestamps are not equal when any of SatTimestamp parts are not equal.
     * This SatTimestamp and lhs need to be valid. If either is (or both!)
     * are invalid, the function returns true.
     *
     * @param lhs The SatTimestamp to compare to.
     *
     * @return true if SatTimestamps are not equal.
     */
    bool operator!=( const SatTimestamp& lhs ) const;

    /**
     * Compare SatTimestamps.
     * SatTimestamp parts are compared in order of importance.
     * This SatTimestamp and lhs need to be valid. If either is (or both!)
     * are invalid, the function returns false.
     *
     * @param lhs The SatTimestamp to compare to.
     *
     * @return True if this is earlier than lhs and both are valid, false otherwise
     */
    bool operator<( const SatTimestamp& lhs ) const;

    /**
     * Compare SatTimestamps.
     * SatTimestamp parts are compared in order of importance.
     * This SatTimestamp and lhs need to be valid. If either is (or both!)
     * are invalid, the function returns false.
     *
     * @param lhs The SatTimestamp to compare to.
     * @return True if this is later than lhs and both are valid, false otherwise.
     */
    bool operator>( const SatTimestamp& lhs ) const;

    /**
     * Compare SatTimestamps.
     * Combines operators operator<( ) and operator==( ) or inclusived <( ).
     *
     * @param lhs The SatTimestamp to compare to.
     *
     * @return True if this is earlier or equal than lhs and both are valid, false otherwise.
     *
     * @sa SatTimestamp::operator<
     * @sa SatTimestamp::operator==
     */
    bool operator<=( const SatTimestamp& lhs ) const;

    /**
     * Compare SatTimestamps.
     * Combines <( ) and ==( ) operators or inclusived >( ).
     *
     * @param lhs The SatTimestamp to compare to.
     *
     * @return True if this is later or equal than lhs and both are valid, false otherwise.
     *
     * @sa SatTimestamp::operator<
     * @sa SatTimestamp::operator==
     */
    bool operator>=( const SatTimestamp& lhs ) const;

private:

    uint8_t m_hour;
    uint8_t m_minute;
    uint8_t m_second;
    uint16_t m_millisecond;
};

} // common

#endif // SATTIMESTAMP_H
