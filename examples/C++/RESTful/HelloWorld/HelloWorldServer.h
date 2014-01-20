/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this RPCDDS distribution.
 *
 *************************************************************************
 * 
 * @file HelloWorldServer.h
 * This header file contains the declaration of the server for all interfaces.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _HelloWorldSERVER_H_
#define _HelloWorldSERVER_H_

#include "rpcdds/server/Server.h"
#include "HelloWorldServerImpl.h"

namespace eprosima
{
    namespace rpcdds
    {
        namespace protocol
        {
            class HelloWorldProtocol;
        }
    }
}

namespace HelloWorld
{
    /**
     * \brief This class implements a specific server for the defined interface HelloWorldResource by user.
     */
    class RPCDDSUSERDllExport HelloWorldResourceServer : public eprosima::rpcdds::server::Server
    {
        public:

            /**
             * \brief This constructor sets the transport that will be used by the server.
             *
             * \param strategy Strategy used by server to work with new requests.
             *        This class doesn't delete this object in its destructor. Cannot be NULL.
             * \param transport The network transport that the server has to use.
             *        This transport's object is not deleted by this class in its destructor. Cannot be NULL.
             * \param protocol Generated protocol that the server has to use.
             *        This class has the information to process requests and build responses for this application environment. 
             * \param servant Servant that the server will use to invoke user's functions.
             * \exception eProsima::RPCDDS::InitializeException This exception is thrown when the initialization was wrong.
             */
            HelloWorldResourceServer(eprosima::rpcdds::strategy::ServerStrategy &strategy, eprosima::rpcdds::transport::ServerTransport &transport,
                eprosima::rpcdds::protocol::HelloWorldProtocol &protocol, HelloWorldResourceServerImpl &servant);

            /// \brief The default destructor.
            virtual ~HelloWorldResourceServer();





            
         private:
            
            /// \brief Pointer to the server's servant implemented by the user.
            HelloWorldResourceServerImpl &_impl;
    };

};


#endif // _HelloWorldSERVER_H_
