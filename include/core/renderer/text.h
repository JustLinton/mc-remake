#ifndef TEXT_RENDER_H
#define TEXT_RENDER_H

#include <iostream>
#include <map>
#include <string>

#include <core/root_context.h>
#include <core/font.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <graphics/shader.h>

#include <bits/stdc++.h>
using namespace std;

void renderTexts(RootContext *rootContext){
    rootContext->shaders["text"]->use();
    RenderText(*rootContext->shaders["text"], version_string, 15.0f, (float)SCR_HEIGHT - 30.0f, 0.38f, glm::vec3(1.0f, 1.0f, 1.0f));
}

void renderTextFPS(RootContext *rootContext, const float* deltaTime, const float* accTime){
    static float lastTime = 0.0f;
    static string lastFpsStr = "0.0";
    static float lastFpsOneSec = 0.0f;
    static int lastFpsDataCountOneSec = 0;
    float fps = 1.0f / &deltaTime;
    lastFpsOneSec += fps;
    lastFpsDataCountOneSec += 1;
    if(*accTime - lastTime >= 1.0f){
        lastTime = *accTime;
        stringstream sst;
        sst << lastFpsOneSec / lastFpsDataCountOneSec;
        sst >> lastFpsStr;
        lastFpsOneSec = 0.0f;
        lastFpsDataCountOneSec = 0;
        lastFpsStr = "FPS> "+ lastFpsStr;
    }

    rootContext->shaders["text"]->use();
    RenderText(*rootContext->shaders["text"], lastFpsStr, 15.0f, (float)SCR_HEIGHT - 55.0f, 0.38f, glm::vec3(1.0f, 1.0f, 1.0f));
}

#endif