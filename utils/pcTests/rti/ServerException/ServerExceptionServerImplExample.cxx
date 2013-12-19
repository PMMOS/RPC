/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file ServerExceptionServerImplExample.cxx
 * This source file contains the definition of the skeleton for all interfaces.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "ServerExceptionServerImplExample.h"
#include "rpcdds/exceptions/ServerInternalException.h"

using namespace eprosima::rpcdds;
using namespace ::exception;

void ServerExceptionServerImplExample::sendException() 
{
	throw ServerInternalException("Testing exception");
} 

char* ServerExceptionServerImplExample::sendExceptionTwo(/*in*/ char* message, /*inout*/ char*& message2, /*out*/ char*& message3) 
{
    char*  sendExceptionTwo_ret = NULL;

    throw ServerInternalException("Testing exception");

    return sendExceptionTwo_ret;
} 

Estructura ServerExceptionServerImplExample::sendExceptionThree(/*in*/ const Estructura& es, /*inout*/ Estructura& es2, /*out*/ Estructura& es3) 
{
    Estructura sendExceptionThree_ret;

    throw ServerInternalException("Testing exception");

    return sendExceptionThree_ret;
} 
