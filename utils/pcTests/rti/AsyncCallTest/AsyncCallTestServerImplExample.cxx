/** 
 * Generated by RPCDDS                                              *
 * Empty interface implementation to be filled with your own code.  *
 */
 
#include "AsyncCallTestServerImplExample.h"

#include "ndds/ndds_namespace_cpp.h"
 
DDS_Long AsyncCallTestServerImplExample::getLong(/*in*/ DDS_Long lo1, /*inout*/ DDS_Long& lo2, /*out*/ DDS_Long& lo3) 
{
    DDS_Long  getLong_ret = 0;    

    lo3 = lo2;
    getLong_ret = lo1;
    lo2 = lo1 + lo2;
   
    return getLong_ret;
} 
 
DDS_Boolean AsyncCallTestServerImplExample::getBoolean(/*in*/ DDS_Boolean bo1, /*inout*/ DDS_Boolean& bo2, /*out*/ DDS_Boolean& bo3) 
{
    DDS_Boolean  getBoolean_ret = RTI_FALSE;    

    bo3 = bo2;
    getBoolean_ret = bo1;
    bo2 = bo1 | bo2;
   
    return getBoolean_ret;
} 
 
char* AsyncCallTestServerImplExample::getString(/*in*/ char* s1, /*inout*/ char*& s2, /*out*/ char*& s3) 
{
    char*  getString_ret = NULL;    

    s3 = DDS::String_dup(s2);
    getString_ret = DDS::String_dup(s1);
    DDS::String_free(s2);
    s2 = DDS::String_alloc(strlen(s1) + strlen(s3) + 1);
#if defined(RTI_WIN32)
    _snprintf(s2, strlen(s1) + strlen(s3) + 1, "%s%s", s1, s3);
#elif defined(RTI_LINUX)
    snprintf(s2, strlen(s1) + strlen(s3) + 1, "%s%s", s1, s3);
#endif
   
    return getString_ret;
} 
 
Structure AsyncCallTestServerImplExample::duplicate(/*in*/ const Structure& ev) 
{
    Structure duplicate_ret;
        
	duplicate_ret.dato = ev.dato;
	duplicate_ret.message = DDS::String_dup(ev.message);
   
    return duplicate_ret;
} 
