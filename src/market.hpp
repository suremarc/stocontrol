#pragma once

#include <inttypes.h>
#include <type_traits>
#include <concepts>
#include <ranges>
#include "common.hpp"

/**
 * A tradable entity with a unique identifier.
 */
template <class T>
concept Asset = requires {
    typename T::ID;
};

/**
 * Best Bid and Offer for a tradable asset at an instant in time.
 */
struct BBO
{
    Decimal ask;
    Decimal bid;
};

/**
 * A market interface that only supports liquidity-taking, i.e. market orders.
 * Also assumes trading happens instantaneously.
 *
 * @tparam T The type of asset offered in this market.
 */
template <Asset T>
class Market
{
public:
    Market() = delete;

    /**
     * Gives the best bid & offer currently available for an asset.
     */
    BBO quote(typename T::ID asset_id) {}

    /**
     * List all assets that can be traded in this market.
     */
    std::ranges::subrange<T> assets() {};
};