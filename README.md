# OpenGL-Buffer-Class
Dynamic Buffer Class for OpenGL.


USAGE:

std::unique_ptr<Buffer< VBO >> m_VBO; // Creating VBO.

std::unique_ptr<Buffer< EBO >> m_EBO; // Creating EBO.

m_VBO->Use(); // Using this buffer before some draw call.
