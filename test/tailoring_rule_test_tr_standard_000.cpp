
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
    string const table_str(data::tr::standard_collation_tailoring());
    return tailored_collation_table(
        table_str,
        "tr::standard_collation_tailoring()", error, warning);
#else
    if (!exists(boost::filesystem::path("tr_standard.table"))) {
        string const table_str(data::tr::standard_collation_tailoring());
        collation_table table = tailored_collation_table(
            table_str,
            "tr::standard_collation_tailoring()", error, warning);
        save_table(table, "tr_standard.table.0");
        boost::filesystem::rename("tr_standard.table.0", "tr_standard.table");
    }
    return load_table("tr_standard.table");
#endif
}
collation_table const & table()
{
    static collation_table retval = make_save_load_table();
    return retval;
}
TEST(tailoring, tr_standard_000_001)
{
    {
    // greater than (or equal to, for =) preceeding cps
    auto const res = std::vector<uint32_t>(1, 0x0043);
    auto const rel = std::vector<uint32_t>{0x0063, 0x0327};
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
    auto const res = std::vector<uint32_t>{0x0063, 0x0327};
    auto const rel = std::vector<uint32_t>{0x0043, 0x0327};
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
    auto const res = std::vector<uint32_t>(1, 0x0047);
    auto const rel = std::vector<uint32_t>{0x0067, 0x0306};
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
    auto const res = std::vector<uint32_t>{0x0067, 0x0306};
    auto const rel = std::vector<uint32_t>{0x0047, 0x0306};
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
    auto const res = std::vector<uint32_t>(1, 0x0069);
    auto const rel = std::vector<uint32_t>(1, 0x0130);
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
    auto const rel = std::vector<uint32_t>{0x006f, 0x0308};
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
    auto const res = std::vector<uint32_t>{0x006f, 0x0308};
    auto const rel = std::vector<uint32_t>{0x004f, 0x0308};
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
    auto const res = std::vector<uint32_t>(1, 0x0053);
    auto const rel = std::vector<uint32_t>{0x0073, 0x0327};
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
    auto const res = std::vector<uint32_t>{0x0073, 0x0327};
    auto const rel = std::vector<uint32_t>{0x0053, 0x0327};
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
    auto const res = std::vector<uint32_t>(1, 0x0055);
    auto const rel = std::vector<uint32_t>{0x0075, 0x0308};
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
}
