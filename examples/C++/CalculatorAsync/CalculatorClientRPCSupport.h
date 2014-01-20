/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file CalculatorClientRPCSupport.h
 * This header file contains the declaration of the proxy's RPC endpoints for interface Calculator.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _Calculator_CLIENT_RPC_SUPPORT_H_
#define _Calculator_CLIENT_RPC_SUPPORT_H_

#include "utils/GenericClientRPC.h"
#include "CalculatorRequestReplySupport.h"


GENERIC_CLIENT_RPC(Calculator_additionClientRPC, Calculator_additionRequestDataWriter, Calculator_additionReplyDataReader);


GENERIC_CLIENT_RPC(Calculator_subtractionClientRPC, Calculator_subtractionRequestDataWriter, Calculator_subtractionReplyDataReader);


#endif  // _Calculator_CLIENT_RPC_SUPPORT_H_