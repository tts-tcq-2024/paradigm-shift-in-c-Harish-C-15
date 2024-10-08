#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool batteryIsOk(float temperature, float soc, float CR)
{
  return temperature_checker(temperature) && soc_checker(soc) && cr_checker(CR);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
  assert(batteryIsOk(25, 70, 0.8) == false);
  assert(batteryIsOk(25, 10, 0.7) == false);
  assert(batteryIsOk(55, 70, 0.7) == false);
  return 0;
}
