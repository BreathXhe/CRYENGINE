// Copyright 2001-2019 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include <IParameterConnection.h>
#include <PoolObject.h>
#include <CryAudio/IAudioInterfacesCommonData.h>

namespace CryAudio
{
namespace Impl
{
namespace Adx2
{
class CGameVariableAdvanced final : public IParameterConnection, public CPoolObject<CGameVariableAdvanced, stl::PSyncNone>
{
public:

	CGameVariableAdvanced() = delete;
	CGameVariableAdvanced(CGameVariableAdvanced const&) = delete;
	CGameVariableAdvanced(CGameVariableAdvanced&&) = delete;
	CGameVariableAdvanced& operator=(CGameVariableAdvanced const&) = delete;
	CGameVariableAdvanced& operator=(CGameVariableAdvanced&&) = delete;

	explicit CGameVariableAdvanced(
		char const* const szName,
		float const minValue,
		float const maxValue,
		float const multiplier,
		float const shift)
		: m_name(szName)
		, m_minValue(minValue)
		, m_maxValue(maxValue)
		, m_multiplier(multiplier)
		, m_shift(shift)
	{}

	virtual ~CGameVariableAdvanced() override = default;

	// IParameterConnection
	virtual void Set(IObject* const pIObject, float const value) override;
	virtual void SetGlobally(float const value) override;
	// ~IParameterConnection

private:

	CryFixedStringT<MaxControlNameLength> const m_name;
	float const m_minValue;
	float const m_maxValue;
	float const m_multiplier;
	float const m_shift;
};
} // namespace Adx2
} // namespace Impl
} // namespace CryAudio
