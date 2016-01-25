attribute highp vec4 posAttr;
attribute highp vec4 teamAttr;
uniform mat4 matrix;
varying highp vec4 col;

void main()
{
    gl_Position = posAttr * matrix;
    col = vec4(0.5,0.5,0.5,0.5);
}

