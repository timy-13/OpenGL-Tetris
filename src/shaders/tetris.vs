#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 model;
uniform  mat4 projection;

void main()
{
    gl_Position = projection * model * glm::vec4(aPos.xy, 1.0, 1.0);
}