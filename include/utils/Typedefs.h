/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************/

#ifndef _UTILS_TYPEDEFS_H_
#define _UTILS_TYPEDEFS_H_

#include "utils/dds/Middleware.h"

namespace eprosima
{
	namespace rpcdds
	{
        namespace transport
        {
            class ServerTransport;
        }

#define DDS_TIMEOUT(name, duration) DDS::Duration_t name = {duration.total_seconds(), \
    static_cast<EPROSIMA_UINT32>(duration.fractional_seconds() * (1000000000 / boost::posix_time::time_duration::traits_type::res_adjust()))};

#define DDS_TIMEOUT_SET(name, duration) name.sec = duration.total_seconds(); \
        name.nanosec = static_cast<EPROSIMA_UINT32>(duration.fractional_seconds() * (1000000000 / boost::posix_time::time_duration::traits_type::res_adjust()));

		typedef void(*fExecFunction)(eprosima::rpcdds::transport::ServerTransport&, void*);
	} // namespace rpcdds
} // namespace eprosima

#endif // _UTILS_TYPEDEFS_H_
