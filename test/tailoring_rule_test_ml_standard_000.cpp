
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
            data::ml::standard_collation_tailoring(),
            "ml::standard_collation_tailoring()", error, warning);
    return retval;
}
TEST(tailoring, ml_standard_000_001)
{
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0d03),
        std::vector<uint32_t>(1, 0x0d3d),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0d03),
        std::vector<uint32_t>(1, 0x0d3d),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0d4c),
        std::vector<uint32_t>(1, 0x0d57),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0d4c),
        std::vector<uint32_t>(1, 0x0d57),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d15, 0x0d4d},
        std::vector<uint32_t>{0x0d15, 0x0d4d, 0x200d},
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d15, 0x0d4d},
        std::vector<uint32_t>{0x0d15, 0x0d4d, 0x200d},
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d15, 0x0d4d, 0x200d},
        std::vector<uint32_t>(1, 0x0d7f),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d15, 0x0d4d, 0x200d},
        std::vector<uint32_t>(1, 0x0d7f),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d23, 0x0d4d},
        std::vector<uint32_t>{0x0d23, 0x0d4d, 0x200d},
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d23, 0x0d4d},
        std::vector<uint32_t>{0x0d23, 0x0d4d, 0x200d},
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d23, 0x0d4d, 0x200d},
        std::vector<uint32_t>(1, 0x0d7a),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d23, 0x0d4d, 0x200d},
        std::vector<uint32_t>(1, 0x0d7a),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d28, 0x0d4d},
        std::vector<uint32_t>{0x0d28, 0x0d4d, 0x200d},
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d28, 0x0d4d},
        std::vector<uint32_t>{0x0d28, 0x0d4d, 0x200d},
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d28, 0x0d4d, 0x200d},
        std::vector<uint32_t>(1, 0x0d7b),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d28, 0x0d4d, 0x200d},
        std::vector<uint32_t>(1, 0x0d7b),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d30, 0x0d4d},
        std::vector<uint32_t>{0x0d30, 0x0d4d, 0x200d},
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d30, 0x0d4d},
        std::vector<uint32_t>{0x0d30, 0x0d4d, 0x200d},
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d30, 0x0d4d, 0x200d},
        std::vector<uint32_t>(1, 0x0d7c),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d30, 0x0d4d, 0x200d},
        std::vector<uint32_t>(1, 0x0d7c),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d32, 0x0d4d},
        std::vector<uint32_t>{0x0d32, 0x0d4d, 0x200d},
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d32, 0x0d4d},
        std::vector<uint32_t>{0x0d32, 0x0d4d, 0x200d},
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d32, 0x0d4d, 0x200d},
        std::vector<uint32_t>(1, 0x0d7d),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d32, 0x0d4d, 0x200d},
        std::vector<uint32_t>(1, 0x0d7d),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d33, 0x0d4d},
        std::vector<uint32_t>{0x0d33, 0x0d4d, 0x200d},
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d33, 0x0d4d},
        std::vector<uint32_t>{0x0d33, 0x0d4d, 0x200d},
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d33, 0x0d4d, 0x200d},
        std::vector<uint32_t>(1, 0x0d7e),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d33, 0x0d4d, 0x200d},
        std::vector<uint32_t>(1, 0x0d7e),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d2e, 0x0d4d},
        std::vector<uint32_t>(1, 0x0d02),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d2e, 0x0d4d},
        std::vector<uint32_t>(1, 0x0d02),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d28, 0x0d4d},
        std::vector<uint32_t>{0x0d7b, 0x0d4d},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0d28, 0x0d4d},
        std::vector<uint32_t>{0x0d7b, 0x0d4d},
        table(), collation_strength::secondary),
        0);
}
