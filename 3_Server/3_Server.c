#include <stdio.h>
#include "Server.h"

static void Test1(char message[]) {
    printf("Test1\n");
    printf(message);
    printf("\n\n");
}

static void Test2(char message[]) {
    printf("Test2\n");
    printf(message);
    printf("\n\n");
}

static void Test3(char message[]) {
    printf("Test3\n");
    printf(message);
    printf("\n\n");
}

int main()
{
    Initialize();

    Subscribe(Test1);
    SendMessage("This is the first Message");
    SendMessage("This is the second Message");

    Subscribe(Test2);
    SendMessage("This is the third Message");

    return 0;
}