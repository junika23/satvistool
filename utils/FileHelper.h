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

#ifndef FILEHELPER_H
#define FILEHELPER_H

#include <string>

namespace utils
{

class FileHelper
{
public:
    /**
     * Returns true if the given in path can be converted as canonical path
     * @param in A path to a file
     * @param out A canonical path of the given path
     */
    static bool canonical_path( const std::string& in, std::string& out );

    /**
     * Returns true if the given file_path does exist and a valid file
     * @param file_path A path to a file
     */
    static bool file_exists( const std::string& file_path );
};

} // utils

#endif // FILEHELPER_H
