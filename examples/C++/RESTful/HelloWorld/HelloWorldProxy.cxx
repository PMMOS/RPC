/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this RPCDDS distribution.
 *
 *************************************************************************
 * 
 * @file HelloWorldProxy.cxx
 * This source file contains the definition of the proxy for all interfaces.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "HelloWorldProxy.h"
#include "rpcdds/transports/ProxyTransport.h"
#include "HelloWorldProtocol.h"
//#include "HelloWorldAsyncSupport.h"

namespace HelloWorld
{
    HelloWorldResourceProxy::HelloWorldResourceProxy(eprosima::rpcdds::transport::ProxyTransport &transport,
        eprosima::rpcdds::protocol::HelloWorldProtocol &protocol) : Proxy(transport, protocol)
    {
        protocol.activateInterface("HelloWorld::HelloWorldResource");
    }

    HelloWorldResourceProxy::~HelloWorldResourceProxy()
    {
    }




    HelloWorld::HelloResponse HelloWorldResourceProxy::hello(/*in*/ const char* name)
    {
        HelloWorld::HelloResponse hello_ret =
        dynamic_cast<eprosima::rpcdds::protocol::HelloWorldProtocol&>(getProtocol()).HelloWorld_HelloWorldResource_hello(name);
        return hello_ret;
    }


};
