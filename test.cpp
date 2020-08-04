#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include<shader.h>
#include<math.h>
#include<vector>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include "camera2.h"
#include "base.h"
#include "population.h"
#include "axis.h"
#include "city.h"
#include "GL/gl.h"
#include "debug.h"
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 1000;
const unsigned int SCR_HEIGHT = 600;

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;
// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;


glm::vec3 positionR = glm::vec3(0.0f, 0.5f,1.5f);
glm::vec3 Up = glm::vec3(0.0f,1.0f,0.0f);
glm::vec3 Right = glm::vec3(1.0f,0.0f,0.0f);
glm::vec3 Front = glm::vec3(0.0f, 0.0f, -1.0f); // camera front

float xmin;
float xmax;
float ymin;
float ymax;


int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    //Shader ourShader("../camera.vs","../camera.fs");
    base mbase;
    city mcity;
    population mpopulation;
    axis maxis;
    debug mdebug;

    mbase.init();
    mcity.init();
    mpopulation.init();
    maxis.init();
    mdebug.init();

    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        //ourShader.use(); //glUseProgram(shaderProgram);
        // pass projection matrix to shader (note that in this case it could change every frame)
        //glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        float rate = (float)SCR_HEIGHT/SCR_WIDTH;
        xmin = positionR.x-positionR.z;  // displacement in x  initial = -0.1
        ymin = positionR.y-positionR.z;  // displacement in y  initial = -0.1
        xmax = positionR.x+positionR.z;   // INITIAL 1.5     zoom  , glm::radians(camera.Zoom)    instead
        ymax = (rate * (xmax -xmin)) + ymin;
        glm::mat4 projection = glm::ortho(xmin,xmax,ymin,ymax,5.5f,-0.6f); //glm::radians(camera.Zoom)
        //glViewport(0, 0, (float)SCR_WIDTH, (float)SCR_HEIGHT);
        glm::mat4 view = glm::lookAt(positionR, positionR + Front, glm::vec3(0.0f, 1.0f, 0.0f));
        view = projection*view;
        mbase.render(view);
        mcity.render(view);
        mpopulation.render(view);
        maxis.render(view);
        mdebug.render(view);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    mbase.done();
    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    float velocity = 0.1 * 2.5f * deltaTime;

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        //camera.ProcessKeyboard(FORWARD, deltaTime);
        positionR +=  Up * velocity;
    }
        
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        //camera.ProcessKeyboard(BACKWARD, deltaTime); 
        positionR  -= Up * velocity;
    }
        
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        //camera.ProcessKeyboard(LEFT, deltaTime);
        positionR  -= Right * velocity;
    }
        
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        //camera.ProcessKeyboard(RIGHT, deltaTime); 
        positionR  += Right * velocity;
    }
        

    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    {
        //camera.ProcessKeyboard(RIGHT, deltaTime); 
        //Front = 
        //Front = glm::normalize(positionR - glm::vec3( float((xmin+xmax)/2), float((ymin+ymax)/2), 0.0f ) );
        //positionR  -= Front * velocity * float(0.1);
        positionR  -= Front * velocity;
    }
    
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    {   
        //Front = glm::normalize(positionR - glm::vec3( float((xmin+xmax)/2), float((ymin+ymax)/2), 0.0f ));
        //positionR  -= Front * velocity * float(0.1);
        //camera.ProcessKeyboard(RIGHT, deltaTime); 
        positionR  += Front * velocity;
    }

    /*
    if (Zoom >= 1.0f && Zoom <= 45.0f)
            Zoom -= yoffset;
        if (Zoom <= 1.0f)
            Zoom = 1.0f;
        if (Zoom >= 45.0f)
            Zoom = 45.0f;
    */
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
    lastX = xpos;
    lastY = ypos;
    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);
}


