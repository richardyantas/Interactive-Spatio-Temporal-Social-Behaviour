#version 330 core

layout(points) in;
layout(line_strip, max_vertices = 41) out;

uniform float u_cRadius;
uniform mat4 model;
uniform mat4 view;
const float PI = 3.1415926;

void main()
{
    int num_sides = 40;
    for (int i = 0; i <= num_sides; i++) {
        float ang = PI * 2.0 / num_sides * i;
        vec4 offset = vec4( cos( ang ) * u_cRadius, -sin( ang ) * u_cRadius, 0.0, 0.0 );
        //gl_Position = gl_in[0].gl_Position + offset;
        gl_Position = view*(gl_in[0].gl_Position + offset);
        //gl_Position = gl_Position;
        EmitVertex();
    }

    EndPrimitive();
}