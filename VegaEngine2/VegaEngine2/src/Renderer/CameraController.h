#pragma once

namespace fz {

	class OrthoCamera;

	class CameraController
	{
	public:
		CameraController(const std::string& name, const sf::Vector2f& size, bool rotation = false);

		void SetViewport(float x, float y, float width, float height);
		void OnUpdate(float dt);
		void OnEvent(Event& e);
		OrthoCamera& GetOrthoCamera();

	private:
		bool OnMouseScrolled(MouseScrolledEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);
		bool OnMouseButtonPressed(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleased(MouseButtonReleasedEvent& e);
		bool OnMouseMoved(MouseMovedEvent& e);

	private:
		float m_CameraMoveSpeed;
		float m_CameraRotateSpeed;
		float m_CameraZoomFactor;
		sf::Vector2f m_MousePrevPos;
		sf::Vector2f m_MousePos;
		bool m_IsMouseButtonPressed;
		bool m_ActivatedRotation;
		Shared<OrthoCamera> m_Camera;
	};


} // namespace fz