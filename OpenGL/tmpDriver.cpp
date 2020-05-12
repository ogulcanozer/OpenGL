/*_______________________________________________________________________________
* Basic OpenGL Template/Framework for testing. | Ogulcan Ozer. | 11 May 2020    *
*                                                                               *
*   UNFINISHED.   Last updated : 12 May 2020                                    *
*                                                                               *
* Adapted from Yan Chernikov`s OpenGL tutorials.                                *
*_______________________________________________________________________________*/
#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <gl/glut.h>
#include "shader.h"
#include "vertexBuffer.h"
#include "vertexBufferLayout.h"
#include "indexBuffer.h"
#include "vertexArray.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include"texture.h"



int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK)
        std::cerr << "Error !" << std::endl;


    //Example
    //GLfloat position[] = {
    //    -0.5f , -0.5f , 0.0f, 0.0f,
    //     0.5f , -0.5f , 1.0f, 0.0f,
    //     0.5f ,  0.5f , 1.0f, 1.0f,
    //    -0.5f ,  0.5f , 0.0f, 1.0f
    //};
    //GLuint indices[] = {
    //    0, 1, 2,
    //    2, 3, 0
    //};

    //vertexArray va;
    //vertexBuffer vbo(position, 4 * 4 * sizeof(GLfloat), GL_STATIC_DRAW);
    //vertexBufferLayout vbl;
    //vbl.push<float>(2);
    //vbl.push<float>(2);
    //va.addLayout(vbo, vbl);
    //indexBuffer ibo(indices, 3 * 2 , GL_STATIC_DRAW);
    //shader program = shader("resources\\core.vs", "resources\\core.fs");
    //program.useShader();
    //glm::mat4 projection = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);
    //glm::mat4 view = glm::translate( glm::mat4(1.0f), glm::vec3(.0f, .0f, .0f));
    //program.setUniform4f("incolor", 1.0f, 0.0f, 1.0f, 1.0f);
    //va.unbind();
    //vbo.unbind();
    //ibo.unbind();
    //texture tx("resources\\img.png");
    //tx.bind();
    //program.setUniform1i("u_Texture", 0);
    //program.removeShader();
    //renderer r;
    //glm::vec3 translation(.0f,.0f,.0f);


    /*
    
        .INITIALIZE HERE.
        
    */










    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui::StyleColorsDark();


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
            
        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();


        //Example
        //r.clear();
        //program.useShader();
        //glm::mat4 model = glm::translate(glm::mat4(1.0f), translation);
        //glm::mat4 mvp = projection * view * model;
        //program.setUniformMat4f("mvp", mvp);
        //r.draw(va, ibo, program);
        //{
        //    ImGui::SliderFloat3("float", &translation.x, -4.0f, 4.0f);            
        //    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        //}

        /*
        
            .RENDER HERE.
        
        */





        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();

    return 0;
}
