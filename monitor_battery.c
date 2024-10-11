#include "monitor_battery.h"
#include "Param_Checker.h"

#include <stdio.h>

// Function to print a message
void printMessage(const char *message) {
    printf("%s\n", message);
}

// Consolidated function to handle parameter checks
void checkParameter(float value, float min, float max, ParameterState *state,
                    const char *errorMsg, const char *lowWarning, const char *highWarning,
                    int checkHighWarningOnly = 0;) {
    // Set the parameter state with error and warning messages
    setParameterState(state, errorMsg, lowWarning, highWarning);

    // Check bounds and handle errors
    checkBounds(value, min, max, state->errorMessage);

    // Check warnings based on the parameter type
    if (checkHighWarningOnly) {
        handleWarningHigh(value, max, state);  // Only check high warning
    } else {
        checkWarnings(value, min, max, state);  // Check both low and high warnings
    }
}

// Specific checks using the generalized function
void checkTemperature(float temperature, ParameterState *state) {
    checkParameter(temperature, TEMP_MIN, TEMP_MAX, state,
                   "Temperature out of range!",
                   "Warning: Approaching low temperature!",
                   "Warning: Approaching high temperature!");
}

void checkSoc(float soc, ParameterState *state) {
    checkParameter(soc, SOC_MIN, SOC_MAX, state,
                   "State of Charge out of range!",
                   "Warning: Approaching discharge!",
                   "Warning: Approaching charge-peak!");
}

void checkChargeRate(float chargeRate, ParameterState *state) {
    checkParameter(chargeRate, 0, CR_MAX, state,
                   "Charge Rate out of range!",
                   "",  // No low warning
                   "Warning: Approaching charge rate peak!", 1);  // Only high warning
}
