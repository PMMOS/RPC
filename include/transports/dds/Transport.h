/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************/
#ifndef _TRANSPORTS_DDS_TRANSPORT_H_
#define _TRANSPORTS_DDS_TRANSPORT_H_

#include "rpcdds_dll.h"
#include "utils/dds/Middleware.h"

namespace eprosima
{
    namespace rpcdds
    {
        namespace protocol
        {
            class Protocol;
        }

        namespace transport
        {
            class Endpoint;

            namespace dds
            {
                /*!
                 * @brief This class is the base of all classes that implement a transport
                 * using DDS. This transport could be used by both proxies and servers.
                 * @ingroup TRANSPORTMODULE
                 */
                class RPCDDS_DllAPI Transport
                {
                    public:

                        typedef void (*Initialize_data)(void *data);
                        typedef void (*Copy_data)(void *src, void *dst);
                        typedef void (*Finalize_data)(void *data);
                        typedef void (*ProcessFunc)(eprosima::rpcdds::protocol::Protocol&, void*,
                                eprosima::rpcdds::transport::Endpoint*);

                        /*!
                         * @brief Default destructor.
                         */
                        virtual ~Transport();

		                /*!
						 * @brief Initializes all the DDS elements: creates the topic, the participant, the publisher and the subscriber.
						 */
                        void initialize();

		                /*!
						 * @brief Gets the domain participant.
						 * @return DDS domain participant.
						 */
                        inline
                            DDS::DomainParticipant* getParticipant() const
                            {
                                return m_participant;
                            }

		                /*!
						 * @brief Gets the publisher.
						 * @return DDS publisher.
						 */
                        inline
                            DDS::Publisher* getPublisher() const
                            {
                                return m_publisher;
                            }

		                /*!
						 * @brief Gets the subscriber.
						 * @return DDS subscriber.
						 */
                        inline
                            DDS::Subscriber* getSubscriber() const
                            {
                                return m_subscriber;
                            }

                        /*!
                         * @brief This function creates a new procedure endpoint.
                         * This proxy procedure endpoint manages the DDS datawriter and the DDS datareader.
                         *
                         * @param name The name associated with this proxy procedure endpoint.It cannot be NULL.
                         * @param writertypename The type name of the topic that the procedure endpoint uses in the datawriter. It cannot be NULL.
                         * @param readertypename The type name of the topic that the procedure endpoint uses in the datareader. It cannot be NULL.
                         * @return 0 if the function ends successfully, -1 otherwise.
                         */
                        virtual eprosima::rpcdds::transport::Endpoint*
                            createProcedureEndpoint(const char *name, const char *writertypename, const char *readertypename,
                                Initialize_data initialize_data, Copy_data copy_data, Finalize_data finalize_data,
                                ProcessFunc processFunc, int dataSize) = 0;

                    protected:

						/*!
                         * @brief This abstract function sets the QoS to use a specific transport.
                         *
                         * @param participantQos Reference to the DDS domain participant QoS.
                         * @param participant The domain participant that will be set to use a specific transport.
                         */
                        virtual int setTransport(DDS::DomainParticipantQos &participantQos, DDS::DomainParticipant *participant) = 0;

                        /*!
                         * @brief Default constructor.
                         * @param domainId Optional parameter that specifies the domain identifier that will be used in DDS.
                         */
                        Transport(int domainId = 0);

                    private:

                        //! \brief The domain identifier that will be used in DDS.
                        int m_domainId;

                        /*!
                         * @brief A DDS transport that uses a DDS::DomainParticipant entity to create DDS entities.
                         * This participant has to be created during the transport creation.
                         * This pointer should never be NULL.
                         */
                        DDS::DomainParticipant *m_participant;

                        /*!
                         * @brief DDS::Publisher entity used to create DDS::DataWriter entities.
                         * This publisher has to be created in the transport creation.
                         * This pointer should never be NULL.
                         */
                        DDS::Publisher *m_publisher;

                        /*!
                         * @brief DDS::Subscriber entity used to create DDS::DataReader entities.
                         * This subscriber has to be created in the transport creation.
                         * This pointer should never be NULL.
                         */
                        DDS::Subscriber *m_subscriber;
                };
            } // namespace dds
        } // namespace transport
    } // namespace rpcdds
} // namespace eprosima

#endif // _TRANSPORTS_DDS_TRANSPORT_H_
