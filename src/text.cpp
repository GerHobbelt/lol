//
// Lol Engine
//
// Copyright: (c) 2010-2011 Sam Hocevar <sam@hocevar.net>
//   This program is free software; you can redistribute it and/or
//   modify it under the terms of the Do What The Fuck You Want To
//   Public License, Version 2, as published by Sam Hocevar. See
//   http://sam.zoy.org/projects/COPYING.WTFPL for more details.
//

#if defined HAVE_CONFIG_H
#   include "config.h"
#endif

#include <cstdio>
#include <cstdlib> /* free() */
#include <cstring> /* strdup() */

#include "core.h"

/*
 * Text implementation class
 */

class TextData
{
    friend class Text;

private:
    int font, align, length;
    char *text;
    int3 pos;
};

/*
 * Public Text class
 */

Text::Text(char const *text, char const *font)
  : data(new TextData())
{
    data->font = Forge::Register(font);
    data->text = text ? strdup(text) : NULL;
    data->length = text ? strlen(text) : 0;
    data->pos = int3(0, 0, 0);

    drawgroup = DRAWGROUP_HUD;
}

void Text::SetText(char const *text)
{
    if (data->text)
        free(data->text);
    data->text = text ? strdup(text) : NULL;
    data->length = text ? strlen(text) : 0;
}

void Text::SetInt(int val)
{
    if (data->text)
        free(data->text);
    char text[128];
    sprintf(text, "%i", val);
    data->text = strdup(text);
    data->length = strlen(text);
}

void Text::SetPos(int3 pos)
{
    data->pos = pos;
}

void Text::SetAlign(int align)
{
    data->align = align;
}

void Text::TickDraw(float deltams)
{
    Entity::TickDraw(deltams);

    if (data->text)
    {
        Font *font = Forge::GetFont(data->font);
        int3 delta = 0;
        if (data->align == ALIGN_RIGHT)
            delta.x -= data->length * font->GetSize().x;
        else if (data->align == ALIGN_CENTER)
            delta.x -= data->length * font->GetSize().x / 2;
        font->Print(data->pos + delta, data->text);
    }
}

Text::~Text()
{
    if (data->text)
        free(data->text);
    Forge::Deregister(data->font);
    delete data;
}

