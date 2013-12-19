/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this RPCDDS distribution.
 *
 *************************************************************************
 * 
 * @file FooInterfaceProtocol.h
 * This header file contains the declaration of the interface for all protocols.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _FooInterface_PROTOCOL_H_
#define _FooInterface_PROTOCOL_H_

#include "rpcdds/protocols/Protocol.h"
#include "FooInterface.h"
#include "FooInterfaceServerImpl.h"
#include "ndds_namespace_cpp.h"

namespace eprosima
{
    namespace rpcdds
    {
        namespace protocol
        {
            /*!
             * @brief Protocol base class for the specific application
			 * @ingroup FOODDSEXAMPLE
             */
            class RPCDDSUSERDllExport FooInterfaceProtocol : public Protocol
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
                                        void linkFooInterfaceImpl(FooInterfaceServerImpl &impl)
                                        {
                                            _FooInterface_impl = &impl;
                                        }
                                        
                             
                    /*!
                     * @brief This method implements the proxy part of the protocol for the operation FooProcedure
                     *        It has to be implemented by the child classes.
                     */
                    virtual void FooInterface_FooProcedure() = 0;

                    
                protected:
                
                    FooInterfaceProtocol() : Protocol()
                                         
                                        , _FooInterface_impl(NULL)
                                        
                    {}
                    
                    virtual ~FooInterfaceProtocol(){}
                
                	                     
                	                    FooInterfaceServerImpl *_FooInterface_impl;
                	                    
                    
            };
        } // namespace protocol
    } // namespace rpcdds
} // namespace eprosima

#endif // _FooInterface_PROTOCOL_H_
