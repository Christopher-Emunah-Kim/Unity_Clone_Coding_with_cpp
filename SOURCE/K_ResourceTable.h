#pragma once
#include "K_Resource.h"

namespace KHS
{
	const wstring DEFAULT_RESOURCE_PATH = L"..\\Resources\\";

	class ResourceTable
	{
		
	public:
		template<typename T>
		static T* Find(const std::wstring& key)
		{
			auto iter = m_resouces.find(key);
			if (iter == m_resources.end())
				return nullptr;

			return dynamic_cast< T* >( iter->second );
		}

		template<typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			std::wstring combinedPath = DEFAULT_RESOURCE_PATH + path;

			T* resource = ResourceTable::Find<T>(key);

			if ( resource != nullptr )
			{
				return resource;
			}

			resource = new T();

			if (FAILED(resource->Load(combinedPath)))
			{
				delete resource;
				assert(false);
				return nullptr;
			}

			resource->SetName(key);
			resource->SetPath(combinedPath);
			m_resources.insert(std::make_pair(key, resource));

			return resource;
		}


	private:
		static std::map<std::wstring, Resource*> m_resources;
	};
}