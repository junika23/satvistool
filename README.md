satvistool (Satellite Visibility Tool)
======================================================================================================================================

A console application to calculate the maximum numbers of satellites within a range of time which are visible to the ground station.

Usage:
satvistool \<path to log file\>

Output:
\<start time\>-\<end time\>;\<maximum number of satellites\>

Dependencies:
---------------------------------------------------------------------------------------------------------------------------------------
- gcc/g++ version 4.9 or above
- cmake build software
- doxygen to build the code documentation (the output documentation is already included under docs folder)

The solution has been implemented under VMWare on Windows with linux (Ubuntu variant) guest. As IDE, QtCreator has been used.

Content of solution:
---------------------------------------------------------------------------------------------------------------------------------------
1) main.cpp -> main function\n
2) common/SatTimestamp.h/cpp -> Our own implementation of time class to represent Satellite timestamp\n
3) utils/FileHelper.h/cpp -> Implementation of file system related utility such us file_exists and canonical_path static methods
mostly using posix file system\n
4) utils/AlgoHelper.h/cpp -> Implementation of algorithm to find the maximum number of satellites that are visible to ground station
within a time range\n
5) docs folder -> contains doxygen related files and folder\n
6) test folder -> contains unit/functional test related sources (using catch)\n
7) CMakeLists.txt(s) -> cmake related file to build the solution (either using make or ninja)\n
8) Satellites.pdf -> the specification/exercise of this solution\n
9) satellites.dat -> log file as input of the satvistool solution/application\n
10) README.md -> this file.


Major issues and known limitation regarding the implementation of satvistool:
---------------------------------------------------------------------------------------------------------------------------------------
<b>1) Timestamp data</b>\n
We could actually use std::chrono library as part of C++11 but due to some limitation e.g. gcc-4.9 which doesn't have full support of
std::chrono library, in fact that some of embedded platforms are still using older gcc, we can't fully rely on c++11 features. That's 
why we will use our own class to represent timestamp of the satellites.

Using time_ts or ts is not an option since we want to have milliseconds information included into our calculation.
We could use some open source component such as Howard Hinnant's date library (https://github.com/HowardHinnant/date) but to avoid any
dependency to 3rd party, we probably should implement our own timestamp class which is SatTimestamp class in this case.

SatTimestamp will store all relevant timestamp data which are hour, minute, second and millisecond. It has the capability to check
whether the timestamp is valid or invalid and it implements also couple of useful overloaded operators such as ==, !=, <, >, <= and >=

<b>2) Algorithm to calculate the maximum number of occurrences within certain time range(s)</b>\n
Since we have four relevant data of our SatTimestamp class such as hour, minute, second and millisecond, we can't simply use count
array solution. Count array solution will work properly in case we have only one data of time e.g. hour only.

Instead, we will use a solution which will sort lists or vectors of start and end times. Once we have all information sorted, 
we can simply calculate the number of satellites that are visible to the ground station. 
In this algorithm, we need also to consider the end time range.

Time complexity would be O(n log n) which is fine for our case.

There's another solution using auxilary array which is similar to count array one, but currently is not applicable due to multiple 
relevant data that need to be considered.

From the maintenance perspective, it would be much more clearer to use sorted timestamp solution.

<b>Limitation:</b> If there are two maximum numbers within different time range(s), it will return the first one as result.


Test
---------------------------------------------------------------------------------------------------------------------------------------

Though it's not specified, but a small and simple test is provided in this solution using catch test framework. The advantages of catch
is that it doesn't need any library, one just need to add one single header file (catch.hpp) into test file implementation (test.cpp)
and build the whole unit and integration/functional test. Some simple test cases are already implemented in this solution.