#include "CameraController.h"



CameraController::CameraController()
{
}


CameraController::~CameraController()
{
}

void CameraController::update(Camera & a_camera, GLfloat a_dt)
{
	// check for use input
	keyPress(a_camera, a_dt);
	mouseMovement(a_camera);
	mouseClick(a_camera);
	// update camera after input updates
	a_camera.update(a_dt);
}

void CameraController::keyPress(Camera & a_camera, GLfloat a_dt)
{
	if (m_bKeys[GLFW_KEY_W])
		a_camera.moveForward(a_dt);
	if (m_bKeys[GLFW_KEY_S])
		a_camera.moveBack(a_dt);
	if (m_bKeys[GLFW_KEY_A])
		a_camera.moveLeft(a_dt);
	if (m_bKeys[GLFW_KEY_D])
		a_camera.moveRight(a_dt);
}

void CameraController::mouseMovement(Camera & a_camera)
{
	// Update Camera Pitch
	if (m_fOldYoffset != m_fYoffset) {
		a_camera.pitchUpdate(m_fYoffset * m_fMouseSpeed);
		m_fOldYoffset = m_fYoffset;
	}
	// Update Camera Yaw
	if (m_fOldXoffset != m_fXoffset) {
		a_camera.yawUpdate(m_fXoffset * m_fMouseSpeed);
		m_fOldXoffset = m_fXoffset;
	}
}

void CameraController::mouseClick(Camera & a_camera)
{
}
