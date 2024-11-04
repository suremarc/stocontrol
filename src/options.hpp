#include <string>
#include <chrono>
#include <inttypes.h>

#include "market.hpp"
#include "equities.cpp"

enum class ContractType;
enum class OptionStyle;

/**
 * A derivative instrument that provides the right but not the obligation
 * to buy or sell and underlying asset.
 *
 * @tparam T The asset underlying this option.
 */
template <Asset T>
class Option
{
public:
    typedef const struct
    {
        T::ID underlying;
        uint8_t correction;
        std::chrono::year_month_day expiration_date;
        ContractType contract_type;
        OptionStyle style;
        Decimal strike_price;
    } ID;

    ID params;
};

enum class ContractType
{
    Call,
    Put,
};

enum class OptionStyle
{
    American,
    European,
};

class OPRAMarket
{
private:
    void handle_pkt(const uint8_t *data);

public:
    BBO quote(Option<Equity>::ID asset_id);
};

// TODO: implement Market for OPRAMarket
// static_assert(Market<OPRAMarket, Option<Equity>>, "TAQMarket must satisfy the Market concept");
