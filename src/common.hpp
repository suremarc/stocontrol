#pragma once

#include <inttypes.h>

enum class DenominatorCode;

struct Decimal
{
    int32_t numerator;
    DenominatorCode denominator_code;
};

enum class DenominatorCode
{
    Ones,
    Tenths,
    Hundredths,
    Thousanths,
};
