#ifndef _COGE_VERTEXARR 
    #define _COGE_VERTEXARR
    
    #include "External/GLAD/gl.h"

    // Declaration
    typedef struct {
	unsigned int vao;
    } VAO;

    void GenVAO(VAO *vao);
    void RmVAO(VAO *vao);
    void BindVAO(VAO *vao);
    void UnbindVAO();

    // Implementation
    void GenVAO(VAO * vao)  {
	glGenVertexArrays(1, &vao -> vao);
	glBindVertexArray(vao -> vao);
    } 

    void RmVAO(VAO * vao) {
	glDeleteVertexArrays(1, &vao -> vao);
    }

    void BindVAO(VAO * vao) {
	glBindVertexArray(vao -> vao);
    }

    void UnbindVAO() {
	glBindVertexArray(0);
    }

#endif
