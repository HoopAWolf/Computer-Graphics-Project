#ifndef CAMERA_H
#define CAMERA_H

#include "Vector3.h"

class Camera
{
public:
	static Vector3 position;
	static Vector3 target;
	static Vector3 up;
	static Vector3 playerRight;
	static Vector3 view;

	int anchorX, anchorY;
	int WindowX, WindowY;

	Vector3 back;
	Vector3 playerLeft;

	Camera();
	~Camera();
	virtual void Init(const Vector3& pos, const Vector3& target, const Vector3& up);
	virtual void Reset();
	virtual void Update(double dt);
};

#endif