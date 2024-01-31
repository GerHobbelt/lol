//
//  Lol Engine
//
//  Copyright © 2010–2024 Sam Hocevar <sam@hocevar.net>
//
//  Lol Engine is free software. It comes without any warranty, to
//  the extent permitted by applicable law. You can redistribute it
//  and/or modify it under the terms of the Do What the Fuck You Want
//  to Public License, Version 2, as published by the WTFPL Task Force.
//  See http://www.wtfpl.net/ for more details.
//

#pragma once

#include <lol/format> // std::format

namespace lol
{

template<>
inline std::string vec2::tostring() const
{
    return std::format("[ {:6.6f} {:6.6f} ]", x, y);
}

template<>
inline std::string ivec2::tostring() const
{
    return std::format("[ {} {} ]", x, y);
}

template<>
inline std::string vec3::tostring() const
{
    return std::format("[ {:6.6f} {:6.6f} {:6.6f} ]", x, y, z);
}

template<>
inline std::string ivec3::tostring() const
{
    return std::format("[ {} {} {} ]", x, y, z);
}

template<>
inline std::string vec4::tostring() const
{
    return std::format("[ {:6.6f} {:6.6f} {:6.6f} {:6.6f} ]", x, y, z, w);
}

template<>
inline std::string ivec4::tostring() const
{
    return std::format("[ {} {} {} {} ]", x, y, z, w);
}

} // namespace lol
