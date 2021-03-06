/*-----------------------------------------------------------------------------+
Copyright (c) 2018-2018: Hagen Pache
+------------------------------------------------------------------------------+
   Distributed under the Boost Software License, Version 1.0.
      (See accompanying file LICENCE.txt or copy at
           http://www.boost.org/LICENSE_1_0.txt)
+-----------------------------------------------------------------------------*/
#pragma once
#include <dil/Interval.hpp>

namespace dil {
namespace ii {

template <typename T>
inline bool precedes(const Interval<T>& lhs, const Interval<T>& rhs)
{
    return (lhs.upper() < rhs.lower()); 
}

template <typename T>
inline bool preceded_by(const Interval<T>& lhs, const Interval<T>& rhs)
{
    return precedes(rhs, lhs);
}

template <typename T>
inline bool meets(const Interval<T>& lhs, const Interval<T>& rhs)
{
    return (    (lhs.upper() == rhs.lower())
            &&  (lhs.lower() < rhs.upper())); 
}

template <typename T>
inline bool met_by(const Interval<T>& lhs, const Interval<T>& rhs)
{
    return meets(rhs, lhs); 
}

template <typename T>
inline bool overlaps(const Interval<T>& lhs, const Interval<T>& rhs)
{
    return (    (lhs.lower() < rhs.lower())
            &&  (lhs.upper() > rhs.lower())
            &&  (lhs.upper() < rhs.upper())); 
}

template <typename T>
inline bool overlapped_by(const Interval<T>& lhs, const Interval<T>& rhs)
{
    return overlaps(rhs,lhs); 
}

template <typename T>
inline bool starts(const Interval<T>& lhs, const Interval<T>& rhs)
{
    return (    (lhs.lower() == rhs.lower())
            &&  (lhs.upper() < rhs.upper())); 
}

template <typename T>
inline bool started_by(const Interval<T>& lhs, const Interval<T>& rhs)
{
    return starts(rhs,lhs); 
}

template <typename T>
inline bool during(const Interval<T>& lhs, const Interval<T>& rhs)
{
    return (    (lhs.lower() > rhs.lower())
            &&  (lhs.upper() < rhs.upper())); 
}

template <typename T>
inline bool contains(const Interval<T>& lhs, const Interval<T>& rhs)
{
    return during(rhs,lhs); 
}

template <typename T>
inline bool finishes(const Interval<T>& lhs, const Interval<T>& rhs)
{
    return (    (lhs.lower() > rhs.lower())
            &&  (lhs.upper() == rhs.upper())); 
}

template <typename T>
inline bool finished_by(const Interval<T>& lhs, const Interval<T>& rhs)
{
    return finishes(rhs,lhs); 
}

template <typename T>
inline bool equals(const Interval<T>& lhs, const Interval<T>& rhs)
{
    return (    (lhs.lower() == rhs.lower())
            &&  (lhs.upper() == rhs.upper())); 
}

}
}