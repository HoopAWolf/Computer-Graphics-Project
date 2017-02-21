#include "Camera3.h"
#include "Application.h"
#include "Mtx44.h"
#include "MatrixStack.h"
//Include GLEW
#include <GL/glew.h>
//Include GLFW
#include <GLFW/glfw3.h>
#include "PlayerBase.h"

#include <iostream>
#include "MapBase.h"

short mousePosYAnchor, mousePosXAnchor;
int windowX, windowY;

Camera3::Camera3()
{
	limitRotation = 0, mousePosXAnchor = 0, mousePosYAnchor = 0;
	ShowCursor(false);
	glfwGetWindowSize(Application::m_window, &windowX, &windowY);
}

Camera3::~Camera3()
{
}

void Camera3::Init(const Vector3& pos, const Vector3& target, const Vector3& up)
{
	this->position = defaultPosition = pos;
	this->target = defaultTarget = target;
	Vector3 view = (target - position).Normalized();
	Vector3 right = view.Cross(up);
	right.y = 0;
	right.Normalize();
	this->up = defaultUp = right.Cross(view).Normalized();
}

void Camera3::Update(double dt)
{
		static const float CAMERA_SPEED = 5.f, MOVING_SPEED = 40.f;
		glfwGetWindowSize(Application::m_window, &windowX, &windowY);

		Vector3 oldTarget = target;
		Vector3 view = (target - position).Normalized();
		Vector3 right = view.Cross(up);
		POINT p;
		GetCursorPos(&p);

		if (mousePosXAnchor == 0 && mousePosYAnchor == 0)
		{
			mousePosXAnchor = p.x;
			mousePosYAnchor = p.y;
		}

		if (limitRotation < .6 && p.y < mousePosYAnchor)
		{
			float pitch = (float)(CAMERA_SPEED * (mousePosYAnchor - p.y)) * .017f;
			Mtx44 rotation;
			rotation.SetToRotation(pitch, right.x, right.y, right.z);
			view = rotation * view;
			target = position + view;
			limitRotation = view.y;
		}
		else if (limitRotation > -.6 && p.y > mousePosYAnchor)
		{
			float pitch = (float)(-CAMERA_SPEED * (p.y - mousePosYAnchor)) * .017f;
			Mtx44 rotation;
			rotation.SetToRotation(pitch, right.x, right.y, right.z);
			view = rotation * view;
			target = position + view;
			limitRotation = view.y;
		}

		if (p.x < mousePosXAnchor)
		{
			float yaw = (float)(CAMERA_SPEED * (mousePosXAnchor - p.x)) * .017f;
			Mtx44 rotation;
			rotation.SetToRotation(yaw, up.x, up.y, up.z);
			view = rotation * view;
			target = position + view;
			rotationY += yaw;
		}
		else if (p.x > mousePosXAnchor)
		{
			float yaw = (float)(-CAMERA_SPEED * (p.x - mousePosXAnchor)) * .017f;
			Mtx44 rotation;
			rotation.SetToRotation(yaw, up.x, up.y, up.z);
			view = rotation * view;
			target = position + view;
			rotationY += yaw;
		}

		if (Application::IsKeyPressed('A'))
		{
			if (MapBase::instance()->checkingMapDataByCoord(PlayerBase::instance()->getDimension(),
				((int)(position.x - (right.x * MOVING_SPEED * dt))),
				position.z) != '#')
			{
				position.x = position.x - (right.x * MOVING_SPEED * dt);
			}

			if (MapBase::instance()->checkingMapDataByCoord(PlayerBase::instance()->getDimension(),
				position.x,
				((int)(position.z - (right.z * MOVING_SPEED * dt)))) != '#')
			{

				position.z = position.z - (right.z * MOVING_SPEED * dt);
			}

			target = position + view;
		}
		else if (Application::IsKeyPressed('D'))
		{
			if (MapBase::instance()->checkingMapDataByCoord(PlayerBase::instance()->getDimension(),
				((int)(position.x + (right.x * MOVING_SPEED * dt))),
				position.z) != '#')
			{
				position.x = position.x + (right.x * MOVING_SPEED * dt);
			}

			if (MapBase::instance()->checkingMapDataByCoord(PlayerBase::instance()->getDimension(),
				position.x,
				((int)(position.z + (right.z * MOVING_SPEED * dt)))) != '#')
			{
				position.z = position.z + (right.z * MOVING_SPEED * dt);
			}

			target = position + view;
		}

		if (Application::IsKeyPressed('W'))
		{

			if (MapBase::instance()->checkingMapDataByCoord(PlayerBase::instance()->getDimension(),
				((int)(position.x + (view.x * (MOVING_SPEED + ((PlayerBase::instance()->getPlayerState() == PlayerBase::instance()->SPRINTING) ? 20 : 0)) * dt))),
				position.z) != '#')
			{
				position.x = position.x + (view.x * (MOVING_SPEED + ((PlayerBase::instance()->getPlayerState() == PlayerBase::instance()->SPRINTING) ? 20 : 0)) * dt);
			}

			if (MapBase::instance()->checkingMapDataByCoord(PlayerBase::instance()->getDimension(),
				position.x,
				((int)(position.z + (view.z * MOVING_SPEED * dt)))) != '#')
			{
				position.z = position.z + (view.z * MOVING_SPEED * dt);
			}

			target = position + view;
		}
		else if (Application::IsKeyPressed('S'))
		{

			if (MapBase::instance()->checkingMapDataByCoord(PlayerBase::instance()->getDimension(),
				((int)(position.x - (view.x * MOVING_SPEED * dt))),
				position.z) != '#')
			{
				position.x = position.x - (view.x * MOVING_SPEED * dt);
			}

			if (MapBase::instance()->checkingMapDataByCoord(PlayerBase::instance()->getDimension(),
				position.x,
				((int)(position.z - (view.z * MOVING_SPEED * dt)))) != '#')
			{
				position.z = position.z - (view.z * MOVING_SPEED * dt);
			}

			target = position + view;
		}

		mousePosXAnchor = (windowX / 2);
		mousePosYAnchor = (windowY / 2);
		SetCursorPos((windowX / 2), (windowY / 2));
}

double Camera3::getRotationY()
{
	return rotationY;
}
