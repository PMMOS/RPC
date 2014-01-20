/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file CalculatorAsyncSupport.h
 * This header file contains functionality to use asynchronous calls for interface Calculator.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _Calculator_ASYNC_SUPPORT_H_
#define _Calculator_ASYNC_SUPPORT_H_

#include "client/AsyncTask.h"


/**
 * \brief This class represents a asynchronous task created to wait the reply of the procedure addition from the server in an asynchronous call.
 */
class Calculator_additionTask : public eProsima::RPCDDS::AsyncTask
{
    public:

        /**
         * \brief The default constructor.
         *
         * \param obj Object that implements the callbacks that RPCDDS will call when
         *            the reply will be received or and exception will be launched.
         * \param client Pointer to the server's proxy. Cannot be NULL.
         */
        Calculator_additionTask(Calculator_additionCallbackHandler &obj,
           eProsima::RPCDDS::Client *client);

        /// \brief The default destructor.
        virtual ~Calculator_additionTask();
        
        virtual void execute();
        
        virtual void on_exception(const eProsima::RPCDDS::SystemException &ex);
        
        /**
         * \brief This function returns the object used by the task.
         *
         * \return The object that implements the callbacks.
         */
        Calculator_additionCallbackHandler& getObject();
        
        void* getReplyInstance();
        
        private:
        
           Calculator_additionCallbackHandler &m_obj;
           
           Calculator_additionReply m_reply;
};

/**
 * \brief This class represents a asynchronous task created to wait the reply of the procedure subtraction from the server in an asynchronous call.
 */
class Calculator_subtractionTask : public eProsima::RPCDDS::AsyncTask
{
    public:

        /**
         * \brief The default constructor.
         *
         * \param obj Object that implements the callbacks that RPCDDS will call when
         *            the reply will be received or and exception will be launched.
         * \param client Pointer to the server's proxy. Cannot be NULL.
         */
        Calculator_subtractionTask(Calculator_subtractionCallbackHandler &obj,
           eProsima::RPCDDS::Client *client);

        /// \brief The default destructor.
        virtual ~Calculator_subtractionTask();
        
        virtual void execute();
        
        virtual void on_exception(const eProsima::RPCDDS::SystemException &ex);
        
        /**
         * \brief This function returns the object used by the task.
         *
         * \return The object that implements the callbacks.
         */
        Calculator_subtractionCallbackHandler& getObject();
        
        void* getReplyInstance();
        
        private:
        
           Calculator_subtractionCallbackHandler &m_obj;
           
           Calculator_subtractionReply m_reply;
};

#endif // _Calculator_ASYNC_SUPPORT_H_