namespace vfc
{
  bool temperature_checker(float temperature)
  {
    if(temperature < 0 || temperature > 45)
    {
      printf("Temperature is out of range\n");
      return false;
    }
  return true;
  }

bool soc_checker(float soc)
{
  if(soc < 20 || soc > 80)
    {
      printf("State Of Charge is out of range\n");
      return false;
    }
  return true;
}

bool cr_checker(float CR)
{
  if(CR > 0.8)
    {
      printf("Charge Rate is out of range\n");
      return false;
    }
  return true;
}
