/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************/

#include "rpcdds/transports/TCPProxyTransport.h"
#include "rpcdds/exceptions/ServerNotFoundException.h"

#include "boost/asio.hpp"
#include "boost/array.hpp"
#include <iostream>

using namespace std;

namespace eprosima { namespace rpcdds { namespace transport {
    class TCPProxyTransportBoost
    {
        public:

            TCPProxyTransportBoost() : io_service_(NULL), socket_(NULL),
            resolver_(NULL)
            {
                io_service_ = new boost::asio::io_service();
                socket_ = new boost::asio::ip::tcp::socket(*io_service_);
                resolver_ = new boost::asio::ip::tcp::resolver(*io_service_);
            }

            ~TCPProxyTransportBoost()
            {
                if(resolver_ != NULL)
                    delete resolver_;
                if(socket_ != NULL)
                    delete socket_;
                if(io_service_)
                    delete io_service_;
            }

            boost::asio::io_service *io_service_;
            boost::asio::ip::tcp::socket *socket_;
            boost::asio::ip::tcp::resolver *resolver_;
            boost::asio::ip::tcp::resolver::iterator endpoint_iterator_;
    };
}}}

using namespace eprosima::rpcdds;
using namespace ::transport;

TCPProxyTransport::TCPProxyTransport(const std::string &serverAddress) : m_boostInfo(NULL)
{
	string host = "127.0.0.1";
	string port = "80";
	if (serverAddress.size() > 0) {
		size_t index = serverAddress.find(':', 1);
		host = serverAddress.substr(0, index);
		if(index != string::npos)
			port = serverAddress.substr(index + 1, serverAddress.size());
	}
    m_boostInfo = new TCPProxyTransportBoost();
	boost::asio::ip::tcp::resolver::query query(boost::asio::ip::tcp::v4(), host, port);
    m_boostInfo->endpoint_iterator_ = m_boostInfo->resolver_->resolve(query);
	serverAddress_ = host;
}

TCPProxyTransport::TCPProxyTransport(const std::string &serverAddress, const std::string &serverPort) :
    m_boostInfo(NULL)
{
    m_boostInfo = new TCPProxyTransportBoost();
	boost::asio::ip::tcp::resolver::query query(boost::asio::ip::tcp::v4(), serverAddress, serverPort);
	m_boostInfo->endpoint_iterator_ = m_boostInfo->resolver_->resolve(query);
	serverAddress_ = serverAddress;
}

TCPProxyTransport::~TCPProxyTransport()
{
    if(m_boostInfo != NULL)
    {
        if(m_boostInfo->socket_->is_open())
        {
            m_boostInfo->socket_->close();
        }

        delete m_boostInfo;
    }
}

bool TCPProxyTransport::connect()
{
    if(!m_boostInfo->socket_->is_open())
    {
        boost::system::error_code error = boost::asio::error::host_not_found;
        boost::asio::ip::tcp::resolver::iterator end_;

        if(m_boostInfo->endpoint_iterator_ != end_)
        {
            m_boostInfo->socket_->connect(*m_boostInfo->endpoint_iterator_, error);
        }

        if (error)
        {
            throw eprosima::rpcdds::exception::ServerNotFoundException("ERROR<TCPProxyTransport::connect>: "+error.message());
        }
    }
	return true;
}

bool TCPProxyTransport::send(const void* buffer, const size_t bufferSize)
{
	boost::system::error_code error = boost::system::error_code();
    const char *buff = (const char*)buffer;

    if(buff != NULL)
    {
        size_t bytes_sent = 0;
        bytes_sent = boost::asio::write(*m_boostInfo->socket_, boost::asio::buffer(buff, bufferSize),
                boost::asio::transfer_all(), error);
        if (bytes_sent != 0)
        {
            return true;
        }
        else
            std::cout << "Error sending data" << std::endl;

    }
    else
    {
        // TODO print error.
    }

	return false;
}

// dataToRead == 0 -> es bloqueante
// 0 OK
// 1 Connection close
// -1 ERROR
int TCPProxyTransport::receive(void *buffer, const size_t bufferSize, size_t &dataToRead)
{
    boost::system::error_code ec = boost::system::error_code();

    if(buffer != NULL && bufferSize > 0)
    {
        // TODO Chequear durante un tiempo hasta que numData sea mayor que cero. Podria ser que la primera llamada solo devolviera 0.
        
        // Check the space in the buffer.
        if(bufferSize < dataToRead)
        {
            dataToRead = 0;
            return -1;
        }

        // TODO check ec.
        if(dataToRead > 0)
        {
            // TODO Chequear durante un tiempo hasta que numData sea mayor que cero. Podria ser que la primera llamada solo devolviera 0.
            dataToRead = boost::asio::read(*m_boostInfo->socket_, boost::asio::buffer(buffer, dataToRead), ec);
        }
        else
        {
            dataToRead = m_boostInfo->socket_->read_some(boost::asio::buffer(buffer, bufferSize), ec);
        }

        if(ec != boost::asio::error::eof)
            return 0;
        else
            return 1;
    }

    return -1;
}
