#ifndef PARAM_CHECKER_H
#define PARAM_CHECKER_H

typedef struct {
    const char *errorMessage;
    const char *warningLow;
    const char *warningHigh;
} ParameterState;

void setParameterState(ParameterState *state, const char *errorMessage, const char *warningLow, const char *warningHigh);
void printMessage(const char *message);
void checkBounds(float value, float min, float max, const char *errorMessage);
void checkWarnings(float value, float min, float max, const ParameterState *state);

#endif
