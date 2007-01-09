///////////////////////////////////////////////////////////////////////////////
/// \file list.hpp
/// A special-purpose proto transform for putting things into a
/// fusion::cons<> list.
//
//  Copyright 2004 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROTO_TRANSFORM_LIST_HPP_EAN_12_16_2006
#define BOOST_PROTO_TRANSFORM_LIST_HPP_EAN_12_16_2006

#if !defined(__WAVE__) || !defined(BOOST_PROTO_DOXYGEN_INVOKED)
#include <boost/fusion/sequence/container/list/cons.hpp>
#include <boost/xpressive/proto/proto_fwd.hpp>
#else
/// INTERNAL ONLY
/// Needed to work around doxygen bug
struct a_dummy_global;
#endif

namespace boost { namespace proto { namespace transform
{

    // A list transform, that puts elements into a fusion cons-list
    template<typename Grammar>
    struct list
      : Grammar
    {
        list();

        template<typename Expr, typename State, typename Visitor>
        struct apply
        {
            typedef fusion::cons<
                typename Grammar::template apply<Expr, State, Visitor>::type
              , State
            > type;
        };

        template<typename Expr, typename State, typename Visitor>
        static typename apply<Expr, State, Visitor>::type
        call(Expr const &expr, State const &state, Visitor &visitor)
        {
            return typename apply<Expr, State, Visitor>::type
                (Grammar::call(expr, state, visitor), state);
        }
    };

}}}

#endif
