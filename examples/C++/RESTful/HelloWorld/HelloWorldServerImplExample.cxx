/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this RPCDDS distribution.
 *
 *************************************************************************
 * 
 * @file HelloWorldServerImplExample.cxx
 * This source file contains an example of the declaration of a servant.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "HelloWorldServerImplExample.h"



HelloWorld::HelloResponse HelloWorldResourceServerImplExample::hello(/*in*/ const char* name)
{
    HelloWorld::HelloResponse hello_ret;
    HelloWorld::HelloResponse_initialize(&hello_ret);
	
    hello_ret._d = 1; // 1 -> XML representation
    hello_ret._u.xmlHelloResponse.status = 200; // HTTP OK
	sprintf(hello_ret._u.xmlHelloResponse.xmlRepresentation, "<Response>Hello %s!</Response>", name);
   
    return hello_ret;
} 


