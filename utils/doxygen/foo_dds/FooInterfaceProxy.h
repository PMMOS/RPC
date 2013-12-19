/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this RPCDDS distribution.
 *
 *************************************************************************
 * 
 * @file FooInterfaceProxy.h
 * This header file contains the declaration of the proxy for all interfaces.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _FooInterface_PROXY_H_
#define _FooInterface_PROXY_H_

#include "rpcdds/client/Proxy.h"
#include "rpcdds/exceptions/SystemException.h"
#include "rpcdds/exceptions/UserException.h"
#include "rpcdds/utils/dds/Middleware.h"
#include "FooInterface.h"

namespace eprosima
{
    namespace rpcdds
    {
        namespace protocol
        {
            class FooInterfaceProtocol;
        }
    }
}

/*!
 * @brief This abstract class defines the callbacks that RPCDDS will call in an asynchronous call.
 *        These callback has to be implemented in a derived class.
 * @ingroup FOODDSEXAMPLE
 */
class FooInterface_FooProcedureCallbackHandler
{
    public:
        /*!
         * This function is called when is received the reply from the server.
         */
        virtual void FooProcedure() = 0;
        
        /*!
         * @brief This function is called when an exception occurs.
         *        This exception can be launched in the server's side or in the client's side.
         *
         * @param ex The exception that will be launched.
         */
        virtual void on_exception(const eprosima::rpcdds::exception::SystemException &ex) = 0;
};


/*!
 * @brief This class implements a specific server's proxy for the defined interface FooInterface.
 */
class RPCDDSUSERDllExport FooInterfaceProxy : public eprosima::rpcdds::proxy::Proxy
{
    public:
   
        /*!
         * @brief This constructor sets the transport that will be used by the server's proxy.
         *
         * @param transport The network transport that server's proxy has to use.
         *        This transport's object is not deleted by this class in its destructor. Cannot be NULL.
         * @param protocol The protocol used to send the information over the transport.
         *        This protocol's object is not deleted by this class in its destructor. Cannot be NULL.
         * @exception eprosima::rpcdds::exception::InitializeException This exception is thrown when the initialization was wrong.
         */
        FooInterfaceProxy(eprosima::rpcdds::transport::ProxyTransport &transport,
            eprosima::rpcdds::protocol::FooInterfaceProtocol &protocol);

        //! @brief The default destructor.
        virtual ~FooInterfaceProxy();
        
        //! @brief Proxy method for the operation FooProcedure
        void FooProcedure();

        
        ////! @brief Proxy asynchronous method for the operation FooProcedure
        void FooProcedure_async(FooInterface_FooProcedureCallbackHandler &obj);

};


#endif // _FooInterface_PROXY_H_
