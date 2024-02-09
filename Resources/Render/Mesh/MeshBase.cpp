#include "MeshBase.h"
#include "Glad/GladMesh.h"
#include <Debug/Debugger.h>

MeshBase* MeshBase::GetMeshBasedOnAPI(RenderAPI api, MeshData& data)
{
	switch (api)
	{
	case RenderAPI::None:
		return nullptr;
		break;
	case RenderAPI::Gl220:
		return new GladMesh(data);
		break;
	case RenderAPI::Gl330:
		return new GladMesh(data);
		break;
	case RenderAPI::Gl440:
		return new GladMesh(data);
		break;
	case RenderAPI::Gl460:
		return new GladMesh(data);
		break;
	}

}

MeshBase::~MeshBase()
{
	Log("deleeeeete");
}
