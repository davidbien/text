
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
    string const table_str(data::haw::standard_collation_tailoring());
    return tailored_collation_table(
        table_str,
        "haw::standard_collation_tailoring()", error, warning);
#else
    if (!exists(boost::filesystem::path("haw_standard.table"))) {
        string const table_str(data::haw::standard_collation_tailoring());
        collation_table table = tailored_collation_table(
            table_str,
            "haw::standard_collation_tailoring()", error, warning);
        save_table(table, "haw_standard.table.0");
        boost::filesystem::rename("haw_standard.table.0", "haw_standard.table");
    }
    return load_table("haw_standard.table");
#endif
}
collation_table const & table()
{
    static collation_table retval = make_save_load_table();
    return retval;
}
TEST(tailoring, haw_standard_000_001)
{
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x0061);
    auto const rel = std::vector<uint32_t>(1, 0x0065);
    string const res_str = to_string(res);
    string const rel_str = to_string(rel);
    auto const res_view = as_utf32(res);
    auto const rel_view = as_utf32(rel);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::primary),
        -1);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x0065);
    auto const rel = std::vector<uint32_t>(1, 0x0045);
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
    auto const res = std::vector<uint32_t>(1, 0x0045);
    auto const rel = std::vector<uint32_t>(1, 0x0069);
    string const res_str = to_string(res);
    string const rel_str = to_string(rel);
    auto const res_view = as_utf32(res);
    auto const rel_view = as_utf32(rel);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::primary),
        -1);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x0069);
    auto const rel = std::vector<uint32_t>(1, 0x0049);
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
    auto const res = std::vector<uint32_t>(1, 0x0049);
    auto const rel = std::vector<uint32_t>(1, 0x006f);
    string const res_str = to_string(res);
    string const rel_str = to_string(rel);
    auto const res_view = as_utf32(res);
    auto const rel_view = as_utf32(rel);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::primary),
        -1);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x006f);
    auto const rel = std::vector<uint32_t>(1, 0x004f);
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
    auto const res = std::vector<uint32_t>(1, 0x004f);
    auto const rel = std::vector<uint32_t>(1, 0x0075);
    string const res_str = to_string(res);
    string const rel_str = to_string(rel);
    auto const res_view = as_utf32(res);
    auto const rel_view = as_utf32(rel);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::primary),
        -1);
    }
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x0075);
    auto const rel = std::vector<uint32_t>(1, 0x0055);
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
    auto const res = std::vector<uint32_t>(1, 0x0077);
    auto const rel = std::vector<uint32_t>(1, 0x02bb);
    string const res_str = to_string(res);
    string const rel_str = to_string(rel);
    auto const res_view = as_utf32(res);
    auto const rel_view = as_utf32(rel);
    EXPECT_EQ(collate(
        res.begin(), res.end(),
        rel.begin(), rel.end(),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        res_view.begin(), res_view.end(),
        rel_view.begin(), rel_view.end(),
        table(), collation_strength::primary),
        -1);
    }
}
