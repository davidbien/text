
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
            data::fil::standard_collation_tailoring(),
            "fil::standard_collation_tailoring()", error, warning);
    return retval;
}
TEST(tailoring, fil_standard_000_001)
{
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x004e),
        std::vector<uint32_t>(1, 0x00f1),
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00f1),
        std::vector<uint32_t>(1, 0x00d1),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00f1),
        std::vector<uint32_t>(1, 0x00d1),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00d1),
        std::vector<uint32_t>{0x006e, 0x0067},
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0067},
        std::vector<uint32_t>{0x004e, 0x0067},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0067},
        std::vector<uint32_t>{0x004e, 0x0067},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0067},
        std::vector<uint32_t>{0x004e, 0x0047},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0067},
        std::vector<uint32_t>{0x004e, 0x0047},
        table(), collation_strength::secondary),
        0);
}