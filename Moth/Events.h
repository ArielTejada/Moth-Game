#pragma once

namespace Moth 
{
	class KeyPressedEvent
	{
	public:
		KeyPressedEvent(int codeOfKey);
		KeyPressedEvent() = delete;

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

	class KeyReleasedEvent
	{
	public:
		KeyReleasedEvent(int codeOfKey);
		KeyReleasedEvent() = delete;

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};
}


