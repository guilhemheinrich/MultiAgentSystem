attribute highp vec4 posAttr;
attribute highp float teamAttr;
uniform mat4 matrix;
varying highp vec4 col;

uniform float test = 1.0;
void main()
{
    gl_PointSize = 20.0;
    gl_Position = posAttr * matrix;

    if((teamAttr * 1.0) == 2.0)
        col = vec4(0,1,0,1);
    else
        col = vec4(1,0,0,1);

//    if (test == 1.0) col = vec4(0,0,1,1);
}

