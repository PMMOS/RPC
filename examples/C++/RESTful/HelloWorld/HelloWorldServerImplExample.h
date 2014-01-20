/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this RPCDDS distribution.
 *
 *************************************************************************
 * 
 * @file HelloWorldServerImplExample.h
 * This header file contains an example of the declaration of a servant.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _HelloWorldSERVER_IMPL_EXAMPLE_H_
#define _HelloWorldSERVER_IMPL_EXAMPLE_H_

#include "HelloWorldServerImpl.h"

/**
 * \brief This class is an example of a servant and it implements the remote procedures of the servant.
 */
class HelloWorldResourceServerImplExample : public HelloWorld::HelloWorldResourceServerImpl
{
    public:

        //! @brief The default constructor.
        HelloWorldResourceServerImplExample(){}

        //! @brief The default destructor.
        virtual ~HelloWorldResourceServerImplExample(){}




        //! @brief Implementation of the remote procedure hello
        HelloWorld::HelloResponse hello(/*in*/ const char* name);
;
};



#endif // _HelloWorldSERVER_IMPL_EXAMPLE_H_