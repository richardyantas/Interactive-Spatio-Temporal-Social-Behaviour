#version 330 core
layout (location = 0) in vec3 aPos;
uniform mat4 model;
uniform mat4 view;
void main()
{
    //gl_Position = u_transform*vec4(aPos.x, aPos.y, aPos.z, 1.0);
    //gl_Position = model * vec4(aPos, 1.0f);
    gl_Position = view * model * vec4(aPos, 1.0f);
	//TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}