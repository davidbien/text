
// Warning! This file is autogenerated.
#include <boost/text/collation_table.hpp>
#include <boost/text/collate.hpp>
#include <boost/text/data/all.hpp>

#ifndef LIMIT_TESTING_FOR_CI
#include <boost/text/save_load_table.hpp>

#include <boost/filesystem.hpp>
#endif

#include <gtest/gtest.h>

using namespace boost::text;

auto const error = [](string const & s) { std::cout << s; };
auto const warning = [](string const & s) {};

collation_table make_save_load_table()
{
#ifdef LIMIT_TESTING_FOR_CI
    string const table_str(data::kl::standard_collation_tailoring());
    return tailored_collation_table(
        table_str,
        "kl::standard_collation_tailoring()", error, warning);
#else
    if (!exists(boost::filesystem::path("kl_standard.table"))) {
        string const table_str(data::kl::standard_collation_tailoring());
        collation_table table = tailored_collation_table(
            table_str,
            "kl::standard_collation_tailoring()", error, warning);
        save_table(table, "kl_standard.table.0");
        boost::filesystem::rename("kl_standard.table.0", "kl_standard.table");
    }
    return load_table("kl_standard.table");
#endif
}
collation_table const & table()
{
    static collation_table retval = make_save_load_table();
    return retval;
}
TEST(tailoring, kl_standard_000_001)
{
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x0044);
    auto const rel = std::vector<uint32_t>(1, 0x0111);
    string const res_str = to_string(res);
    string const rel_str = to_string(rel);
    auto const res_view = as_utf32(res);
    auto const rel_view = as_utf32(rel);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        0);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::primary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x0111);
    auto const rel = std::vector<uint32_t>(1, 0x0110);
    string const res_str = to_string(res);
    string const rel_str = to_string(rel);
    auto const res_view = as_utf32(res);
    auto const rel_view = as_utf32(rel);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        0);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::secondary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x0110);
    auto const rel = std::vector<uint32_t>(1, 0x00f0);
    string const res_str = to_string(res);
    string const rel_str = to_string(rel);
    auto const res_view = as_utf32(res);
    auto const rel_view = as_utf32(rel);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        0);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::primary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x00f0);
    auto const rel = std::vector<uint32_t>(1, 0x00d0);
    string const res_str = to_string(res);
    string const rel_str = to_string(rel);
    auto const res_view = as_utf32(res);
    auto const rel_view = as_utf32(rel);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        0);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::secondary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x0051);
    auto const rel = std::vector<uint32_t>(1, 0x0138);
    string const res_str = to_string(res);
    string const rel_str = to_string(rel);
    auto const res_view = as_utf32(res);
    auto const rel_view = as_utf32(rel);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        0);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::primary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x0138);
    auto const rel = std::vector<uint32_t>{0x004b, 0x0027};
    string const res_str = to_string(res);
    string const rel_str = to_string(rel);
    auto const res_view = as_utf32(res);
    auto const rel_view = as_utf32(rel);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        0);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::secondary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>{0x0074, 0x0068};
    auto const rel = std::vector<uint32_t>(1, 0x00fe);
    string const res_str = to_string(res);
    string const rel_str = to_string(rel);
    auto const res_view = as_utf32(res);
    auto const rel_view = as_utf32(rel);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        0);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::secondary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>{0x0054, 0x0048};
    auto const rel = std::vector<uint32_t>(1, 0x00de);
    string const res_str = to_string(res);
    string const rel_str = to_string(rel);
    auto const res_view = as_utf32(res);
    auto const rel_view = as_utf32(rel);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        0);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::secondary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x0059);
    auto const rel = std::vector<uint32_t>{0x0075, 0x0308};
    string const res_str = to_string(res);
    string const rel_str = to_string(rel);
    auto const res_view = as_utf32(res);
    auto const rel_view = as_utf32(rel);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        0);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::primary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>{0x0075, 0x0308};
    auto const rel = std::vector<uint32_t>{0x0055, 0x0308};
    string const res_str = to_string(res);
    string const rel_str = to_string(rel);
    auto const res_view = as_utf32(res);
    auto const rel_view = as_utf32(rel);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        0);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::secondary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>{0x0055, 0x0308};
    auto const rel = std::vector<uint32_t>{0x0075, 0x030b};
    string const res_str = to_string(res);
    string const rel_str = to_string(rel);
    auto const res_view = as_utf32(res);
    auto const rel_view = as_utf32(rel);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        0);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::primary),
        0);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>{0x0075, 0x030b};
    auto const rel = std::vector<uint32_t>{0x0055, 0x030b};
    string const res_str = to_string(res);
    string const rel_str = to_string(rel);
    auto const res_view = as_utf32(res);
    auto const rel_view = as_utf32(rel);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::secondary),
        0);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::secondary),
        0);
    }
}
