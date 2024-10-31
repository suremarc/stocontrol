#include <inttypes.h>
#include <common.hpp>

// A market interface that only supports liquidity-taking, i.e. market orders.
// Also assumes trading happens instantaneously.
class Market
{
public:
    // Returns the average execution price of the trade.
    virtual Decimal transact(uint32_t asset_id, Decimal amount, Decimal price) = 0;

    virtual ~Market() = 0;
};
