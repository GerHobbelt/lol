//
//  Lol Engine — Triangle tutorial
//
//  Copyright © 2012—2019 Sam Hocevar <sam@hocevar.net>
//
//  Lol Engine is free software. It comes without any warranty, to
//  the extent permitted by applicable law. You can redistribute it
//  and/or modify it under the terms of the Do What the Fuck You Want
//  to Public License, Version 2, as published by the WTFPL Task Force.
//  See http://www.wtfpl.net/ for more details.
//

#if HAVE_CONFIG_H
#   include "config.h"
#endif

#include <memory>

#include <lol/engine.h>
#include "loldebug.h"

using namespace lol;

LOLFX_RESOURCE_DECLARE(01_triangle);

class Triangle : public WorldEntity
{
public:
    Triangle()
      : m_vertices({ vec2( 0.0f,  0.8f),
                     vec2(-0.8f, -0.8f),
                     vec2( 0.8f, -0.8f) }),
        m_ready(false)
    {
    }

    virtual void tick_draw(float seconds, Scene &scene)
    {
        WorldEntity::tick_draw(seconds, scene);

        if (!m_ready)
        {
            m_shader = Shader::Create(LOLFX_RESOURCE_NAME(01_triangle));
            m_coord = m_shader->GetAttribLocation(VertexUsage::Position, 0);

            m_vdecl = std::make_shared<VertexDeclaration>(VertexStream<vec2>(VertexUsage::Position));

            m_vbo = std::make_shared<VertexBuffer>(m_vertices.bytes());
            void *vertices = m_vbo->Lock(0, 0);
            memcpy(vertices, &m_vertices[0], m_vertices.bytes());
            m_vbo->Unlock();

            m_ready = true;

            /* FIXME: this object never cleans up */
        }

        m_shader->Bind();
        m_vdecl->SetStream(m_vbo, m_coord);
        m_vdecl->Bind();
        m_vdecl->DrawElements(MeshPrimitive::Triangles, 0, 3);
        m_vdecl->Unbind();
    }

private:
    array<vec2> m_vertices;
    std::shared_ptr<Shader> m_shader;
    ShaderAttrib m_coord;
    std::shared_ptr<VertexDeclaration> m_vdecl;
    std::shared_ptr<VertexBuffer> m_vbo;
    bool m_ready;
};

int main(int argc, char **argv)
{
    sys::init(argc, argv);

    Application app("Tutorial 1: Triangle", ivec2(640, 480), 60.0f);

    new DebugFps(5, 5);
    new Triangle();

    app.Run();
    return EXIT_SUCCESS;
}

