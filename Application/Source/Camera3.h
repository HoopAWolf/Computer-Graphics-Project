#ifndef CAMERA_3_H
#define CAMERA_3_H

#include "Camera.h"
#include <windows.h>

class Camera3 : public Camera
{
public:
	Vector3 defaultPosition;
	Vector3 defaultTarget;
	Vector3 defaultUp;
	Vector3 right;

	short mousePosYAnchor, mousePosXAnchor;
	double limitRotation, rotationY = 0, rotationZ = 0;

	Camera3();
	~Camera3();

	virtual void Init(const Vector3& pos, const Vector3& target, const Vector3& up);
	virtual void Update(double dt);
	double getRotationY();
	double getRotationZ();

};

#endif