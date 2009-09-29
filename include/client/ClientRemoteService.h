#ifndef _CLIENTREMOTESERVICE_H_
#define _CLIENTREMOTESERVICE_H_

#include "ndds/ndds_cpp.h"

#include "utils/RemoteServiceWriter.h"
#include "utils/RemoteServiceReader.h"
#include "utils/DDSCSMessages.h"

class ClientRemoteService
{
    public:

        /**
         * \brief The constructor.
         *
         * \param remoteServiceName The name of this service. Cannot be NULL.
         * \param requestTypeName The name of the type used to send the function's parameters. Max: 49 characteres. Cannot be NULL.
         * \param replyTypeName The name of the type used to received the function's return values. Max: 49 characteres. Cannot be NULL.
         * \param clientParticipant Pointer to the domain participant used by the client. Cannot be NULL.
         */
        ClientRemoteService(const char *remoteServiceName, long clientId, const char *requestTypeName, const char *replyTypeName, DDSDomainParticipant *clientParticipant);

        virtual ~ClientRemoteService();

        /**
         */
        DDSCSMessages execute(void *data, int timeout);

        /**
         * 
         */
        int getServerReply(void *requestData, void *replyData);

    private:

        /**
         * \brief This field stores the name of the service.
         */
        char m_remoteServiceName[50];

        /**
         * \brief The publisher used to communicate with the server. Client -> Server
         */
        DDSPublisher *m_requestPublisher;

        /**
         * \brief The subscriber used to communicate with the server. Server -> Client.
         */
        DDSSubscriber *m_replySubscriber;

        /**
         * \brief The topic used to communicate with the server. Client -> Server
         */
        DDSTopic *m_requestTopic;

        /**
         * \brief The topic used to communicate with the server. Server -> Client
         */
        DDSTopic *m_replyTopic;

        /**
         * \brief The data writer used to communicate with the server. Client -> Server
         */
        RemoteServiceWriter *m_requestDataWriter;
        
        /**
         * \brief The data reader used to communicate with the server. Server -> Client
         */
        RemoteServiceReader *m_replyDataReader;

        /**
         * \brief The read condition used to receive server's replies.
         */
        DDSCondition *m_replyCondition;

        /**
         * \brief The waitset used to receive server replies.
         */
        DDSWaitSet *m_replyWaitset;

        /**
         * \brief This function initialize the condition and waitset used to received server communications.
         *
         * \return If the function works successful then returns 0. In other case -1 is returned.
         */
        int createConditionAndWaitset();

        DDS_InstanceHandle_t m_requestInstanceHandle;

        DDSContentFilteredTopic *m_replyFilter;

        unsigned long m_numSec;

};
#endif // _CLIENTREMOTESERVICE_H_