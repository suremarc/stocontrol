#include <string>
#include <fstream>
#include <unordered_map>
#include <array>
#include <ranges>

#include "market.hpp"

class Equity
{
public:
    typedef const std::string ID;
    ID ticker;
};

class TAQMarket
{
private:
    std::ostream taq_nbbo_file;
    std::unordered_map<Equity::ID, BBO> top_of_book;
    std::vector<Equity> assets;

public:
    std::chrono::time_point<std::chrono::steady_clock> timestamp() const;
    BBO quote(Equity::ID asset_id) const;
    std::ranges::subrange<typename std::vector<Equity>::const_iterator> assets() const;
};

static_assert(Market<TAQMarket, Equity>, "TAQMarket must satisfy the Market concept");
