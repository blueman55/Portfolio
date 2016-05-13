#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/gl.h>

void Draw()
{
	int i;
	int j;
	int n;
	int Array[4][4];
	
	//for(i = 0; i <= 4; i++)
	//{
	//	for(j = 0; j <= 4; j++)
	//	{
	//		Array[i][j] = i*j*j*0.5;
	//	}
	//}
	
	for(i = -10; i <= 10; i++)
	{

		glBegin(GL_TRIANGLE_STRIP);

	//for(i = 0; i <= 4; i++)
	//{
			for(j = -10; j <= 10; j++)
			{		
				glVertex3f(i,j,-20+i*j*j*0.01);
				glVertex3f(i+1,j,-20+i*j*j*0.01);
			}
	//}

		glEnd();
		glPopMatrix();	
	}
}
static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	printf("pos x:%lf\n", xpos);
        printf("pos y:%lf\n", ypos);



	float m[4][4] = 
	{
			{1,0,0,0},
			{0,cos(ypos/10000),sin(ypos/10000),0},
			{0,-sin(ypos/10000),cos(ypos/10000),0},
			{0,0,0,1}
	};
	glMultMatrixf(&m[0][0]);
}
static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    if (key == GLFW_KEY_W && (action == GLFW_REPEAT || action == GLFW_PRESS))
    {
        float m[4][4] = 
	{
			{1,0,0,0},
			{0,1,0,0},
			{0,0,1,0},
			{0,0,1,1}
	};
	glMultMatrixf(&m[0][0]);
    }
if (key == GLFW_KEY_S && (action == GLFW_REPEAT || action == GLFW_PRESS))
    {
        float m[4][4] = 
	{
			{1,0,0,0},
			{0,1,0,0},
			{0,0,1,0},
			{0,0,-1,1}
	};
	glMultMatrixf(&m[0][0]);
    }
if (key == GLFW_KEY_A && (action == GLFW_REPEAT || action == GLFW_PRESS))
    {
        float m[4][4] = 
	{
			{1,0,0,0},
			{0,1,0,0},
			{0,0,1,0},
			{1,0,0,1}
	};
	glMultMatrixf(&m[0][0]);
    }
if (key == GLFW_KEY_D && (action == GLFW_REPEAT || action == GLFW_PRESS))
    {
        float m[4][4] = 
	{
			{1,0,0,0},
			{0,1,0,0},
			{0,0,1,0},
			{-1,0,0,1}
	};
	glMultMatrixf(&m[0][0]);
    }
}
int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);

    glfwSetCursorPosCallback(window, cursor_position_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); //*****************************

    while (!glfwWindowShouldClose(window))
    {
	glClear(GL_COLOR_BUFFER_BIT);
	/*glLoadIdentity();
	float m[4][4] = 
	{
			{1,0,0,0},
			{0,1,0,0},
			{0,0,1,0},
			{cos(glfwGetTime()),sin(glfwGetTime()),0,1}
	};
	glMultMatrixf(&m[0][0]);*/
	Draw();
	
        //float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        //ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
	glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 90.0);
        //glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}
