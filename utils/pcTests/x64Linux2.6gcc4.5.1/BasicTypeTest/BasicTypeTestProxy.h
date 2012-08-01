#ifndef _BasicTypeTest_PROXY_H_
#define _BasicTypeTest_PROXY_H_

/** 
 * Generated by DDSCS: Do not edit.  Version 1.0 *
 */

#include "client/Client.h"
#include "BasicTypeTestRequestReplyUtils.h"
#include "BasicTypeTestClientRPCSupport.h"

class BasicTypeTestProxy : public DDSRPC::Client
{
    public:

        /// \brief The default constructor.
        BasicTypeTestProxy(int domainId = 0, unsigned int timeout = 3000,
        const char *qosLibrary =  "BasicTypeTest_Library", const char *qosProfile = "BasicTypeTest_Profile");

        /// \brief The default destructor.
        virtual ~BasicTypeTestProxy();

        unsigned int getTimeout();
        void setTimeout(unsigned int millis);
        
         
        DDSRPC::ReturnMessage
         getOctet(DDS_Octet oc1 ,DDS_Octet &oc2,DDS_Octet &oc3, DDS_Octet &getOctet_ret);
         
        DDSRPC::ReturnMessage
         getChar(DDS_Char ch1 ,DDS_Char &ch2,DDS_Char &ch3, DDS_Char &getChar_ret);
         
        DDSRPC::ReturnMessage
         getWChar(DDS_Wchar wch1 ,DDS_Wchar &wch2,DDS_Wchar &wch3, DDS_Wchar &getWChar_ret);
         
        DDSRPC::ReturnMessage
         getShort(DDS_Short sh1 ,DDS_Short &sh2,DDS_Short &sh3, DDS_Short &getShort_ret);
         
        DDSRPC::ReturnMessage
         getUShort(DDS_UnsignedShort ush1 ,DDS_UnsignedShort &ush2,DDS_UnsignedShort &ush3, DDS_UnsignedShort &getUShort_ret);
         
        DDSRPC::ReturnMessage
         getLong(DDS_Long lo1 ,DDS_Long &lo2,DDS_Long &lo3, DDS_Long &getLong_ret);
         
        DDSRPC::ReturnMessage
         getULong(DDS_UnsignedLong ulo1 ,DDS_UnsignedLong &ulo2,DDS_UnsignedLong &ulo3, DDS_UnsignedLong &getULong_ret);
         
        DDSRPC::ReturnMessage
         getLLong(DDS_LongLong llo1 ,DDS_LongLong &llo2,DDS_LongLong &llo3, DDS_LongLong &getLLong_ret);
         
        DDSRPC::ReturnMessage
         getULLong(DDS_UnsignedLongLong ullo1 ,DDS_UnsignedLongLong &ullo2,DDS_UnsignedLongLong &ullo3, DDS_UnsignedLongLong &getULLong_ret);
         
        DDSRPC::ReturnMessage
         getFloat(DDS_Float fl1 ,DDS_Float &fl2,DDS_Float &fl3, DDS_Float &getFloat_ret);
         
        DDSRPC::ReturnMessage
         getDouble(DDS_Double do1 ,DDS_Double &do2,DDS_Double &do3, DDS_Double &getDouble_ret);
         
        DDSRPC::ReturnMessage
         getBoolean(DDS_Boolean bo1 ,DDS_Boolean &bo2,DDS_Boolean &bo3, DDS_Boolean &getBoolean_ret);
        
    private:
        DDSRPC::ClientRPC *getOctet_Service;
        DDSRPC::ClientRPC *getChar_Service;
        DDSRPC::ClientRPC *getWChar_Service;
        DDSRPC::ClientRPC *getShort_Service;
        DDSRPC::ClientRPC *getUShort_Service;
        DDSRPC::ClientRPC *getLong_Service;
        DDSRPC::ClientRPC *getULong_Service;
        DDSRPC::ClientRPC *getLLong_Service;
        DDSRPC::ClientRPC *getULLong_Service;
        DDSRPC::ClientRPC *getFloat_Service;
        DDSRPC::ClientRPC *getDouble_Service;
        DDSRPC::ClientRPC *getBoolean_Service; 
        
        unsigned int m_timeout;
};

#endif // _BasicTypeTest_PROXY_H_