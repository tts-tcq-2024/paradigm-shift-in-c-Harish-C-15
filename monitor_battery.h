#ifndef MONITOR_BATTERY_H
#define MONITOR_BATTERY_H

#include <stdio.h>
#include "Param_Checker.h"

#define CR_MAX 0.8
#define TEMP_MIN 0.0
#define TEMP_MAX 45.0
#define SOC_MIN 20.0
#define SOC_MAX 80.0

#define TOLERANCE_PERCENTAGE 0.05

void printMessage(const char *message);

void checkTemperature(float temperature, ParameterState *state);

void checkSoc(float soc, ParameterState *state);

void checkChargeRate(float chargeRate, ParameterState *state);

#endif 
