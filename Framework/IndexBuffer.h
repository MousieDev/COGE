#ifndef _COGE_INDEXBUFF 
    
    #define _COGE_INDEXBUFF
    #include <stdio.h>
    #include "External/GLAD/gl.h"
    
    // Declaration
    typedef struct {
	const unsigned int * data;
	unsigned int size;
	int usage; 
	unsigned int ibo;
	unsigned int count;
    } IBO;
    
    void GenIBO(IBO *indexBuffer);
    void RmIBO(IBO *indexBuffer);
    void BindIBO(IBO *indexBuffer);
    void UnbindIBO();

    // Implementation
    void GenIBO(IBO * indexBuffer) {
	glGenBuffers(1, &indexBuffer -> ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer -> ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexBuffer -> size, indexBuffer -> data, indexBuffer -> usage);
	indexBuffer -> count = indexBuffer -> size / sizeof(unsigned int);
    }

    void RmIBO(IBO * indexBuffer) {
	glDeleteBuffers(1, &indexBuffer -> ibo);
    }

    void BindIBO(IBO * indexBuffer) {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer -> ibo);
    }

    void UnbindIBO() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

#endif
