#include "Camera.hpp"

void Camera::updateCameraVectors()
{
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front = glm::normalize(front);
    Right = glm::normalize(glm::cross(Front, WorldUp));
    Up    = glm::normalize(glm::cross(Right, Front));
}

Camera::Camera(glm::vec3 position, glm::vec3 up, GLfloat yaw, GLfloat pitch)
        : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
{
    Position = position;
    WorldUp = up;
    Yaw = yaw;
    Pitch = pitch;
    updateCameraVectors();
}

Camera::Camera (GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw, GLfloat pitch)
        : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
{
    Position = glm::vec3(posX, posY, posZ);
    WorldUp = glm::vec3(upX, upY, upZ);
    Yaw = yaw;
    Pitch = pitch;
    updateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(Position, Position + Front, Up);
}

void Camera::ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime)
{
    GLfloat velocity = MovementSpeed * deltaTime;
    if (direction == FORWARD)
        Position += Front * velocity;
    if (direction == BACKWARD)
        Position -= Front * velocity;
    if (direction == LEFT)
        Position -= Right * velocity;
    if (direction == RIGHT)
        Position += Right * velocity;
}

void Camera::ProcessMouseMovement (GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch)
{
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;

    Yaw   += xoffset;
    Pitch += yoffset;

    // Make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (Pitch > 89.0f)
            Pitch = 89.0f;
        if (Pitch < -89.0f)
            Pitch = -89.0f;
    }
    updateCameraVectors();
}

void Camera::ProcessMouseScroll (GLfloat yoffset)
{
    if (Zoom >= 1.0f && Zoom <= 45.0f)
        Zoom -= yoffset;
    if (Zoom <= 1.0f)
        Zoom = 1.0f;
    if (Zoom >= 45.0f)
        Zoom = 45.0f;
}

const glm::vec3 & Camera::getPosition() const {
    return Position;
}

void Camera::setPosition(const glm::vec3 &Position) {
    Camera::Position = Position;
}

const glm::vec3 & Camera::getFront() const {
    return Front;
}

void Camera::setFront(const glm::vec3 &Front) {
    Camera::Front = Front;
}

const glm::vec3 & Camera::getUp() const {
    return Up;
}

void Camera::setUp(const glm::vec3 &Up) {
    Camera::Up = Up;
}

const glm::vec3 & Camera::getRight() const {
    return Right;
}

void Camera::setRight(const glm::vec3 &Right) {
    Camera::Right = Right;
}

const glm::vec3 & Camera::getWorldUp() const {
    return WorldUp;
}

void Camera::setWorldUp(const glm::vec3 &WorldUp) {
    Camera::WorldUp = WorldUp;
}

GLfloat Camera::getYaw() const {
    return Yaw;
}

void Camera::setYaw(GLfloat Yaw) {
    Camera::Yaw = Yaw;
}

GLfloat Camera::getPitch() const {
    return Pitch;
}

void Camera::setPitch(GLfloat Pitch) {
    Camera::Pitch = Pitch;
}

GLfloat Camera::getMovementSpeed() const {
    return MovementSpeed;
}

void Camera::setMovementSpeed(GLfloat MovementSpeed) {
    Camera::MovementSpeed = MovementSpeed;
}

GLfloat Camera::getMouseSensitivity() const {
    return MouseSensitivity;
}

void Camera::setMouseSensitivity(GLfloat MouseSensitivity) {
    Camera::MouseSensitivity = MouseSensitivity;
}

GLfloat Camera::getZoom() const {
    return Zoom;
}

void Camera::setZoom(GLfloat Zoom) {
    Camera::Zoom = Zoom;
}