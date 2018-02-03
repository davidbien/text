
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
            data::bs::standard_collation_tailoring(),
            "bs::standard_collation_tailoring()", error, warning);
    return retval;
}
TEST(tailoring, bs_standard_000_001)
{
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0043),
        std::vector<uint32_t>(1, 0x010d),
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x010d),
        std::vector<uint32_t>(1, 0x010c),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x010d),
        std::vector<uint32_t>(1, 0x010c),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x010c),
        std::vector<uint32_t>(1, 0x0107),
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0107),
        std::vector<uint32_t>(1, 0x0106),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0107),
        std::vector<uint32_t>(1, 0x0106),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0044),
        std::vector<uint32_t>{0x0064, 0x017e},
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0064, 0x017e},
        std::vector<uint32_t>(1, 0x01c6),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0064, 0x017e},
        std::vector<uint32_t>(1, 0x01c6),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c6),
        std::vector<uint32_t>{0x0044, 0x017e},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c6),
        std::vector<uint32_t>{0x0044, 0x017e},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0044, 0x017e},
        std::vector<uint32_t>(1, 0x01c5),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0044, 0x017e},
        std::vector<uint32_t>(1, 0x01c5),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c5),
        std::vector<uint32_t>{0x0044, 0x017d},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c5),
        std::vector<uint32_t>{0x0044, 0x017d},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0044, 0x017d},
        std::vector<uint32_t>(1, 0x01c4),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0044, 0x017d},
        std::vector<uint32_t>(1, 0x01c4),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c4),
        std::vector<uint32_t>(1, 0x0111),
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0111),
        std::vector<uint32_t>(1, 0x0110),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0111),
        std::vector<uint32_t>(1, 0x0110),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x004c),
        std::vector<uint32_t>{0x006c, 0x006a},
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006c, 0x006a},
        std::vector<uint32_t>(1, 0x01c9),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006c, 0x006a},
        std::vector<uint32_t>(1, 0x01c9),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c9),
        std::vector<uint32_t>{0x004c, 0x006a},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c9),
        std::vector<uint32_t>{0x004c, 0x006a},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004c, 0x006a},
        std::vector<uint32_t>(1, 0x01c8),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004c, 0x006a},
        std::vector<uint32_t>(1, 0x01c8),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c8),
        std::vector<uint32_t>{0x004c, 0x004a},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c8),
        std::vector<uint32_t>{0x004c, 0x004a},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004c, 0x004a},
        std::vector<uint32_t>(1, 0x01c7),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004c, 0x004a},
        std::vector<uint32_t>(1, 0x01c7),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x004e),
        std::vector<uint32_t>{0x006e, 0x006a},
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x006a},
        std::vector<uint32_t>(1, 0x01cc),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x006a},
        std::vector<uint32_t>(1, 0x01cc),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01cc),
        std::vector<uint32_t>{0x004e, 0x006a},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01cc),
        std::vector<uint32_t>{0x004e, 0x006a},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x006a},
        std::vector<uint32_t>(1, 0x01cb),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x006a},
        std::vector<uint32_t>(1, 0x01cb),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01cb),
        std::vector<uint32_t>{0x004e, 0x004a},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01cb),
        std::vector<uint32_t>{0x004e, 0x004a},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x004a},
        std::vector<uint32_t>(1, 0x01ca),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x004a},
        std::vector<uint32_t>(1, 0x01ca),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0053),
        std::vector<uint32_t>(1, 0x0161),
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0161),
        std::vector<uint32_t>(1, 0x0160),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0161),
        std::vector<uint32_t>(1, 0x0160),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x005a),
        std::vector<uint32_t>(1, 0x017e),
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x017e),
        std::vector<uint32_t>(1, 0x017d),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x017e),
        std::vector<uint32_t>(1, 0x017d),
        table(), collation_strength::secondary),
        0);
}
