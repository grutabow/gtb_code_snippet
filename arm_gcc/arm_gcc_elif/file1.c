
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

typedef union 
{
    unsigned char Data[32];
    
    struct 
    {
        unsigned char jump[3];
        unsigned short sectors;
        unsigned int signature;
    } __attribute__((packed)) BootSector;
} USector;

USector gSector = {
    .BootSector = {{0xaa, 0xbb, 0xcc}, 0x3232, 0x11ff99cc}
};


typedef struct __attribute__((packed))
{
    unsigned char a;
    unsigned short b;
    unsigned int c;
} Partition;

Partition gpp = {0xfc, 0x1234, 0x88776655};

iotx_mc_client_t my_client = {1, 2, 3};

char * sit_still __attribute__((aligned(32),section("dsp_visible1")));

int why_not;

char big_array1[16] = {0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 
                       0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20};
char small_array[2];
char big_array2[5] = {0x31, 0x32, 0x33, 0x34, 0x35};


__attribute__((aligned(16))) unsigned int g_aligned_word = 0xd4c3b2a1;



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

void show_number(unsigned int n)
{
    
}


int IOT_MQTT_Unsubscribe(void *handle, const char *topic_filter)
{
    pointer_sanity_check(handle, NULL_VALUE_ERROR);
    string_ptr_sanity_check(topic_filter, NULL_VALUE_ERROR);

    //return iotx_mc_unsubscribe((iotx_mc_client_t *)handle, topic_filter);
    return 0;
}

int IOT_MQTT_Publish(void *handle, const char *topic_name,
                     iotx_mqtt_topic_info_pt topic_msg)
{
    pointer_sanity_check(handle, NULL_VALUE_ERROR);
    string_ptr_sanity_check(topic_name, NULL_VALUE_ERROR);

    //return iotx_mc_publish((iotx_mc_client_t *)handle, topic_name, topic_msg);
    return 1;
}


void visit_sector()
{
    unsigned int __attribute__((aligned(1))) *p1 = &gpp.c;
    unsigned int *p2 = &gpp.c;
    show_number(*p1 + 1);
    show_number(*p2 + 2);
    for(int i=0;i<10;i++) gpp.c++;
    show_number(gpp.c);
}


int sit_still2 __attribute__((section("dsp_visible1")));


#ifdef AAA222
int here_scheoo(int a)
{
    return a+1;
}
#elif BBB333
int there_too(int b)
{
    return b+3;
}
#else
int way_out(int c)
{
    return c-2;
}
#endif


