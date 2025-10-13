#pragma once
#include "K_Entity.h"

namespace KHS
{

	class Resource abstract : public Entity
	{
	public:
		Resource() = delete;
		Resource(EResourceType type)
			: m_type(type) , m_path(L"")
		{

		}

		virtual ~Resource() {}

		//HRESULT : 0 is S_OK, negative value is fail, positive value is warning
		virtual HRESULT Load(const std::wstring& path) = 0; 
		
		inline const std::wstring& GetPath() { return m_path; }
		inline void SetPath(const std::wstring& path) { m_path = path; }

	private:
		const EResourceType m_type;
		std::wstring m_path;
	};

}

