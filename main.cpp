// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
// #include <iostream>
// #include <cmath>

// /*function declarations*/
// void framebuffer_size_callback(GLFWwindow *window, int width, int height);
// void processInput(GLFWwindow *window);
// /***********************/

// /*vertex shader*/
// const char *vertexShaderSource = "#version 330 core\n"
//                                  "layout (location = 0) in vec3 aPos;\n"
//                                  "layout (location = 1) in vec3 aColor;\n"
//                                  "out vec3 ourColor;\n"
//                                  "void main()\n"
//                                  "{\n"
//                                  "  gl_Position = vec4(aPos, 1.0);\n"
//                                  "  ourColor = aColor;\n"
//                                  "}\0";
// /**************/

// /*fragment shader*/
// const char *fragmentShaderSource = "#version 330 core\n"
//                                   "out vec4 FragColor;\n"
//                                   "in vec3 ourColor;\n"
//                                   "void main()\n"
//                                   "{\n"
//                                   "   FragColor = vec4(ourColor, 1.0f);\n"
//                                   "}\0";
// /*****************/

// int main()
// {
//     /*GLFW/window conifig and initialization*/
//     if (!glfwInit())
//     {
//         std::cerr << "Failed to start GLFW" << std::endl;

//         return -1;
//     }

//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

//     GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
//     if (window == NULL)
//     {
//         std::cerr << "Failed to create GLFW window" << std::endl;
//         glfwTerminate();

//         return -1;
//     }

//     glfwMakeContextCurrent(window);
//     /****************************************/

//     /*initializing glad*/
//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//     {
//         std::cerr << "Failed to initialize GLAD" << std::endl;
//         glfwDestroyWindow(window);
//         glfwTerminate();

//         return -1;
//     }
//     /*******************/

//     glViewport(0, 0, 800, 600);
//     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

//     float vertices[] = {
//         -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
//          0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
//          0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
//     };  

//     unsigned int VAO, VBO;
//     glGenVertexArrays(1, &VAO); 
//     glGenBuffers(1, &VBO);

//     glBindVertexArray(VAO);

//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//     glEnableVertexAttribArray(0);
//     glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
//     glEnableVertexAttribArray(1);
//     glEnableVertexAttribArray(1);

//     unsigned int vertexShader;
//     vertexShader = glCreateShader(GL_VERTEX_SHADER);
//     glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//     glCompileShader(vertexShader);
//     int success;
//     char infoLog[512];
//     glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//     if (!success) {
//         glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//         std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//     }

//     unsigned int fragmentShader;
//     fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//     glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//     glCompileShader(fragmentShader);
//     glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//     if (!success) {
//         glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//         std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//     }

//     unsigned int shaderProgram;
//     shaderProgram = glCreateProgram();
//     glAttachShader(shaderProgram, vertexShader);
//     glAttachShader(shaderProgram, fragmentShader);
//     glLinkProgram(shaderProgram);
//     glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//     if(!success) {
//         glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//         std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
//     }

//     glDeleteShader(vertexShader);
//     glDeleteShader(fragmentShader);

//     while (!glfwWindowShouldClose(window))
//     {
//         /*inputs*/
//         processInput(window);
//         /********/

//         /*rendering*/
//         glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT);

//         // draws triangle
//         glUseProgram(shaderProgram);
        
//         glBindVertexArray(VAO);
//         glDrawArrays(GL_TRIANGLES, 0, 3);

//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }

//     glDeleteVertexArrays(1, &VAO);
//     glDeleteBuffers(1, &VBO);

//     glfwDestroyWindow(window);
//     glfwTerminate();

//     return 0;
// }

// /*function definitions*/
// void framebuffer_size_callback(GLFWwindow *window, int width, int height)
// {
//     glViewport(0, 0, width, height);
// }

// void processInput(GLFWwindow *window)
// {
//     if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//     {
//         glfwSetWindowShouldClose(window, true);
//     }
// }

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

/*function declarations*/
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);
/***********************/

/*vertex shader*/
const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "out vec4 vertexColor;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos, 1.0);\n"
                                 "vertexColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);\n"
                                 "}\0";
/**************/

/*fragment shader*/
const char *fragmentShaderSource = "#version 330 core\n"
                                  "out vec4 FragColor;\n"
                                  "uniform vec4 ourColor;\n"
                                  "void main()\n"
                                  "{\n"
                                  "   FragColor = ourColor;\n"
                                  "}\0";
/*****************/

int main()
{

    bool isBlue = false;

    /*GLFW/window conifig and initialization*/
    if (!glfwInit())
    {
        std::cerr << "Failed to start GLFW" << std::endl;

        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();

        return -1;
    }

    glfwMakeContextCurrent(window);
    /****************************************/

    /*initializing glad*/
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();

        return -1;
    }
    /*******************/

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };  

    unsigned int VAO, VBO;
    glGenVertexArrays(1, &VAO); 
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    while (!glfwWindowShouldClose(window))
    {
        /*inputs*/
        processInput(window);
        /********/

        /*rendering*/
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draws triangle
        glUseProgram(shaderProgram);
        
        int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");

        if (!isBlue) {
            glUniform4f(vertexColorLocation, 1.0f, 0.0f, 0.0f, 1.0f);
            isBlue = true;
        } else {
            glUniform4f(vertexColorLocation, 0.0f, 0.0f, 1.0f, 1.0f);
            isBlue = false;
        }

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

/*function definitions*/
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}
