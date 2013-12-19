/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this RPCDDS distribution.
 *
 *************************************************************************
 * 
 * @file CalculatorProxy.cxx
 * This source file contains the definition of the proxy for all interfaces.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "CalculatorProxy.h"
#include "rpcdds/transports/ProxyTransport.h"
#include "CalculatorProtocol.h"
//#include "CalculatorAsyncSupport.h"

namespace Calculator
{
    addResourceProxy::addResourceProxy(eprosima::rpcdds::transport::ProxyTransport &transport,
        eprosima::rpcdds::protocol::CalculatorProtocol &protocol) : Proxy(transport, protocol)
    {
        protocol.activateInterface("Calculator::addResource");
    }

    addResourceProxy::~addResourceProxy()
    {
    }




    Calculator::AddResponse addResourceProxy::add(/*in*/ DDS_Long a, /*in*/ DDS_Long b)
    {
        Calculator::AddResponse add_ret =
        dynamic_cast<eprosima::rpcdds::protocol::CalculatorProtocol&>(getProtocol()).Calculator_addResource_add(a, b);
        return add_ret;
    }


    substractResourceProxy::substractResourceProxy(eprosima::rpcdds::transport::ProxyTransport &transport,
        eprosima::rpcdds::protocol::CalculatorProtocol &protocol) : Proxy(transport, protocol)
    {
        protocol.activateInterface("Calculator::substractResource");
    }

    substractResourceProxy::~substractResourceProxy()
    {
    }




    Calculator::SubstractResponse substractResourceProxy::substract(/*in*/ DDS_Long a, /*in*/ DDS_Long b)
    {
        Calculator::SubstractResponse substract_ret =
        dynamic_cast<eprosima::rpcdds::protocol::CalculatorProtocol&>(getProtocol()).Calculator_substractResource_substract(a, b);
        return substract_ret;
    }


    multiplyResourceProxy::multiplyResourceProxy(eprosima::rpcdds::transport::ProxyTransport &transport,
        eprosima::rpcdds::protocol::CalculatorProtocol &protocol) : Proxy(transport, protocol)
    {
        protocol.activateInterface("Calculator::multiplyResource");
    }

    multiplyResourceProxy::~multiplyResourceProxy()
    {
    }




    Calculator::MultiplyResponse multiplyResourceProxy::multiply(/*in*/ DDS_Long a, /*in*/ DDS_Long b)
    {
        Calculator::MultiplyResponse multiply_ret =
        dynamic_cast<eprosima::rpcdds::protocol::CalculatorProtocol&>(getProtocol()).Calculator_multiplyResource_multiply(a, b);
        return multiply_ret;
    }


    divideResourceProxy::divideResourceProxy(eprosima::rpcdds::transport::ProxyTransport &transport,
        eprosima::rpcdds::protocol::CalculatorProtocol &protocol) : Proxy(transport, protocol)
    {
        protocol.activateInterface("Calculator::divideResource");
    }

    divideResourceProxy::~divideResourceProxy()
    {
    }




    Calculator::DivideResponse divideResourceProxy::divide(/*in*/ DDS_Long a, /*in*/ DDS_Long b)
    {
        Calculator::DivideResponse divide_ret =
        dynamic_cast<eprosima::rpcdds::protocol::CalculatorProtocol&>(getProtocol()).Calculator_divideResource_divide(a, b);
        return divide_ret;
    }


};
