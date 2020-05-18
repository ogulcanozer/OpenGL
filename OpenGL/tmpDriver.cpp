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
#include "texture.h"
#include "objLoader.h"
#include "exampleObjects.h"




int main(void)
{
#pragma region GLFW and GLEW INIT
    /**************GLFW and GLEW INIT****************/
    GLFWwindow* window;
    glewExperimental = GL_TRUE;
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); //Vsync on

    if (glewInit() != GLEW_OK)
        std::cerr << "Error !" << std::endl;

    /**************************************************/
#pragma endregion

#pragma region LOAD OBJECT
    objLoader o("resources\\donut.obj");
#pragma endregion

#pragma region INIT VAO, VBO, IBO and SHADER
    vertexArray va;
    vertexBuffer vbo(o.posTex.data(), o.posTex.size() * sizeof(GLfloat), GL_STATIC_DRAW);
    vertexBufferLayout vbl;
    vbl.push<float>(3);
    vbl.push<float>(2);
    va.addLayout(vbo, vbl);
    indexBuffer ibo(o.indices.data(), o.indices.size(), GL_STATIC_DRAW);
    shader program = shader("resources\\core.vs", "resources\\core.fs");
    program.useShader();
#pragma endregion

#pragma region INIT PROJ. MAT. AND UNIFORMS
    float rot_angleY = 0;
    float rot_angleX = 0;
    float radius = 10.0f;
    glm::mat4 projection = glm::perspective(100.0, -16.0 / 12.0, 0.01, 100.0);
    glm::vec3 translation(.0f, .0f, .0f);

    program.setUniform4f("incolor", 1.0f, 0.5f, 0.31f, 1.0f);
    va.unbind();
    vbo.unbind();
    ibo.unbind();
    //texture tx("resources\\tex.jpg");
    //tx.bind();
    //program.setUniform1i("u_Texture", 0);
    program.removeShader();
    renderer r;
#pragma endregion

#pragma region INIT IMGUI
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui::StyleColorsDark();
#pragma endregion

#pragma region RENDER LOOP
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

#pragma region START IMGUI and CLEAR
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        r.clear();
#pragma endregion

#pragma region SET MVP MAT. VALUES
        program.useShader();
        glm::mat4 rotationX = glm::rotate(glm::mat4(1.0f), glm::radians(rot_angleX), { 1.0f,0.0f,0.0f });
        glm::mat4 model = glm::translate(glm::mat4(1.0f), translation) * rotationX;
        float camPosX = sin(rot_angleY) * radius;
        float camPosZ = cos(rot_angleY) * radius;
        glm::mat4 view = glm::lookAt(glm::vec3(camPosX, 0.0, camPosZ), translation, glm::vec3(0.0f, 1.0f, 0.0f));
        glm::mat4 mvp = projection * view * model;
        program.setUniformMat4f("mvp", mvp);
#pragma endregion

#pragma region DRAW OBJ AND IMGUI
        /*Draw our objects*/
        r.draw(va, ibo, program);
        /*Set MVP variables with IMGUI*/
        ImGui::SliderFloat("v_RotateY", &rot_angleY, -3.0f, 3.0f);
        ImGui::SliderFloat("v_RotateX", &rot_angleX, -90.0f, 90.0f);
        ImGui::SliderFloat("v_RotateRadius", &radius, 0.1f, 10.0f);
        ImGui::SliderFloat3("t_Model", &translation.x, -15.0f, 0.1f);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        /*Draw IMGUI*/
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
#pragma endregion

#pragma region GLFW UPDATE
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
#pragma endregion



    }
#pragma endregion


#pragma region END IMGUI and GLFW
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();
#pragma endregion



    return 0;
}
