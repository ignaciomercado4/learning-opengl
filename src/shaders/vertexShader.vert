#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 ourPos;

void main()
{
  gl_Position = vec4(aPos, 1.0f);
  ourPos = aPos;
}

// question:  why is the bottom-left side of our triangle black?
// answer: the bottom-left side of the triangle is black because the bottom-left vertex X and Y coordinates
// are both negative, and color creation in GLSL is made passing RGBA values ranging from 0.0 (darkest) to
// 1.0 (brightest).
 