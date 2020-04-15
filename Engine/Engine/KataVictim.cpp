#include "KataVictim.h"


KataVictim::KataVictim()
{
	m_Model = 0;
	m_HasParent = false;
}

KataVictim::~KataVictim()
{
}

void KataVictim::Load()
{
	Gameobject::Load();
	// Release the model object.
	if (m_Model)
	{
		m_Model->Shutdown();
		delete m_Model;
		m_Model = 0;
	}
}

void KataVictim::Unload()
{
	Gameobject::Unload();
	// Release the model object.
	if (m_Model)
	{
		m_Model->Shutdown();
		delete m_Model;
		m_Model = 0;
	}
}

bool KataVictim::Init(HWND hwnd, D3DClass* d3d)
{
	bool result;
	Gameobject::Init(hwnd, d3d);
	m_Model = new ModelClass();
	if (!m_Model)
	{
		return false;
	}
	// Initialize the model.
	result = m_Model->Initialize(Gameobject::m_D3D->GetDevice(), "Data\\Objects\\m_cube.obj", L"../Engine/baseColor.tga");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize model.", L"Error", MB_OK);
		return false;
	}
	m_Scale = XMMatrixScaling(0.75f, 0.75f, 0.75f);
	return result;
}

bool KataVictim::Update()
{
	return false;
}

bool KataVictim::Update(Katamari* k)
{

	m_Transform->trs = m_Scale * m_Translation * k->m_Rotation * k->m_Translation;
	return true;
}

void KataVictim::AttachTo(Gameobject* go)
{
	m_HasParent = true;
	m_ParentTRS = go->m_Transform->trs;

	Vector3 d = Distance(go);

	m_Translation = XMMatrixTranslation(d.x,0.0f, d.z);
}

void KataVictim::Place(Vector3 pos)
{
	m_Translation.Translation(pos);
	m_Transform->trs = m_Translation * m_Scale;
}



