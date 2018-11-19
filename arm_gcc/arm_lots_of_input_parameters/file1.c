
#include <string.h>

#define NULL_VALUE_ERROR  2

typedef struct
{
    int dummy;
    char a;
    int b;
} iotx_mc_client_t;

typedef struct
{
    char * topic;
    int size;
}iotx_mqtt_topic_info_pt;



iotx_mc_client_t my_client = {1, 2, 3};

char * sit_still __attribute__((aligned(32),section("dsp_visible1")));

int why_not;

char big_array1[16] = {0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 
                       0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20};
char small_array[2];
char big_array2[8] = {0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38};


#pragma arm section code = "bcode1"


void pointer_sanity_check(void *x, int e)
{
    char * p = (char *)x;
    why_not += *p;
}

int string_ptr_sanity_check(const char * s, int e)
{
    if( why_not > 360 )
        e += s[0] << 2;
    return e;
}

char* use_std_f(char *ft, char* in, int c)
{
    ft[0] = '0' + c;
    ft[1] = 0;
    return strcat(ft, in);
}

int lot_param(char a, char b, char c, char d, char e, char f, char g)
{
    return a+b+c+d+e+f+g;
}

int IOT_MQTT_Unsubscribe(void *handle, const char *topic_filter)
{
    pointer_sanity_check(handle, NULL_VALUE_ERROR);
    string_ptr_sanity_check(topic_filter, NULL_VALUE_ERROR);

    //return iotx_mc_unsubscribe((iotx_mc_client_t *)handle, topic_filter);
    return 3;
}

int IOT_MQTT_Publish(void *handle, const char *topic_name,
                     iotx_mqtt_topic_info_pt topic_msg)
{
    int ret;
    pointer_sanity_check(handle, NULL_VALUE_ERROR);
    string_ptr_sanity_check(topic_name, NULL_VALUE_ERROR);

    //return iotx_mc_publish((iotx_mc_client_t *)handle, topic_name, topic_msg);
    ret = lot_param(1, 2, 3, 4, 5, 6, topic_name[0]);
    return ret;
}



int sit_still2 __attribute__((section("dsp_visible1")));







