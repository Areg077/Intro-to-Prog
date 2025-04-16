// a lot of AI was used to write this code, but I understand everything and can explain each part!

#include <stdio.h>

//  Here we are creating a tyoe and naming it State which represents the subway gates
typedef enum {
    LOCKED,
    UNLOCKED,
    PASSING,
    BLOCKED
} State;

// again we are creating another type which represent the events that trigger transitions
typedef enum {
    SCAN_TICKET,
    PASS_THROUGH,
    BAD_ACTION
} Event;

// In this part we are converting the states into strings
const char* getStateName(State state) {
    switch (state) {
        case LOCKED: return "LOCKED";
        case UNLOCKED: return "UNLOCKED";
        case PASSING: return "PASSING";
        case BLOCKED: return "BLOCKED";
        default: return "UNKNOWN";
    }
}

// Again converting Evenets into strings
const char* getEventName(Event e) {
    switch (e) {
        case SCAN_TICKET: return "SCAN_TICKET";
        case PASS_THROUGH: return "PASS_THROUGH";
        case BAD_ACTION: return "BAD_ACTION";
        default: return "UNKNOWN";
    }
}

// this is the logic part. Using switch we are creating a function that connects each caase to states
State handleEvent(State current, Event e) {
    switch (current) {
        case LOCKED:
            if (e == SCAN_TICKET) return UNLOCKED;
            if (e == BAD_ACTION) return BLOCKED;
            break;
        case UNLOCKED:
            if (e == PASS_THROUGH) return PASSING;
            if (e == BAD_ACTION) return BLOCKED;
            break;
        case PASSING:
            return LOCKED;
        case BLOCKED:
            if (e == SCAN_TICKET) return LOCKED;
            break;
    }
    return current; 
}


//finallt this where we are showing the result of the FSM.
int main() {
    State currentState = LOCKED;

    Event inputs[] = {
        SCAN_TICKET,
        PASS_THROUGH,
        BAD_ACTION,
        SCAN_TICKET,
        PASS_THROUGH,
        BAD_ACTION,
        SCAN_TICKET
    };

    int numEvents = sizeof(inputs) / sizeof(inputs[0]);

    printf("Subway Entry FSM Simulation\n");
    printf("----------------------------\n");

    for (int i = 0; i < numEvents; i++) {
        printf("Event: %s\n", getEventName(inputs[i]));
        currentState = handleEvent(currentState, inputs[i]);
        printf("Current State: %s\n\n", getStateName(currentState));
    }

    return 0;
