
#define diagPrintf(fmt,...)  diagPrintf_Extend(diagTraceDesc, ##__VA_ARGS__)

int wx(int rrg)
{
    diagPrintf("next %d", rrg);
    diagPrintf("oh");
    
    return rrg>>1;
}




    