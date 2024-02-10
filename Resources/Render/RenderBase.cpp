#include "RenderBase.h"
#include "Glad/RenderGlad.h"
#include <Debug/Debugger.h>

RenderBase* RenderBase::GetRenderBasedOnApi(RenderAPI api)
{
	switch (api)
	{
	case RenderAPI::None:
		return nullptr;
		break;
	case RenderAPI::GL220:
		return new RenderGlad();
		break;
	case RenderAPI::GL330:
		return new RenderGlad();
		break;
	case RenderAPI::GL440:
		return new RenderGlad();
		break;
	case RenderAPI::GL460:
		return new RenderGlad();
		break;
	default:
		ErrorLog("Strange Render API");
		break;
	}
}
