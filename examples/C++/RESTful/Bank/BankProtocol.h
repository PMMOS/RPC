/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this RPCDDS distribution.
 *
 *************************************************************************
 * 
 * @file BankProtocol.h
 * This header file contains the declaration of the interface for all protocols.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _Bank_PROTOCOL_H_
#define _Bank_PROTOCOL_H_

#include "rpcdds/protocols/Protocol.h"
#include "Bank.h"
#include "BankServerImpl.h"
#include "ndds_namespace_cpp.h"

namespace eprosima
{
    namespace rpcdds
    {
        namespace protocol
        {
            /*!
             * @brief Protocol base class for the specific application
             */
            class RPCDDSUSERDllExport BankProtocol : public Protocol
            {
                public:
                
                   /*!
                    * @brief This method sets the transport for the communications. It has to be implemented by the children classes.
                    * @param transport Transport to use.
                    * @return True if the assignment is successful, false otherwise
                    */
                    virtual bool setTransport(eprosima::rpcdds::transport::Transport &transport) = 0;
                    
                    virtual bool activateInterface(const char* interfaceName) = 0;
                    
                                       /*!
                                        * @brief This method links a specific servant with the protocol.
                                        * @param impl Servant implementation.
                                        */
                                        void linkBank_account_accountNumberResourceImpl(Bank::account_accountNumberResourceServerImpl &impl)
                                        {
                                            _Bank_account_accountNumberResource_impl = &impl;
                                        }
                                        
                             





                    /*!
                     * @brief This method implements the proxy part of the protocol for the operation getAccountDetails
                     *        It has to be implemented by the child classes.
                     */
                    virtual Bank::GetAccountDetailsResponse Bank_account_accountNumberResource_getAccountDetails(/*in*/ const Bank::account_accountNumber& account_accountNumber, /*in*/ const char* user, /*in*/ const Bank::GetAccountDetailsRequest& GetAccountDetailsRequest) = 0;


                    
                protected:
                
                    BankProtocol() : Protocol()
                                         
                                        , _Bank_account_accountNumberResource_impl(NULL)
                                        
                    {}
                    
                    virtual ~BankProtocol(){}
                
                	                     
                	                    Bank::account_accountNumberResourceServerImpl *_Bank_account_accountNumberResource_impl;
                	                    
                    
            };
        } // namespace protocol
    } // namespace rpcdds
} // namespace eprosima

#endif // _Bank_PROTOCOL_H_
