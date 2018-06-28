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

#include "FileHelper.h"

#include <sys/stat.h>
#include <dirent.h>


namespace utils
{

// ------------------------------------------------------------------------------------------------

bool
FileHelper::canonical_path( const std::string& in, std::string& out )
{
    const char* cstr_in = in.c_str( );
    char cstr_out[ PATH_MAX ];
    char* out_ptr;

    out_ptr = realpath( cstr_in, cstr_out );

    if ( !out_ptr )
    {
        out.assign( cstr_in );

        return false;
    }

    out.assign( out_ptr );

    return true;
}

// -------------------------------------------------------------------------------------------------

bool
FileHelper::file_exists( const std::string& file_path )
{
    if ( file_path.empty( ) )
    {
        return false;
    }

    struct stat stat_info;

    return ( 0 == stat( file_path.c_str( ), &stat_info ) ) && S_ISREG( stat_info.st_mode );
}

// -------------------------------------------------------------------------------------------------

} // utils

// End of file
