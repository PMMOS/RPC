/** 
 * Generated by DDSCS                                                    *
 * Example client. Method params should be initialized before execution  *
 */

#include "StructTestProxy.h"
#include "StructTestRequestReplyPlugin.h"

int main()
{
    int domainId = 0;
    unsigned int timeoutInMillis = 4000;
    StructTestProxy *proxy = new StructTestProxy(domainId, timeoutInMillis);
    DDS_Duration_t period = {5,0};
    
    Envio *ev = EnvioPluginSupport_create_data();       
    ev->dato = 10;
    ev->message = "HOLA";
   
    Recepcion *duplicate_ret = RecepcionPluginSupport_create_data();       
    DDSCSMessages  duplicateRetValue;        

    /**
     * Dynamic memory passed to the proxy will be freed before return *
     * Pass a copy if you want to keep it                             *
     */
    duplicateRetValue = proxy->duplicate(*ev    ,*duplicate_ret    );
    printf("%s %d\n", duplicate_ret->message, duplicate_ret->devolucion);

    Envio *ev1 = EnvioPluginSupport_create_data();    
    Envio *ev2 = EnvioPluginSupport_create_data();       
    ev1->dato = 10;
    ev1->message = "HOLA";
    ev2->dato = 20;
    ev2->message = "ADIOS";
   
    Recepcion *suma_ret = RecepcionPluginSupport_create_data();       
    DDSCSMessages  sumaRetValue;        

    /**
     * Dynamic memory passed to the proxy will be freed before return *
     * Pass a copy if you want to keep it                             *
     */
    sumaRetValue = proxy->suma(*ev1    , *ev2    ,*suma_ret    );
    printf("%s %d\n", suma_ret->message, suma_ret->devolucion);


   delete(proxy);
   NDDSUtility::sleep(period);
}
