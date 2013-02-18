//
// Lol Engine
//
// Copyright: (c) 2010-2011 Sam Hocevar <sam@hocevar.net>
//   This program is free software; you can redistribute it and/or
//   modify it under the terms of the Do What The Fuck You Want To
//   Public License, Version 2, as published by Sam Hocevar. See
//   http://www.wtfpl.net/ for more details.
//

//
// The Sampler class
// -----------------
// The Sampler is a static class that manages samples.
//

#if !defined __LOL_SAMPLER_H__
#define __LOL_SAMPLER_H__

#include <stdint.h>

namespace lol
{

class Sampler
{
public:
    static int Register(char const *path);
    static void Deregister(int id);

    static void PlaySample(int id);

private:
    Sampler() {}
};

} /* namespace lol */

#endif // __LOL_SAMPLER_H__

