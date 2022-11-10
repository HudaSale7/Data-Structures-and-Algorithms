#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "global.h"

#define DATA 'D'
#define VOICE 'V'
#define EMERGENCY 'E'

int menu();
int main()
{
    List centralList;
    Call myCall;

    int dataCounter = 0;
    int voiceCounter = 0;
    int emergencyCounter = 0;
    int position;

    createList(&centralList);
    while (1)
    {
        int userOption = menu();
        switch (userOption)
        {
        case 1:
            printf("\t - the number of the calling party: ");
            scanf("%d", &myCall.info.data.callingNumber);
            printf("\n\t - the number of the party to be called: ");
            scanf("%d", &myCall.info.data.calledNumber);
            printf("\n\t - the number of packets: ");
            scanf("%d", &myCall.info.data.packetNumber);
            printf("\n\t------------------------------------------------------\n");

            myCall.type = DATA;
            position = listSize(&centralList);
            insertList(position, myCall, &centralList);
            dataCounter++;

            system("pause");
            system("cls");
            break;
        case 2:
            printf("\t - the number of the calling party: ");
            scanf("%d", &myCall.info.voice.callingNumber);
            printf("\n\t - the number of the party to be called: ");
            scanf("%d", &myCall.info.voice.calledNumber);
            printf("\n\t - showing the caller ID (1 or 0)?: ");
            scanf("%d", &myCall.info.voice.callerID);
            printf("\n\t - roaming option (1 or 0)?: ");
            scanf("%d", &myCall.info.voice.roaming);
            printf("\n\t------------------------------------------------------\n");

            myCall.type = VOICE;
            position = voiceCounter + emergencyCounter;
            insertList(position, myCall, &centralList);
            voiceCounter++;

            system("pause");
            system("cls");
            break;
        case 3:
            printf("\t - the number of the calling party: ");
            scanf("%d", &myCall.info.emergency.callingNumber);
            printf("\n\t - the number of the party to be called: ");
            scanf("%d", &myCall.info.emergency.calledNumber);
            printf("\n\t------------------------------------------------------\n");

            myCall.type = EMERGENCY;
            position = emergencyCounter;
            insertList(position, myCall, &centralList);
            emergencyCounter++;

            system("pause");
            system("cls");
            break;
        case 4:
            if (listEmpty(&centralList))
            {
                printf("\t   there are not waiting calls to serve !");
                printf("\n\t------------------------------------------------------\n");
            }
            else
            {
                position = 0;
                deleteList(position, &myCall, &centralList);
                
                switch (myCall.type)
                {
                case DATA:
                    printf("\t   Serving data call\n");
                    printf("\n\t - the number of the calling party: %d", myCall.info.data.callingNumber);
                    printf("\n\t - the number of the party to be called: %d", myCall.info.data.calledNumber);
                    printf("\n\t - the number of packets: %d", myCall.info.data.packetNumber);
                    printf("\n\t------------------------------------------------------\n");
                    dataCounter--;
                    break;
                case VOICE:
                    printf("\t   Serving voice call\n");
                    printf("\n\t - the number of the calling party: %d", myCall.info.voice.callingNumber);
                    printf("\n\t - the number of the party to be called: %d", myCall.info.voice.calledNumber);
                    printf("\n\t - the caller ID: %d", myCall.info.voice.callerID);
                    printf("\n\t - roaming option: %d", myCall.info.voice.roaming);
                    printf("\n\t------------------------------------------------------\n");
                    voiceCounter--;
                    break;
                case EMERGENCY:
                    printf("\t   Serving emergency call\n");
                    printf("\n\t - the number of the calling party: %d", myCall.info.emergency.callingNumber);
                    printf("\n\t - the number of the party to be called: %d", myCall.info.emergency.calledNumber);
                    printf("\n\t------------------------------------------------------\n");
                    emergencyCounter--;
                    break;
                default:
                    break;
                }
            }
            system("pause");
            system("cls");
            break;
        case 5:
            if (listEmpty(&centralList))
            {
                printf("\t   there are not waiting calls to dismiss !");
                printf("\n\t------------------------------------------------------\n");
            }
            else
            {
                retrieveList(listSize(&centralList) - 1, &myCall, &centralList);
                switch (myCall.type)
                {
                case DATA:
                    printf("\t   Dismiss all data calls\n");
                    while (dataCounter)
                    {
                        deleteList(listSize(&centralList) - 1, &myCall, &centralList);
                        printf("\n\t - the number of the calling party: %d", myCall.info.data.callingNumber);
                        printf("\n\t - the number of the party to be called: %d", myCall.info.data.calledNumber);
                        printf("\n\t - the number of packets: %d", myCall.info.data.packetNumber);
                        printf("\n\t------------------------------------------------------\n");
                        dataCounter--;
                    }
                    break;
                case VOICE:
                    printf("\t   Dismiss all voice calls\n");
                    while (voiceCounter)
                    {
                        deleteList(listSize(&centralList) - 1, &myCall, &centralList);
                        printf("\n\t - the number of the calling party: %d", myCall.info.voice.callingNumber);
                        printf("\n\t - the number of the party to be called: %d", myCall.info.voice.calledNumber);
                        printf("\n\t - the caller ID: %d", myCall.info.voice.callerID);
                        printf("\n\t - roaming option: %d", myCall.info.voice.roaming);
                        printf("\n\t------------------------------------------------------\n");
                        voiceCounter--;
                    }
                    break;
                default:
                    printf("\t   there are not waiting calls to dismiss !");
                    printf("\n\t------------------------------------------------------\n");
                    break;
                }
            }
            system("pause");
            system("cls");
            break;
        case 6:
            exit(1);
            break;
        default:
            break;
        }
    }
    return 0;
}

int menu()
{
    int option;
    printf("  Welcome to cellular mobile system\n");
    printf("  1. Data Call coming.\n");
    printf("  2. Voice Call coming.\n");
    printf("  3. Emergency Call coming.\n");
    printf("  4. Serve a call.\n");
    printf("  5. Dismiss calls with least priority.\n");
    printf("  6. Exit.\n");
    printf("  Your option --> ");
    scanf("%d", &option);
    system("cls");
    return option;
}