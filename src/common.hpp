#include <inttypes.h>

struct Decimal
{
    int32_t numerator;
    DenominatorCode denominator_code;
};

enum DenominatorCode
{
    Ones,
    Tenths,
    Hundredths,
    Thousanths,
};
