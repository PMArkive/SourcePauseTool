#pragma once

#ifdef OE
#include "vector.h"
#else
#include "mathlib\vector.h"
#endif

#include "..\strafe\strafestuff.hpp"

namespace aim
{
	enum class InterpType
	{
		LINEAR = 0,
		SINE,
		CUBIC,
		EXPONENTIAL,
	};

	// Returns false if the string is not a recognized interp type name.
	bool ParseInterpType(const char* str, InterpType& out);

	struct ViewState
	{
		enum AimState
		{
			NO_AIM,
			ANGLES,
			POSITION,
			ENTITY,
		};
		AimState state;

		QAngle current;
		QAngle target;

		Vector targetPos;
		int targetID;

		int ticksLeft;
		int totalTicks;
		bool timedChange;
		bool jumpedLastTick;

		InterpType interpolationType;

		ViewState();
		float CalculateNewYaw(float newYaw, const Strafe::StrafeInput& strafeInput);
		float CalculateNewPitch(float newPitch, const Strafe::StrafeInput& strafeInput);
		void UpdateView(float& pitch, float& yaw, const Strafe::StrafeInput& strafeInput);
		void SetJump();
	};

	void GetAimAngleIterative(const QAngle& target, QAngle& current, int commandOffset, const Vector& vecSpread);
	bool GetCone(int cone, Vector& out);
	QAngle DecayPunchAngle(QAngle m_vecPunchAngle, QAngle m_vecPunchAngleVel, int frames);
} // namespace aim
