#include "CommonInclude.h"

namespace KHS
{
	class Entity
	{
	public:
		Entity()
			:m_name(L" ")
		{
		}

		virtual ~Entity() = default;

		void SetName(const std::wstring& name) { m_name = name; }
		std::wstring& GetName() { return m_name; }

	private:
		std::wstring m_name;
	};
}