#ifndef _TypedefTestSKELETON_H_
#define _TypedefTestSKELETON_H_

/** 
 * Generated by DDSCS: Do not edit.  Version 1.0 *
 */

#include "server/Server.h"
#include "TypedefTestServerImpl.h"
#include "TypedefTestRequestReplyUtils.h"

/**
 * \brief This class implements a specific server for the defined interface by user.
 */
class TypedefTestServerH : public eProsima::DDSRPC::Server
{
    private: 
      TypedefTestServerImpl *_impl;
    public:

        /**
         * \brief Default constructor. The server has to know what network transport
         *        it should use.
         *
         * \param strategy Strategy used by server to work with new requests. Cannot be NULL.
         * \param transport The network transport that server has to use. Cannot be NULL.
         * \param domainId The DDS domain that DDS will use to work. Default value: 0
         */
        TypedefTestServerH(eProsima::DDSRPC::ServerStrategy *strategy, eProsima::DDSRPC::Transport *transport,
            int domainId = 0);

        /// \brief The default destructor.
        virtual ~TypedefTestServerH();

        static void getLargo(eProsima::DDSRPC::Server *server, void *requestData, eProsima::DDSRPC::ServerRPC *service);
        static void getLarguisimo(eProsima::DDSRPC::Server *server, void *requestData, eProsima::DDSRPC::ServerRPC *service);
        static void getDatosDef(eProsima::DDSRPC::Server *server, void *requestData, eProsima::DDSRPC::ServerRPC *service);
        static void getDatosDefondo(eProsima::DDSRPC::Server *server, void *requestData, eProsima::DDSRPC::ServerRPC *service);
        static void getCadena(eProsima::DDSRPC::Server *server, void *requestData, eProsima::DDSRPC::ServerRPC *service);
        static void getCorrea(eProsima::DDSRPC::Server *server, void *requestData, eProsima::DDSRPC::ServerRPC *service);
};

/**
 * \brief This class implements a specific server for the defined interface by user.
 *        This server uses the UDPv4 transport.
 */
class TypedefTestServer : public TypedefTestServerH
{
    public:

        /**
         * \brief Default constructor.
         *
         * \param strategy Strategy used by server to work with new requests. Cannot be NULL.
         * \param domainId The DDS domain that DDS will use to work. Default value: 0
         */
        TypedefTestServer(eProsima::DDSRPC::ServerStrategy *strategy,
            int domainId = 0);

        /// \brief The default destructor.
        virtual ~TypedefTestServer();
};

/**
 * \brief This class implements a specific server for the defined interface by user.
 *        This server uses the TCPv4 transport.
 */
class TypedefTestWANServer : public TypedefTestServerH
{
    public:

        /**
         * \brief Default constructor.
         *
         * \param strategy Strategy used by server to work with new requests. Cannot be NULL.
         * \param public_address Public address and port of the server. The server should be accesible in this address.
         *        The user has to configure its router for this purpose. By example: "218.18.3.133:7600"      *
         * \param server_bind_port Port used by the server in its machine. This port will be use in the router for port forwarding
         *        between the public port and this port.
         * \param domainId The DDS domain that DDS will use to work. Default value: 0
         */
        TypedefTestWANServer(eProsima::DDSRPC::ServerStrategy *strategy, 
            const char *public_address, const char *server_bind_port,
            int domainId = 0);

        /// \brief The default destructor.
        virtual ~TypedefTestWANServer();
};

#endif // _TypedefTestSKELETON_H_