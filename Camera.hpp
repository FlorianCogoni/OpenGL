#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

const GLfloat YAW         = -90.0f;
const GLfloat PITCH       =  0.0f;
const GLfloat SPEED       =  2.5f;
const GLfloat SENSITIVITY =  0.1f;
const GLfloat ZOOM        =  45.0f;


class Camera
{

private:
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;

    GLfloat Yaw;
    GLfloat Pitch;

    GLfloat MovementSpeed;
    GLfloat MouseSensitivity;
    GLfloat Zoom;

    void updateCameraVectors();

public:

    explicit Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), GLfloat yaw = YAW, GLfloat pitch = PITCH);

    Camera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw, GLfloat pitch);

    glm::mat4 GetViewMatrix();

    void ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime);

    void ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch = GL_TRUE);

    void ProcessMouseScroll(GLfloat yoffset);

    const glm::vec3 &getPosition() const;

    void setPosition(const glm::vec3 &Position);

    const glm::vec3 &getFront() const;

    void setFront(const glm::vec3 &Front);

    const glm::vec3 &getUp() const;

    void setUp(const glm::vec3 &Up);

    const glm::vec3 &getRight() const;

    void setRight(const glm::vec3 &Right);

    const glm::vec3 &getWorldUp() const;
    void setWorldUp(const glm::vec3 &WorldUp);

    GLfloat getYaw() const;

    void setYaw(GLfloat Yaw);

    GLfloat getPitch() const;

    void setPitch(GLfloat Pitch);

    GLfloat getMovementSpeed() const;

    void setMovementSpeed(GLfloat MovementSpeed);

    GLfloat getMouseSensitivity() const;

    void setMouseSensitivity(GLfloat MouseSensitivity);

    GLfloat getZoom() const;

    void setZoom(GLfloat Zoom);
};
#endif