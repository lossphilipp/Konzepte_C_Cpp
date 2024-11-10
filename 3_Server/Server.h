#pragma once
#include <stdlib.h>

void Initialize();
void Subscribe(void (*func)());
void Unsubscribe(void (*func)());
void SendMessage(char message[]);