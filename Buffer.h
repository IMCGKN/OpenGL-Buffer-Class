#pragma once

enum BufferType
{
    VBO,
    EBO
};

#include <glm/glm.hpp>

struct Vertex
{
    glm::vec3 aPos;
    glm::vec3 aCol;
};

#include <glad/glad.h>

template<BufferType T>
class Buffer
{
private:
	unsigned int m_ID;

public:
	Buffer(const std::vector<Vertex>& vertices, unsigned int usage)
	{
		glGenBuffers(1, &m_ID);

		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), usage);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	Buffer(const std::vector<unsigned int>& indices, unsigned int usage)
	{
		glGenBuffers(1, &m_ID);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), usage);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	~Buffer()
	{
		glDeleteBuffers(1, &m_ID);
	}

	void Use()
	{
		unsigned int type = T == VBO ? GL_ARRAY_BUFFER : GL_ELEMENT_ARRAY_BUFFER;
		glBindBuffer(type, m_ID);
	}

	void Unuse()
	{
		unsigned int type = T == VBO ? GL_ARRAY_BUFFER : GL_ELEMENT_ARRAY_BUFFER;
		glBindBuffer(type, 0);
	}
};