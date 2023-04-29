#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdbool.h>
#include <shaderloader.h>

static const GLfloat g_vertex_buffer_data[] = {
    -1.0f,
    -1.0f,
    0.0f,
    1.0f,
    -1.0f,
    0.0f,
    0.0f,
    1.0f,
    0.0f,
};

void triangleMaker()
{
    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);
}

int main(int argc, char const *argv[])
{
    glewExperimental = true;
    if (!glfwInit())
    {
        fprintf(stderr, "No can initiliaze GLFW\n");
        return 0;
    }
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window;

    window = glfwCreateWindow(1600, 900, "Tut1", NULL, NULL); // OpenGL context initialized
    if (window == NULL)
    {
        fprintf(stderr, "Something bad happened, maybe GPU BAD????");
        glfwTerminate();
        return 0;
    }
    glfwMakeContextCurrent(window);
    glewExperimental = true;
    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "GLEW no work:(");
        return 0;
    }

    GLuint programID = LoadShaders("/home/hajlektalan/Documents/UNI_repos/grafika/graphics/temp/src/SimpleVertexShader.glsl", "/home/hajlektalan/Documents/UNI_repos/grafika/graphics/temp/src/SimpleFragmentShader.glsl");

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE); // This is where you put stuffs
    do
    {
        glUseProgram(programID);
        triangleMaker();
        glfwSwapBuffers(window);
        glfwPollEvents();
    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

    glfwTerminate();
    return 0;
}
