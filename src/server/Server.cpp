/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************/

#include "rpcdds/server/Server.h"
#include "rpcdds/exceptions/InitializeException.h"
#include "rpcdds/strategies/ServerStrategy.h"
#include "rpcdds/transports/ServerTransport.h"
#include "rpcdds/protocols/Protocol.h"

#include "boost/config/user.hpp"
#include "boost/thread.hpp"

static const char* const CLASS_NAME ="eprosima::rpcdds::server::Server";

using namespace eprosima::rpcdds;
using namespace ::server;
using namespace ::strategy;
using namespace ::transport;
using namespace ::protocol;
using namespace ::exception;

Server::Server(ServerStrategy &strategy, ServerTransport &transport, Protocol &protocol) :
    m_strategy(strategy), m_transport(transport), m_protocol(protocol)
{
    const char* const METHOD_NAME ="Server";
    std::string errorMessage;

    if(protocol.setTransport(transport))
    {
        transport.setStrategy(strategy);
        transport.linkProtocol(protocol);
        return;
    }
    else
    {
        errorMessage = "Cannot bind protocol with the transport";
    }

    printf("ERROR<%s::%s>: %s\n", CLASS_NAME, METHOD_NAME, errorMessage.c_str());
    throw InitializeException(std::move(errorMessage));
}

Server::~Server()
{
}

void Server::serve()
{
    const char* const METHOD_NAME = "server";
    m_transport.run();
    printf("INFO<%s::%s>: Server is running\n", CLASS_NAME, METHOD_NAME);	
}

void Server::stop()
{
    const char* const METHOD_NAME = "stop";
    printf("INFO<%s::%s>: Server is stopped\n", CLASS_NAME, METHOD_NAME);
}
