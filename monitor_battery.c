#include "monitor_battery.h"
#include "Param_Checker.h"

void printMessage(const char *message)
{
    printf("%s\n", message);
}

void checkTemperature(float temperature, ParameterState *state) 
{
    setParameterState(state, "Temperature out of range!", 
                     "Warning: Approaching low temperature!", 
                     "Warning: Approaching high temperature!");
    
    checkBounds(temperature, TEMP_MIN, TEMP_MAX, state->errorMessage);
    checkWarnings(temperature, TEMP_MIN, TEMP_MAX, state);
}

void checkSoc(float soc, ParameterState *state) 
{
    setParameterState(state, "State of Charge out of range!", 
                     "Warning: Approaching discharge!", 
                     "Warning: Approaching charge-peak!");
    
    checkBounds(soc, SOC_MIN, SOC_MAX, state->errorMessage);
     checkWarnings(soc, SOC_MIN, SOC_MAX, state);
}

void checkChargeRate(float chargeRate, ParameterState *state) 
{
    setParameterState(state, "Charge Rate out of range!", 
                     "", 
                     "Warning: Approaching charge rate peak!");
    
    checkBounds(chargeRate, 0, CR_MAX, state->errorMessage);
    handleWarningHigh(chargeRate, CR_MAX, state);
    
}
