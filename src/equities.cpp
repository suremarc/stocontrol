#include <lexy/callback.hpp>
#include <lexy/dsl.hpp>

#include "equities.hpp"

BBO TAQMarket::quote(Equity::ID asset_id) {
    // todo
};

namespace taq
{

    struct NBBORow
    {
        Timestamp timestamp;
        char exchange;
        std::string symbol;
        Decimal bid_price;
        uint32_t bid_size;
        Decimal offer_price;
        uint32_t offer_size;
        char quote_condition;
        uint64_t sequence_number;
        char nbbo_indicator;
        char finra_bbo_indicator;
        char finra_adf_mpid_indicator;
        char quote_cancel_or_correction;
        char source_of_quote;
        char best_bid_quote_condition;
        char best_bid_exchange;
        Decimal best_bid_price;
        uint32_t best_bid_size;
        std::string best_bid_finra_market_maker_id;
        char best_offer_quote_condition;
        char best_offer_exchange;
        Decimal best_offer_price;
        uint32_t best_offer_size;
        std::string best_offer_finra_market_maker_id;
        char luld_bbo_indicator;
        char nbbo_luld_indicator;
        char sip_generated_message_identifier;
        Timestamp participant_timestamp;
        Timestamp finra_adf_timestamp;
        std::string security_status_indicator;

        static constexpr auto rule = [] {

        };
    };

    struct Timestamp
    {
        uint8_t hours;
        uint8_t minutes;
        uint8_t seconds;
        uint32_t nanos;
    };

    namespace grammar
    {
        namespace dsl = lexy::dsl;

        struct timestamp
        {
            static constexpr auto rule = dsl::repeat(3)(dsl::integer<uint8_t>(dsl::n_digits<2>)) + dsl::integer<uint32_t>(dsl::n_digits<9>);
            static constexpr auto value = lexy::construct<Timestamp>;
        };

        // struct nbbo_row {
        //     static constexpr auto rule =
        // }

        struct decimal
        {
            static constexpr auto rule = dsl::integer<int32_t> + dsl::opt(dsl::lit<"."> + dsl::integer<uint32_t>);
            static constexpr auto value = lexy::callback<Decimal>([](
                                                                      std::int32_t integer_part,
                                                                      std::optional<std::uint32_t> fractional_part)
                                                                  { return Decimal{
                                                                        numerator : integer_part,
                                                                    }; });
        };
    };
}
