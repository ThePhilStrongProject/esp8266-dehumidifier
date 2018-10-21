#include <Arduino.h>
#include "sequencer.h"

enum FrameStates
{
    FRAME_COMPLETE = 0,
    FRAME_INCOMPLETE
} frameStatus;

enum StateMachineStates
{
    STATE_ERROR = 0,
    STATE_IDLE
} state;

/*
 * Static function prototypes
 */

static FrameStates getFrameState(void);

/*
 * Public functions
 */

void StartSequencer(void)
{
    while (1)
    {
        if (getFrameState() == FRAME_COMPLETE)
        {
        }
        else if (getFrameState() == FRAME_INCOMPLETE)
        {
        }
        else
        {
            state = STATE_ERROR;
        }
    }
}

/*
 * Local functions
 */

static FrameStates getFrameState(void)
{
    static uint32_t lastFrameTime;
    if ((lastFrameTime - millis()) >= FRAME_TIME_MS)
    {
        return FRAME_COMPLETE;
    }
    else
    {
        return FRAME_INCOMPLETE;
    }
}