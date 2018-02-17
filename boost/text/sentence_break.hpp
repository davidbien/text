#ifndef BOOST_TEXT_SENTENCE_BREAK_HPP
#define BOOST_TEXT_SENTENCE_BREAK_HPP

#include <boost/text/utility.hpp>

#include <array>

#include <cassert>
#include <stdint.h>


namespace boost { namespace text {

    /** The sentence properties outlined in Unicode 10. */
    enum class sentence_prop_t {
        Other,
        CR,
        LF,
        Sep,
        Sp,
        Lower,
        Upper,
        OLetter,
        Numeric,
        ATerm,
        STerm,
        Close,
        SContinue,
        Format,
        Extend
    };

    /** Returns the sentence property associated with code point \a cp. */
    sentence_prop_t sentence_prop(uint32_t cp) noexcept;

    namespace detail {
        inline bool skippable(sentence_prop_t prop) noexcept
        {
            return prop == sentence_prop_t::Extend ||
                   prop == sentence_prop_t::Format;
        }

        inline bool para_sep(sentence_prop_t prop) noexcept
        {
            return prop == sentence_prop_t::Sep ||
                   prop == sentence_prop_t::CR || prop == sentence_prop_t::LF;
        }

        inline bool sa_term(sentence_prop_t prop) noexcept
        {
            return prop == sentence_prop_t::STerm ||
                   prop == sentence_prop_t::ATerm;
        }

        inline bool sb8_not(sentence_prop_t prop) noexcept
        {
            return prop != sentence_prop_t::OLetter &&
                   prop != sentence_prop_t::Upper &&
                   prop != sentence_prop_t::Lower && !para_sep(prop) &&
                   !sa_term(prop);
        }

        template<typename CPIter, typename Func>
        bool before_close_sp(CPIter it, CPIter first, bool skip_sps, Func func)
        {
            --it;
            while (it != first && detail::skippable(sentence_prop(*it))) {
                --it;
            }
            if (skip_sps) {
                while (it != first &&
                       sentence_prop(*it) == sentence_prop_t::Sp) {
                    --it;
                    while (it != first &&
                           detail::skippable(sentence_prop(*it))) {
                        --it;
                    }
                }
            }
            while (it != first &&
                   sentence_prop(*it) == sentence_prop_t::Close) {
                --it;
                while (it != first && detail::skippable(sentence_prop(*it))) {
                    --it;
                }
            }
            return func(sentence_prop(*it));
        }

        template<typename CPIter>
        struct sentence_break_state
        {
            CPIter it;
            bool it_points_to_prev = false;

            sentence_prop_t prev_prev_prop;
            sentence_prop_t prev_prop;
            sentence_prop_t prop;
            sentence_prop_t next_prop;
            sentence_prop_t next_next_prop;
        };

        template<typename CPIter>
        sentence_break_state<CPIter> next(sentence_break_state<CPIter> state)
        {
            ++state.it;
            state.prev_prev_prop = state.prev_prop;
            state.prev_prop = state.prop;
            state.prop = state.next_prop;
            state.next_prop = state.next_next_prop;
            return state;
        }

        template<typename CPIter>
        sentence_break_state<CPIter> prev(sentence_break_state<CPIter> state)
        {
            if (!state.it_points_to_prev)
                --state.it;
            state.it_points_to_prev = false;
            state.next_next_prop = state.next_prop;
            state.next_prop = state.prop;
            state.prop = state.prev_prop;
            state.prev_prop = state.prev_prev_prop;
            return state;
        }

        // TODO: Attempt to consildate with word skip_forward()
        // SB5: Except after line breaks, ignore/skip (Extend | Format)*
        template<typename CPIter>
        sentence_break_state<CPIter> skip_forward(
            sentence_break_state<CPIter> state, CPIter first, CPIter last)
        {
            if (state.it != first && !skippable(state.prev_prop) &&
                skippable(state.prop)) {
                auto temp_it = state.it;
                while (std::next(temp_it) != last) {
                    auto temp_next_prop = sentence_prop(*++temp_it);
                    if (!skippable(temp_next_prop))
                        break;
                }
                if (temp_it == last) {
                    state.it = last;
                } else {
                    auto const temp_prop = sentence_prop(*temp_it);
                    state.it = temp_it;
                    state.prop = temp_prop;
                    state.next_prop = sentence_prop_t::Other;
                    state.next_next_prop = sentence_prop_t::Other;
                    if (std::next(state.it) != last) {
                        state.next_prop = sentence_prop(*std::next(state.it));
                        if (std::next(state.it, 2) != last) {
                            state.next_next_prop =
                                sentence_prop(*std::next(state.it, 2));
                        }
                    }
                }
            }
            return state;
        }

    }

    /** Finds the nearest sentence break at or before before <code>it</code>.
        If <code>it == first</code>, that is returned.  Otherwise, the first
        code point of the sentence <code>it</code> is within is returned (even
        if <code>it</code> is already at the first code point of a
        sentence. */
    template<typename CPIter>
    inline CPIter
    prev_sentence_break(CPIter first, CPIter it, CPIter last) noexcept
    {
        // TODO
        return it;
    }

    // b sentence_break.hpp:215
    // b sentence_break_09.cpp:414

    /** Finds the next sentence break after <code>it</code>.  This will be the
        first code point after the current sentence, or <code>last</code> if
        no next sentence exists.

        \pre <code>it</code> is at the beginning of a sentence. */
    template<typename CPIter>
    inline CPIter next_sentence_break(CPIter first, CPIter it, CPIter last) noexcept
    {
        if (it == last)
            return last;

        if (++it == last)
            return last;

        detail::sentence_break_state<CPIter> state;

        state.it = it;

        state.prev_prev_prop = sentence_prop_t::Other;
        state.prev_prop = sentence_prop_t::Other;
        if (state.it != first) {
            state.prev_prop = sentence_prop(*std::prev(state.it));
            if (std::prev(state.it) != first)
                state.prev_prev_prop = sentence_prop(*std::prev(state.it, 2));
        }
        state.prop = sentence_prop(*state.it);
        state.next_prop = sentence_prop_t::Other;
        state.next_next_prop = sentence_prop_t::Other;
        if (std::next(state.it) != last) {
            state.next_prop = sentence_prop(*std::next(state.it));
            if (std::next(state.it, 2) != last)
                state.next_next_prop = sentence_prop(*std::next(state.it, 2));
        }

        for (; state.it != last; state = next(state)) {
            if (std::next(state.it) != last && std::next(state.it, 2) != last)
                state.next_next_prop = sentence_prop(*std::next(state.it, 2));
            else
                state.next_next_prop = sentence_prop_t::Other;

            // SB3
            if (state.prev_prop == sentence_prop_t::CR &&
                state.prop == sentence_prop_t::LF) {
                continue;
            }

            // SB4
            if (detail::para_sep(state.prev_prop))
                return state.it;

            // Puting this here means not having to do it explicitly below
            // between prop and next_prop (and transitively, between prev_prop
            // and prop).
            state = detail::skip_forward(state, first, last);
            if (state.it == last)
                return last;

            // SB6
            if (state.prev_prop == sentence_prop_t::ATerm &&
                state.prop == sentence_prop_t::Numeric) {
                continue;
            }

            // SB7
            if ((state.prev_prev_prop == sentence_prop_t::Upper ||
                 state.prev_prev_prop == sentence_prop_t::Lower) &&
                state.prev_prop == sentence_prop_t::ATerm &&
                state.prop == sentence_prop_t::Upper) {
                continue;
            }

            // SB8
            if ((state.prev_prop == sentence_prop_t::ATerm ||
                 state.prev_prop == sentence_prop_t::Close ||
                 state.prev_prop == sentence_prop_t::Sp) &&
                (detail::sb8_not(state.prop) ||
                 state.prop == sentence_prop_t::Lower)) {
                bool const aterm = detail::before_close_sp(
                    state.it, first, true, [](sentence_prop_t prop) {
                        return prop == sentence_prop_t::ATerm;
                    });
                if (aterm) {
                    auto it = state.it;
                    while (it != last && detail::sb8_not(sentence_prop(*it))) {
                        ++it;
                        while (it != last &&
                               detail::skippable(sentence_prop(*it))) {
                            ++it;
                        }
                    }
                    if (it != last &&
                        sentence_prop(*it) == sentence_prop_t::Lower) {
                        continue;
                    }
                }
            }

            // SB8a
            if ((detail::sa_term(state.prev_prop) ||
                 state.prev_prop == sentence_prop_t::Close ||
                 state.prev_prop == sentence_prop_t::Sp) &&
                (state.prop == sentence_prop_t::SContinue ||
                 detail::sa_term(state.prop))) {
                if (detail::before_close_sp(
                        state.it, first, true, [](sentence_prop_t prop) {
                            return detail::sa_term(prop);
                        })) {
                    continue;
                }
            }

            // SB9
            if ((detail::sa_term(state.prev_prop) ||
                 state.prev_prop == sentence_prop_t::Close) &&
                (state.prop == sentence_prop_t::Close ||
                 state.prop == sentence_prop_t::Sp ||
                 detail::para_sep(state.prop))) {
                if (detail::before_close_sp(
                        state.it, first, false, [](sentence_prop_t prop) {
                            return detail::sa_term(prop);
                        })) {
                    continue;
                }
            }

            // SB10
            if ((detail::sa_term(state.prev_prop) ||
                 state.prev_prop == sentence_prop_t::Close ||
                 state.prev_prop == sentence_prop_t::Sp) &&
                (state.prop == sentence_prop_t::Sp ||
                 detail::para_sep(state.prop))) {
                if (detail::before_close_sp(
                        state.it, first, true, [](sentence_prop_t prop) {
                            return detail::sa_term(prop);
                        })) {
                    continue;
                }
            }

            // SB11
            if ((detail::sa_term(state.prev_prop) ||
                 state.prev_prop == sentence_prop_t::Close ||
                 state.prev_prop == sentence_prop_t::Sp ||
                 detail::para_sep(state.prev_prop)) &&
                //!detail::para_sep(state.prop) &&
                !detail::skippable(state.prop)) {
                auto it = state.it;
                if (detail::para_sep(state.prev_prop))
                    --it;
                if (it != first &&
                    detail::before_close_sp(
                        it, first, true, [](sentence_prop_t prop) {
                            return detail::sa_term(prop);
                        })) {
                    return state.it;
                }
            }
        }
        return last;
    }

    /** Returns the bounds of the sentence that <code>it</code> lies
        within. */
    template<typename CPIter>
    inline cp_range<CPIter>
    sentence_range(CPIter first, CPIter it, CPIter last) noexcept
    {
        cp_range<CPIter> retval{prev_sentence_break(first, it, last)};
        retval.last = next_sentence_break(first, retval.first, last);
        return retval;
    }

}}

#endif