//
// Lol Engine
//
// Copyright: (c) 2010-2014 Sam Hocevar <sam@hocevar.net>
//   This program is free software; you can redistribute it and/or
//   modify it under the terms of the Do What The Fuck You Want To
//   Public License, Version 2, as published by Sam Hocevar. See
//   http://www.wtfpl.net/ for more details.
//

#if defined HAVE_CONFIG_H
#   include "config.h"
#endif

#include <lol/main.h>
#include <lolunit.h>

namespace lol
{

LOLUNIT_FIXTURE(BuildTest)
{
    LOLUNIT_TEST(TypeSizeHalf)
    {
        LOLUNIT_ASSERT_EQUAL(sizeof(half), 2);

#if LOL_FEATURE_CXX11_UNRESTRICTED_UNIONS
        LOLUNIT_ASSERT_EQUAL(sizeof(f16vec2), 4);
        LOLUNIT_ASSERT_EQUAL(sizeof(f16vec3), 6);
        LOLUNIT_ASSERT_EQUAL(sizeof(f16vec4), 8);

        LOLUNIT_ASSERT_EQUAL(sizeof(f16mat2), 8);
        LOLUNIT_ASSERT_EQUAL(sizeof(f16mat3), 18);
        LOLUNIT_ASSERT_EQUAL(sizeof(f16mat4), 32);
#endif
    }

    LOLUNIT_TEST(TypeSizeFloat)
    {
        LOLUNIT_ASSERT_EQUAL(sizeof(float), 4);

        LOLUNIT_ASSERT_EQUAL(sizeof(vec2), 8);
        LOLUNIT_ASSERT_EQUAL(sizeof(vec3), 12);
        LOLUNIT_ASSERT_EQUAL(sizeof(vec4), 16);

        LOLUNIT_ASSERT_EQUAL(sizeof(mat2), 16);
        LOLUNIT_ASSERT_EQUAL(sizeof(mat3), 36);
        LOLUNIT_ASSERT_EQUAL(sizeof(mat4), 64);
    }

    LOLUNIT_TEST(TypeSizeDouble)
    {
        LOLUNIT_ASSERT_EQUAL(sizeof(double), 8);

        LOLUNIT_ASSERT_EQUAL(sizeof(dvec2), 16);
        LOLUNIT_ASSERT_EQUAL(sizeof(dvec3), 24);
        LOLUNIT_ASSERT_EQUAL(sizeof(dvec4), 32);

        LOLUNIT_ASSERT_EQUAL(sizeof(dmat2), 32);
        LOLUNIT_ASSERT_EQUAL(sizeof(dmat3), 72);
        LOLUNIT_ASSERT_EQUAL(sizeof(dmat4), 128);
    }

    LOLUNIT_TEST(TypeSizeInt8)
    {
        LOLUNIT_ASSERT_EQUAL(sizeof(i8vec2), 2);
        LOLUNIT_ASSERT_EQUAL(sizeof(u8vec2), 2);
        LOLUNIT_ASSERT_EQUAL(sizeof(i8vec3), 3);
        LOLUNIT_ASSERT_EQUAL(sizeof(u8vec3), 3);
        LOLUNIT_ASSERT_EQUAL(sizeof(i8vec4), 4);
        LOLUNIT_ASSERT_EQUAL(sizeof(u8vec4), 4);
    }

    LOLUNIT_TEST(TypeSizeInt16)
    {
        LOLUNIT_ASSERT_EQUAL(sizeof(i16vec2), 4);
        LOLUNIT_ASSERT_EQUAL(sizeof(u16vec2), 4);
        LOLUNIT_ASSERT_EQUAL(sizeof(i16vec3), 6);
        LOLUNIT_ASSERT_EQUAL(sizeof(u16vec3), 6);
        LOLUNIT_ASSERT_EQUAL(sizeof(i16vec4), 8);
        LOLUNIT_ASSERT_EQUAL(sizeof(u16vec4), 8);
    }

    LOLUNIT_TEST(TypeSizeInt32)
    {
        LOLUNIT_ASSERT_EQUAL(sizeof(ivec2), 8);
        LOLUNIT_ASSERT_EQUAL(sizeof(uvec2), 8);
        LOLUNIT_ASSERT_EQUAL(sizeof(ivec3), 12);
        LOLUNIT_ASSERT_EQUAL(sizeof(uvec3), 12);
        LOLUNIT_ASSERT_EQUAL(sizeof(ivec4), 16);
        LOLUNIT_ASSERT_EQUAL(sizeof(uvec4), 16);
    }

    LOLUNIT_TEST(TypeSizeInt64)
    {
        LOLUNIT_ASSERT_EQUAL(sizeof(i64vec2), 16);
        LOLUNIT_ASSERT_EQUAL(sizeof(u64vec2), 16);
        LOLUNIT_ASSERT_EQUAL(sizeof(i64vec3), 24);
        LOLUNIT_ASSERT_EQUAL(sizeof(u64vec3), 24);
        LOLUNIT_ASSERT_EQUAL(sizeof(i64vec4), 32);
        LOLUNIT_ASSERT_EQUAL(sizeof(u64vec4), 32);
    }

#if !defined LOL_BUILD_DEBUG
    LOLUNIT_TEST(FastMath)
    {
        double x, y;

        y = x = 1.0 + rand(0.1f, 0.2f);
        y += 4503599627370496.0;
        /* The compiler should optimise this away */
        y -= 4503599627370496.0;

        LOLUNIT_ASSERT_EQUAL(x, y);
    }
#endif
};

} /* namespace lol */
