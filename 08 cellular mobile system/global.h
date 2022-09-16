#ifndef GLOBAL_H
#define GLOBAL_H
#include <stdbool.h>

typedef struct datacall
{
    long long int callingNumber;
    long long int calledNumber;
    long long int packetNumber;
}dataCall;

typedef struct voicecall
{
    long long int callingNumber;
    long long int calledNumber;
    bool callerID;
    bool roaming;
}voiceCall;

typedef struct emergencycall
{
    long long int callingNumber;
    long long int calledNumber;
}emergencyCall;

typedef struct call
{
    char type;
    union
    {
        dataCall data;
        voiceCall voice;
        emergencyCall emergency;
    } info;
}Call;

typedef Call listEntry;

#endif