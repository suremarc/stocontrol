#include <string>
#include <fstream>
#include <unordered_map>
#include <array>

#include "market.hpp"

class Equity
{
public:
    typedef const std::string ID;
    ID ticker;
};

class TAQMarket : Market<Equity>
{
private:
    std::ofstream taq_file;
    std::unordered_map<Equity::ID, BBO> top_of_book;

public:
    BBO quote(Equity::ID asset_id);
};
