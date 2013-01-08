/** 
 * Generated by RPCDDS                                                   *
 * Example client. Method params should be initialized before execution  *
 */

#include "ServerExceptionProxy.h"
#include "ServerExceptionRequestReplyPlugin.h"
#include "exceptions/Exceptions.h"

int main(int argc, char **argv)
{
    ServerExceptionProxy *proxy = new ServerExceptionProxy("ServerExceptionService");

    try
    {
        proxy->sendException();
        printf("TEST FAILED<sendException>: No exception\n");
        _exit(-1);
    }
    catch(eProsima::RPCDDS::ServerInternalException &ex)
    {
        if(strcmp(ex.what(), "Testing exception") != 0)
        {
            printf("TEST FAILED<sendException>: Bad exception message\n");
            _exit(-1);
        }
    }
    catch(eProsima::RPCDDS::Exception &ex)
    {
        printf("TEST FAILED<sendException>: %s\n", ex.what());
        _exit(-1);
    }

    char*  s1  = DDS::String_dup("PRUEBA");       
    char*  s2  = DDS::String_dup("PRUEBA2");       
    char*  s3  = NULL;    
    char*  sendExceptionTwoRetValue = NULL;  

    try
    {
        sendExceptionTwoRetValue = proxy->sendExceptionTwo(s1, s2, s3);
        printf("TEST FAILED<sendExceptionTwo>: No exception\n");
        _exit(-1);
    }
    catch(eProsima::RPCDDS::ServerInternalException &ex)
    {
        if(strcmp(ex.what(), "Testing exception") != 0)
        {
            printf("TEST FAILED<sendExceptionTwo>: Bad exception message\n");
            _exit(-1);
        }
    }
    catch(eProsima::RPCDDS::Exception &ex)
    {
        printf("TEST FAILED<sendExceptionTwo>: %s\n", ex.what());
        _exit(-1);
    }

    Estructura es1;
    Estructura es2;
    Estructura es3;
    Estructura sendExceptionThreeRetValue;

    Estructura_initialize(&es1);
    Estructura_initialize(&es2);

    try
    {
        sendExceptionThreeRetValue = proxy->sendExceptionThree(es1, es2, es3);
        printf("TEST FAILED<sendExceptionThree>: No exception\n");
        _exit(-1);
    }
    catch(eProsima::RPCDDS::ServerInternalException &ex)
    {
        if(strcmp(ex.what(), "Testing exception") != 0)
        {
            printf("TEST FAILED<sendExceptionThree>: Bad exception message\n");
            _exit(-1);
        }
    }
    catch(eProsima::RPCDDS::Exception &ex)
    {
        printf("TEST FAILED<sendExceptionThree>: %s\n", ex.what());
        _exit(-1);
    }

    Estructura_finalize(&es1);
    Estructura_finalize(&es2);

	printf("TEST SUCCESFULLY\n");

    delete(proxy);

	_exit(0);
    return 0;
}
