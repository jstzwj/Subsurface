attribute vec3 pos;
attribute vec4 color;
uniform mat4 M;
uniform mat4 V;
uniform mat4 P;
varying vec4 M_Color;
void main()
{
        M_Color = color;
        gl_Position = P * V * M * vec4(pos, 1.0);
}
