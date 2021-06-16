#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "3rd_party/GLAD/gl.h"
#include "Log.h"

/* Credits to: https://github.com/templalizer1284/cshader */

// read an entire file as const char*
const char* slurp_file(const char* filename) {
    // load the file
    FILE* f = fopen(filename, "r");
    const char* buffer;

    if (f == NULL ) {
        LogError("Unable to load file `%s`", filename);
    }
    // initialize the buffer size
    long buf_size;
    fseek(f, 0, SEEK_END);
    buf_size = ftell(f);
    buffer = (const char*)malloc(buf_size+1);
    rewind(f);
    int read = fread((char*)buffer, sizeof(const char*), buf_size, f);
    (void)read;
    // close the file
    fclose(f);
    return buffer;
}

// Load Shader from vertex and fragment shader files

unsigned int LS(const char * vsFileName, const char * fsFileName) {
    unsigned int vsID = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fsID = glCreateShader(GL_FRAGMENT_SHADER);

    char* vsCode = (char*)slurp_file(vsFileName);
    int vlength = strlen(vsCode);
    vsCode[vlength] = '0';

    char* fsCode = (char*)slurp_file(fsFileName);
    int flength = strlen(fsCode);
    fsCode[flength] = '0';

    const char *vsSource = vsCode;
    const char *fsSource = fsCode;

    int result = 0;
    int infoLogLength;

    glShaderSource(vsID, 1, &vsSource, &vlength);
    glCompileShader(vsID);

    glGetShaderiv(vsID, GL_COMPILE_STATUS, &result);
    glGetShaderiv(vsID, GL_INFO_LOG_LENGTH, &infoLogLength);

    if (infoLogLength > 0) {
        char errorMsg[infoLogLength + 1];
        glGetShaderInfoLog(vsID, infoLogLength, NULL, &errorMsg[0]);
        LogError("%s", &errorMsg[0]);
    }

    glShaderSource(fsID, 1, &fsSource, &flength);
    glCompileShader(fsID);

    glGetShaderiv(fsID, GL_COMPILE_STATUS, &result);
    glGetShaderiv(fsID, GL_INFO_LOG_LENGTH, &infoLogLength);

    if (infoLogLength > 0) {
        char errorMsg[infoLogLength + 1];
        glGetShaderInfoLog(fsID, infoLogLength, NULL, &errorMsg[0]);
        LogError("%s", &errorMsg[0]);
    }


    unsigned int programID = glCreateProgram();
    glAttachShader(programID, vsID);
    glAttachShader(programID, fsID);
    glLinkProgram(programID);

    glGetProgramiv(programID, GL_LINK_STATUS, &result);
    glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);

    if (infoLogLength > 0){
        char errorMsg[infoLogLength + 1];
        glGetProgramInfoLog(programID, infoLogLength, NULL, &errorMsg[0]);
        LogError("%s", &errorMsg[0]);
    }


    glDetachShader(programID, vsID);
    glDetachShader(programID, fsID);

    glDeleteShader(vsID);
    glDeleteShader(fsID);

    free(vsCode);
    free(fsCode);

    return programID;
}
