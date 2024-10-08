#ifndef CHECK_FOR_LIMIT_H
#define CHECK_FOR_LIMIT_H

#include <stdbool.h>

namespace abc
{
  bool   temperature_checker(float temperature);
  bool soc_checker(float soc);
  bool cr_checker(float CR);
}

#endif
