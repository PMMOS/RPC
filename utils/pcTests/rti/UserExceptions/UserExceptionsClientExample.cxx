/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file UserExceptionsClientExample.cxx
 * This source file shows a simple example of how to create a proxy for an interface.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "UserExceptionsProxy.h"
#include "UserExceptionsDDSProtocol.h"
#include "rpcdds/transports/dds/UDPProxyTransport.h"
#include "rpcdds/exceptions/Exceptions.h"
#include "UserExceptionsRequestReplyPlugin.h"

#include "UserExceptionsT.h"

#include <iostream>

using namespace eprosima::rpcdds;
using namespace ::exception;
using namespace ::transport::dds;
using namespace ::protocol::dds;

int main(int argc, char **argv)
{
    UserExceptionsProtocol *protocol = NULL;
    UDPProxyTransport *transport = NULL;
    Beta::IfcProxy *proxy = NULL;
    
    // Creation of the proxy for interface "Beta::Ifc".
    try
    {
        protocol = new UserExceptionsProtocol();
        transport = new UDPProxyTransport("UserExceptionsService");
        proxy = new Beta::IfcProxy(*transport, *protocol);
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        _exit(-1);
    }
    
    // Create and initialize parameters.
    DDS_Long  l1 = 10;
    DDS_Long  l2 = 2;
    DDS_Long  l3 = 120;
    DDS_Long  ret = 0;


    // Call to remote procedure "sendLevel1".
    try
    {
        proxy->sendLevel1(l1, l2, l3);
    }
    catch(Level1 &ex)
    {
        if((ex.count != l1) || (strcmp(ex.msg, "sendLevel1") != 0))
        {
            std::cout << "TEST FAILED<sendLevel1>: Bad data" << std::endl;
            _exit(-1);
        }
    }
    catch(UserException &ex)
    {
        std::cout << "TEST FAILED<sendLevel1>: Different user exception" << std::endl;
        _exit(-1);
    }
    catch(Exception &ex)
    {
        std::cout << "TEST FAILED<sendLevel1>: System exception: " << ex.what() << std::endl;
        _exit(-1);
    }
    
    // Call to remote procedure "sendLevel2".
    try
    {
        ret = proxy->sendLevel2();
    }
    catch(Alfa::Level2 &ex)
    {
        if((ex.count != 101) || (ex.ana.count != 102) || (strcmp(ex.ana.comment, "sendLevel2") != 0))
        {
            std::cout << "TEST FAILED<sendLevel2>: Bad data" << std::endl;
            _exit(-1);
        }
    }
    catch(UserException &ex)
    {
        std::cout << "TEST FAILED<sendLevel2>: Different user exception" << std::endl;
        _exit(-1);
    }
    catch(Exception &ex)
    {
        std::cout << "TEST FAILED<sendLevel2>: System exception: " << ex.what() << std::endl;
        _exit(-1);
    }

    // Call to remote procedure "sendExcep".
    try
    {
        ret = proxy->sendExcep(l1);
    }
    catch(Beta::Excep &ex)
    {
        if((ex.count != l1) || (strcmp(ex.msg, "sendExcep") != 0))
        {
            std::cout << "TEST FAILED<sendExcep>: Bad data" << std::endl;
            _exit(-1);
        }
    }
    catch(UserException &ex)
    {
        std::cout << "TEST FAILED<sendExcep>: Different user exception" << std::endl;
        _exit(-1);
    }
    catch(Exception &ex)
    {
        std::cout << "TEST FAILED<sendExcep>: System exception: " << ex.what() << std::endl;
        _exit(-1);
    }

    // Call to remote procedure "sendExcepIntern".
    try
    {
        ret = proxy->sendExcepIntern(l1);
    }
    catch(Beta::ExcepIntern &ex)
    {
        if((ex.count != l1) || (strcmp(ex.msg, "sendExcepIntern") != 0))
        {
            std::cout << "TEST FAILED<sendExcepIntern>: Bad data" << std::endl;
            _exit(-1);
        }
    }
    catch(UserException &ex)
    {
        std::cout << "TEST FAILED<sendExcepIntern>: Different user exception" << std::endl;
        _exit(-1);
    }
    catch(Exception &ex)
    {
        std::cout << "TEST FAILED<sendExcepIntern>: System exception: " << ex.what() << std::endl;
        _exit(-1);
    }
    
	printf("TEST SUCCESFULLY\n");

    delete proxy;
    delete transport;
    delete protocol;

	_exit(0);
    return 0;
}









