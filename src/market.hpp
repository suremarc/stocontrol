#pragma once

#include <inttypes.h>
#include <type_traits>
#include <concepts>
#include <ranges>
#include <chrono>

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
template <typename M, typename A>
concept Market = requires(const M market, const A asset, const typename A::ID asset_id) {
    requires Asset<A>;

    /**
     * The timestamp of the last processed order in this market.
     */
    { market.timestamp() } -> std::same_as<std::chrono::time_point<std::chrono::steady_clock>>;

    /**
     * Gives the best bid & offer currently available for an asset.
     */
    { market.quote(asset_id) } -> std::same_as<BBO>;

    /**
     * List all assets that can be traded in this market.
     */
    { market.assets() } -> std::ranges::input_range;
    { *std::ranges::begin(market.assets()) } -> std::same_as<const A &>;
};
