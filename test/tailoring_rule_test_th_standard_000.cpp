
// Warning! This file is autogenerated.
#include <boost/text/collation_table.hpp>
#include <boost/text/collate.hpp>
#include <boost/text/data/all.hpp>

#include <gtest/gtest.h>

using namespace boost::text;

auto const error = [](string const & s) { std::cout << s; };
auto const warning = [](string const & s) {};

collation_table const & table()
{
    static collation_table retval =
        tailored_collation_table(
            data::th::standard_collation_tailoring(),
            "th::standard_collation_tailoring()", error, warning);
    return retval;
}
TEST(tailoring, th_standard_000_001)
{
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0e5b),
        std::vector<uint32_t>(1, 0x0e46),
        table(), collation_strength::quaternary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0e4e),
        std::vector<uint32_t>(1, 0x0e4c),
        table(), collation_strength::quaternary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0e32),
        std::vector<uint32_t>(1, 0x0e45),
        table(), collation_strength::quaternary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0e32, 0x0e4d},
        std::vector<uint32_t>{0x0e4d, 0x0e32},
        table(), collation_strength::quaternary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0e4d, 0x0e32},
        std::vector<uint32_t>(1, 0x0e33),
        table(), collation_strength::quaternary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0e45, 0x0e4d},
        std::vector<uint32_t>{0x0e4d, 0x0e45},
        table(), collation_strength::quaternary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0e44),
        std::vector<uint32_t>(1, 0x0e3a),
        table(), collation_strength::quaternary),
        -1);
}
