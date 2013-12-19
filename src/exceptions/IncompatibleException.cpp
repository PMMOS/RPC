/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************/

#include <rpcdds/exceptions/IncompatibleException.h>

using namespace eprosima::rpcdds::exception;

IncompatibleException::IncompatibleException(const std::string &message) : SystemException(message, 1)
{
}

IncompatibleException::IncompatibleException(std::string&& message) : SystemException(std::move(message), 1)
{
}

IncompatibleException::IncompatibleException(const IncompatibleException &ex) : SystemException(ex)
{
}

IncompatibleException::IncompatibleException(IncompatibleException&& ex) : SystemException(std::move(ex))
{
}

IncompatibleException& IncompatibleException::operator=(const IncompatibleException &ex)
{
    if(this != &ex)
    {
        SystemException::operator=(ex);
    }

    return *this;
}

IncompatibleException& IncompatibleException::operator=(IncompatibleException&& ex)
{
    if(this != &ex)
    {
        SystemException::operator=(std::move(ex));
    }

    return *this;
}

IncompatibleException::~IncompatibleException() throw()
{
}

void IncompatibleException::raise() const
{
    throw *this;
}
