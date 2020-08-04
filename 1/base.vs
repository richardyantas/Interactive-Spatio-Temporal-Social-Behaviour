#version 330 core
layout (location = 0) in vec3 aPos;
//uniform mat4 u_transform;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 model;
void main()
{
    //gl_Position = u_transform*vec4(aPos.x, aPos.y, aPos.z, 1.0);
    gl_Position = projection * view * model * vec4(aPos, 1.0f);
	//TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}