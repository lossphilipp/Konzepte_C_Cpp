#include "Server.h"

// WRONG!!! Only memory for one character gets allocated like this!
typedef void (*callback_t)(char message[]);

callback_t* subscribers;
int subscriberCount = 0;

void Subscribe(callback_t callbackFunction) {
	subscribers = (callback_t*)realloc(subscribers, (subscriberCount + 1) * sizeof(callback_t));

	subscribers[subscriberCount] = callbackFunction;
	subscriberCount++;
}

void Unsubscribe(callback_t callbackFunction) {
	// Search for correct callback function!
}

void SendMessage(char message[]) {
	int size = sizeof(subscribers) / sizeof(callback_t);

	for (int i = 0; i < size; i++)
	{
		subscribers[i](message);
	}
}

void Initialize() {
	subscribers = (callback_t*)malloc(sizeof(callback_t));
}