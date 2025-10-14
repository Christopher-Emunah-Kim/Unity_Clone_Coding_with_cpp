#include "K_ResourceTable.h"
#include "K_Resource.h"

namespace KHS
{
	std::map<std::wstring , Resource*> ResourceTable::m_resources{};
}