#pragma once

#include "Core/Core.h"

namespace sf {
	class WindowBase;
}

namespace fz {

	enum class Axis
	{
		Horizontal,
		Vertical,
	};

	struct AxisInfo
	{
		Axis axis;
		std::list<int> positives;
		std::list<int> negatives;
		float sensi = 10.0f;
		float value = 0.0f;

		void AddKey(bool positive, int code)
		{
			if (positive)
				positives.push_back(code);
			else
				negatives.push_back(code);
		}
	};

	class InputManager
	{
	public:
		static void Init();
		static void Update(float dt);

		inline static bool IsKeyPressed(KeyType keycode) {
			return InputManager::IsKeyPressedImpl(keycode); 
		}
		inline static bool IsMouseButtonPressed(MouseButtonType button) {
			return InputManager::IsMouseButtonPressedImpl(button);
		}
		inline static sf::Vector2f GetMousePosition() {
			return InputManager::GetMousePositionImpl();
		}
		inline static void SetTargetTrackingWindow(sf::WindowBase* window) {
			s_TargetWindow = window;
		}

		static float GetAxisRaw(Axis axis);
		static float GetAxis(Axis axis);

	protected:
		static bool IsKeyPressedImpl(KeyType keycode);
		static bool IsMouseButtonPressedImpl(MouseButtonType button);
		static sf::Vector2f GetMousePositionImpl();
		static bool Contains(const std::list<int>& list, int code);

	private:
		static sf::WindowBase* s_TargetWindow;
		static std::unordered_map<Axis, AxisInfo> s_AxisInfoMap;
	};

	using Input = fz::InputManager;

} // namespace fz

