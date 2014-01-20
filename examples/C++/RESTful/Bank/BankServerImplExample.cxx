/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this RPCDDS distribution.
 *
 *************************************************************************
 * 
 * @file BankServerImplExample.cxx
 * This source file contains an example of the declaration of a servant.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "BankServerImplExample.h"
#include <iostream>

using namespace std;


Bank::GetAccountDetailsResponse account_accountNumberResourceServerImplExample::getAccountDetails(/*in*/ const Bank::account_accountNumber& account_accountNumber, /*in*/ const char* user, /*in*/ const Bank::GetAccountDetailsRequest& GetAccountDetailsRequest)
{
    Bank::GetAccountDetailsResponse getAccountDetails_ret;
    Bank::GetAccountDetailsResponse_initialize(&getAccountDetails_ret);

	cout << "Account number (embedded parameter): " << account_accountNumber.accountNumber_ << endl;
	cout << "User (query parameter): " << user << endl;
	if(GetAccountDetailsRequest._d == 1) {
		cout << "Password (XML body parameter): " << GetAccountDetailsRequest._u.xmlRepresentation << endl;
	}

	getAccountDetails_ret._d = 1;
	getAccountDetails_ret._u.xmlGetAccountDetailsResponse.status = 200;
	getAccountDetails_ret._u.xmlGetAccountDetailsResponse.xmlRepresentation = strdup("<AccountDetails> ... </AccountDetails>");

    return getAccountDetails_ret;
} 


