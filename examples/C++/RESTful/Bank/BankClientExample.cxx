/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this RPCDDS distribution.
 *
 *************************************************************************
 * 
 * @file BankClientExample.cxx
 * This source file shows a simple example of how to create a proxy for an interface.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "BankProxy.h"
#include "BankRESTProtocol.h"
#include "rpcdds/transports/HttpProxyTransport.h"
#include "rpcdds/exceptions/Exceptions.h"

#include <iostream>

using namespace eprosima::rpcdds;
using namespace eprosima::rpcdds::exception;
using namespace eprosima::rpcdds::transport;
using namespace eprosima::rpcdds::protocol::rest;

int main(int argc, char **argv)
{
    BankProtocol *protocol = NULL;
    ProxyTransport *transport = NULL;
    Bank::account_accountNumberResourceProxy *proxy = NULL;
    
    // Creation of the proxy for interface "Bank::account_accountNumberResource".
    try
    {
        protocol = new BankProtocol();
        transport = new HttpProxyTransport("127.0.0.1:8080");
        proxy = new Bank::account_accountNumberResourceProxy(*transport, *protocol);
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }
    
    // Create and initialize parameters.
    Bank::account_accountNumber account_accountNumber;
    char*  user = NULL;
    Bank::GetAccountDetailsRequest GetAccountDetailsRequest;
    Bank::account_accountNumber_initialize(&account_accountNumber);
    Bank::GetAccountDetailsRequest_initialize(&GetAccountDetailsRequest);

	account_accountNumber.accountNumber_ = 12345;
	user = strdup("User");
	GetAccountDetailsRequest._d = 1;
	GetAccountDetailsRequest._u.xmlRepresentation = strdup("<Password>passwd1234</Password>");

    // Create and initialize return value.
    Bank::GetAccountDetailsResponse getAccountDetails_ret;
    Bank::GetAccountDetailsResponse_initialize(&getAccountDetails_ret);

    // Call to remote procedure "getAccountDetails".
    try
    {
        getAccountDetails_ret = proxy->getAccountDetails(account_accountNumber, user, GetAccountDetailsRequest);
		if(getAccountDetails_ret._d == 1) {
			std::cout << getAccountDetails_ret._u.xmlGetAccountDetailsResponse.xmlRepresentation << endl;
		}
    }
    catch(SystemException &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    
    Bank::account_accountNumber_finalize(&account_accountNumber);
    if(user != NULL) free(user);
    Bank::GetAccountDetailsRequest_finalize(&GetAccountDetailsRequest);

    Bank::GetAccountDetailsResponse_finalize(&getAccountDetails_ret);
    
    delete(proxy);
    delete(transport);
    delete(protocol);
   
    return 0;
}






