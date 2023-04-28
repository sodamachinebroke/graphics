#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<stdbool.h>

int main(int argc, char const *argv[])
{
    glewExperimental = true;
    if (!glfwInit()){
            fprintf(stderr, "No can initiliaze GLFW\n");
            return 0;
    }
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window;

    window = glfwCreateWindow(1600, 900, "Tut1", NULL, NULL);
    if(window == NULL){
        fprintf(stderr, "Something bad happened, maybe GPU BAD????");
        glfwTerminate();
        return 0;
    }
    glfwMakeContextCurrent(window);
    glewExperimental = true;
    if(glewInit() != GLEW_OK)
    {
        fprintf(stderr, "GLEW no work:(");
        return 0;
    }

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    do{
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}
