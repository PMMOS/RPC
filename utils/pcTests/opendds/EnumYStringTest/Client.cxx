/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file Client.cxx
 * This source file shows a simple example of how to create a proxy for interface EnumYStringTest.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "EnumYStringTestProxy.h"
#include "EnumYStringTestRequestReplyTypeSupportImpl.h"
#include "exceptions/Exceptions.h"

#include <iostream>

int main(int argc, char **argv)
{
    EnumYStringTestProxy *proxy = NULL;
    
    // Creation of the proxy for interface "EnumYStringTest".
    try
    {
        proxy = new EnumYStringTestProxy("EnumYStringTestService", 0, 30000L);
    }
    catch(eProsima::RPCDDS::InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }

    // Create and initialize parameters.
    Valores  v1 = VALOR1;
    Valores  v2 = VALOR2;
    Valores  v3 = VALOR1;

    // Create and initialize return value.
    Valores  getEnum_ret = VALOR1;

    // Call to remote procedure "getEnum".
    try
    {
        getEnum_ret = proxy->getEnum(v1, v2, v3);

        if(v3 != VALOR2 ||
                getEnum_ret != VALOR1 ||
                v2 != VALOR1 ||
                v1 != VALOR1)
        {
            printf("TEST FAILED<getEnum>: Wrong values\n");
            _exit(-1);
        }       
    }
    catch(eProsima::RPCDDS::Exception &ex)
    {
        printf("TEST FAILED<getEnum>: %s\n", ex.what());
        _exit(-1);
    }

    char*  s1  = strdup("PRUEBA");       
    char*  s2  = strdup("PRUEBA2");       
    char*  s3  = NULL;    
    char*  getStringRetValue = NULL;       

    try
    {
        getStringRetValue = proxy->getString(s1, s2, s3);

        if(strcmp(s3, "PRUEBA2") != 0 ||
                strcmp(getStringRetValue, "PRUEBA") != 0 ||
                strcmp(s2, "PRUEBAPRUEBA2") != 0 ||
                strcmp(s1, "PRUEBA") != 0)
        {
            printf("TEST FAILED<getString>: Wrong values\n");
            _exit(-1);
        }       
    }
    catch(eProsima::RPCDDS::Exception &ex)
    {
        printf("TEST FAILED<getString>: %s\n", ex.what());
        _exit(-1);
    }

    if(s1 != NULL) free(s1);    
    if(s2 != NULL) free(s2);    
    if(s3 != NULL) free(s3);    
    if(getStringRetValue != NULL) free(getStringRetValue);    

    char*  sb1  = strdup("PRUEBA");       
    char*  sb2  = strdup("PRUEBA2");       
    char*  sb3  = NULL;    
    char*  getStringBoundedRetValue = NULL;       

    try
    {
        getStringBoundedRetValue = proxy->getStringBounded(sb1, sb2, sb3);

        if(strcmp(sb3, "PRUEBA2") != 0 ||
                strcmp(getStringBoundedRetValue, "PRUEBA") != 0 ||
                strcmp(sb2, "PRUEBAPRUEBA2") != 0 ||
                strcmp(sb1, "PRUEBA") != 0)
        {
            printf("TEST FAILED<getStringBounded>: Wrong values\n");
            _exit(-1);
        }    
    }
    catch(eProsima::RPCDDS::Exception &ex)
    {
        printf("TEST FAILED<getStringBounded>: %s\n", ex.what());
        _exit(-1);
    }

    if(sb1 != NULL) free(sb1);    
    if(sb2 != NULL) free(sb2);    
    if(sb3 != NULL) free(sb3);    
    if(getStringBoundedRetValue != NULL) free(getStringBoundedRetValue);

    printf("TEST SUCCESFULLY\n");

    delete(proxy);
   
    _exit(0);

    return 0;
}
