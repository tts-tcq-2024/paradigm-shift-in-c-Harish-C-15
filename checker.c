#include <stdio.h>
#include <assert.h>

using namespace std;

bool temperature_checker(float temperature)
{
  if(temperature < 0 || temperature > 45)
    {
      cout<<"Temperature is out of range\n";
      return false;
    }
  return true;
}

bool soc_checker(float soc)
{
  if(soc < 20 || soc > 80)
    {
      cout<<"State Of Charge is out of range\n";
      return false;
    }
  return true;
}

bool cr_checker(float CR)
{
  if(CR > 0.8)
    {
      cout<<"Charge Rate is out of range\n";
      return false;
    }
  return true;
}

bool batteryIsOk(float temperature, float soc, float CR)
{
  return temperature_checker(temperature) && soc_checker(soc) && cr_checker(chargeRate);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  return 0;
}
