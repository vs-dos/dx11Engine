#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_
#include <windows.h>
#include "d3dclass.h"
#include "cameraclass.h"
#include "modelclass.h"
#include "colorshaderclass.h"


const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame(int,int);
	bool Render();

private:
	D3DClass* m_D3D;
	CameraClass* m_Camera;
	ModelClass* m_BarLeft;
	ModelClass* m_BarRight;
	ModelClass* m_Ball;
	XMFLOAT3 ballDirection;
	ColorShaderClass* m_ColorShader;
};
#endif