attribute highp vec4 posAttr;
attribute highp int teamAttr;
uniform mat4 matrix;
varying highp vec4 col;

void main()
{
    gl_PointSize = 20;
    gl_Position = posAttr * matrix;
    col = vec4(1,0,0,1);
}

