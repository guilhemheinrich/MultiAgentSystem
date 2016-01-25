attribute highp vec4 posAttr;
attribute highp float teamAttr;
uniform mat4 matrix;
varying highp vec4 col;

void main()
{
    gl_PointSize = 20.0;
    gl_Position = posAttr * matrix;
    col = vec4(1,0,0,1);
    if((teamAttr * 1.0) == 1.0)
        col = vec4(0,1,0,1);
    else
        col = vec4(1,0,0,1);
}

