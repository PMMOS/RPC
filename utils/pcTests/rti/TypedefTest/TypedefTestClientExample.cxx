/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file TypedefTestClientExample.cxx
 * This source file shows a simple example of how to create a proxy for an interface.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "TypedefTestProxy.h"
#include "TypedefTestDDSProtocol.h"
#include "rpcdds/transports/dds/UDPProxyTransport.h"
#include "rpcdds/exceptions/Exceptions.h"
#include "TypedefTestRequestReplyPlugin.h"

#include <iostream>

using namespace eprosima::rpcdds;
using namespace ::exception;
using namespace ::transport::dds;
using namespace ::protocol::dds;

int main(int argc, char **argv)
{
    TypedefTestProtocol *protocol = NULL;
    UDPProxyTransport *transport = NULL;
    TypedefTestProxy *proxy = NULL;
    
    try
    {
        protocol = new TypedefTestProtocol();
        transport = new UDPProxyTransport("TypedefTestService");
        proxy = new TypedefTestProxy(*transport, *protocol);
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }

    largo  l1 = 1;    
    largo  l2 = 0;       
    largo  getLargo_ret = 0;    

    try
    {
        getLargo_ret = proxy->getLargo(l1, l2);

        if(l2 != 1 ||
                getLargo_ret != 1 ||
                l1 != 1)
        {
            std::cout << "TEST FAILED<getLargo>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getLargo>: " << ex.what() << std::endl;
        _exit(-1);
    }

    larguisimo  ll1 = 1;       
    larguisimo  ll2 = 0;    
    larguisimo  getLarguisimo_ret = 0;       

    try
    {
        getLarguisimo_ret = proxy->getLarguisimo(ll1, ll2);

        if(ll2 != 1 ||
                getLarguisimo_ret != 1 ||
                ll1 != 1)
        {
            std::cout << "TEST FAILED<getLarguisimo>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getLarguisimo>: " << ex.what() << std::endl;
        _exit(-1);
    }

    DatosDef d1;      
    DatosDef d2;    
    DatosDef getDatosDef_ret;       

    DatosDef_initialize(&d1);
    DatosDef_initialize(&d2);
    DatosDef_initialize(&getDatosDef_ret);

    d1.count = 1;
    d1.message = DDS::String_dup("PRUEBA");;

    try
    {
        getDatosDef_ret = proxy->getDatosDef(d1, d2);

        if(d2.count != 1 || strcmp(d2.message, "PRUEBA") != 0 ||
                getDatosDef_ret.count != 1 || strcmp(getDatosDef_ret.message, "PRUEBA") != 0 ||
                d1.count != 1 || strcmp(d1.message, "PRUEBA") != 0)
        {
            std::cout << "TEST FAILED<getDatosDef>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getDatosDef>: " << ex.what() << std::endl;
        _exit(-1);
    }

    DatosDef_finalize(&d1);    
    DatosDef_finalize(&d2);    
    DatosDef_finalize(&getDatosDef_ret);    

    DatosDefondo dd1;       
    DatosDefondo dd2;    
    DatosDefondo getDatosDefondo_ret;       

    DatosDefondo_initialize(&dd1);
    DatosDefondo_initialize(&dd2);
    DatosDefondo_initialize(&getDatosDefondo_ret);

    dd1.count = 1;
    dd1.message = DDS::String_dup("PRUEBA");

    try
    {
        getDatosDefondo_ret = proxy->getDatosDefondo(dd1, dd2);

        if(dd2.count != 1 || strcmp(dd2.message, "PRUEBA") != 0 ||
                getDatosDefondo_ret.count != 1 || strcmp(getDatosDefondo_ret.message, "PRUEBA") != 0 ||
                dd1.count != 1 || strcmp(dd1.message, "PRUEBA") != 0)
        {
            std::cout << "TEST FAILED<getDatosDef>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getDatosDef>: " << ex.what() << std::endl;
        _exit(-1);
    }

    DatosDefondo_finalize(&dd1);    
    DatosDefondo_finalize(&dd2);    
    DatosDefondo_finalize(&getDatosDefondo_ret);    

    cadena  c1  = DDS::String_dup("PRUEBA");       
    cadena  c2  = NULL;    
    cadena  getCadena_ret  = NULL;       

    try
    {
        getCadena_ret = proxy->getCadena(c1, c2);

        if(strcmp(c2, "PRUEBA") != 0 ||
                strcmp(getCadena_ret, "PRUEBA") != 0 ||
                strcmp(c1, "PRUEBA") != 0)
        {
            std::cout << "TEST FAILED<getCadena>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getCadena>: " << ex.what() << std::endl;
        _exit(-1);
    }

    if(c1 != NULL) DDS::String_free(c1);    
    if(c2 != NULL) DDS::String_free(c2);    
    if(getCadena_ret != NULL) DDS::String_free(getCadena_ret);    

    correa  cc1  = DDS::String_dup("PRUEBA");       
    correa  cc2  = NULL;    
    correa  getCorrea_ret  = NULL;       

    try
    {
        getCorrea_ret = proxy->getCorrea(cc1, cc2);

        if(strcmp(cc2, "PRUEBA") != 0 ||
                strcmp(getCorrea_ret, "PRUEBA") != 0 ||
                strcmp(cc1, "PRUEBA") != 0)
        {
            std::cout << "TEST FAILED<getCadena>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getCadena>: " << ex.what() << std::endl;
        _exit(-1);
    }

    if(cc1 != NULL) DDS::String_free(cc1);    
    if(cc2 != NULL) DDS::String_free(cc2);    
    if(getCorrea_ret != NULL) DDS::String_free(getCorrea_ret); 

    std::cout << "TEST SUCCESFULLY" << std::endl;

    delete proxy;
    delete transport;
    delete protocol;

    _exit(0);
    return 0;
}
