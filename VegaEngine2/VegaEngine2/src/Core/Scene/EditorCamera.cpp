#include "pch.h"
#include "EditorCamera.h"

namespace fz {

	EditorCamera::EditorCamera(const sf::Vector2f& size, bool rotation)
		: m_CameraMoveSpeed(500.f)
		, m_CameraRotateSpeed(100.f)
		, m_CameraZoomFactor(1.0f)
		, m_MousePrevPos(0.0f, 0.0f)
		, m_MousePos(0.0f, 0.0f)
		, m_IsMouseButtonPressed(false)
		, m_ActivatedRotation(rotation)
		, m_Camera(nullptr)
	{
		sf::Vector2f pos{ size.x * 0.5f, size.y * 0.5f };
		m_Camera = CreateShared<fz::OrthoCamera>(pos, size);
	}

	void EditorCamera::SetSize(float width, float height)
	{
		m_Camera->SetSize(width, height);
	}

	void EditorCamera::SetViewport(float x, float y, float width, float height)
	{
		if ((x >= width) || (y >= height))
		{
			return;
		}
		sf::FloatRect rect;
		rect.left = x / width;
		rect.top = y / height;
		rect.width = (x + width) / width;
		rect.height = (y + height) / height;
		m_Camera->SetViewport(rect);
	}

	void EditorCamera::OnUpdate(float dt)
	{
		if (!m_ActivatedController)
			return;

		if (InputManager::IsKeyPressed(KeyType::A))
			m_Camera->Move(m_CameraMoveSpeed * -1.0f * dt, 0.0f);
		else if (InputManager::IsKeyPressed(KeyType::D))
			m_Camera->Move(m_CameraMoveSpeed * dt, 0.0f);

		if (InputManager::IsKeyPressed(KeyType::W))
			m_Camera->Move(0.0f, m_CameraMoveSpeed * -1.0f * dt);
		else if (InputManager::IsKeyPressed(KeyType::S))
			m_Camera->Move(0.0f, m_CameraMoveSpeed * dt);

		if (m_ActivatedRotation)
		{
			if (InputManager::IsKeyPressed(KeyType::Q))
				m_Camera->Rotate(m_CameraRotateSpeed * dt);
			else if (InputManager::IsKeyPressed(KeyType::E))
				m_Camera->Rotate(m_CameraRotateSpeed * -1.0f * dt);
		}
	}

	void EditorCamera::OnEvent(Event& e)
	{
		EventDispatcher dis(e);
		dis.Dispatch<MouseScrolledEvent>(BIND_EVENT_FUNC(EditorCamera::OnMouseScrolled));
		dis.Dispatch<WindowResizeEvent>(BIND_EVENT_FUNC(EditorCamera::OnWindowResized));
		dis.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FUNC(EditorCamera::OnMouseButtonPressed));
		dis.Dispatch<MouseButtonReleasedEvent>(BIND_EVENT_FUNC(EditorCamera::OnMouseButtonReleased));
		dis.Dispatch<MouseMovedEvent>(BIND_EVENT_FUNC(EditorCamera::OnMouseMoved));
	}

	OrthoCamera& EditorCamera::GetOrthoCamera()
	{
		return *m_Camera;
	}

	void EditorCamera::SetActivated(bool enabled)
	{
		m_ActivatedController = enabled;
	}

	bool EditorCamera::OnMouseScrolled(MouseScrolledEvent& e)
	{
		if (!m_ActivatedController)
			return false;

		float offset = e.GetYOffset();
		if (offset < 0)
		{
			m_CameraZoomFactor += 0.05f;
			m_Camera->Zoom(m_CameraZoomFactor);
		}
		else
		{
			m_CameraZoomFactor -= 0.05f;
			m_Camera->Zoom(m_CameraZoomFactor);
		}
		return false;
	}

	bool EditorCamera::OnWindowResized(WindowResizeEvent& e)
	{
		m_Camera->SetSize((float)e.GetWidth(), (float)e.GetHeight());
		return false;
	}

	bool EditorCamera::OnMouseButtonPressed(MouseButtonPressedEvent& e)
	{
		if (e.GetMouseButton() == MouseButtonType::Left)
		{
			m_IsMouseButtonPressed = true;
		}

		return false;
	}

	bool EditorCamera::OnMouseButtonReleased(MouseButtonReleasedEvent& e)
	{
		if (e.GetMouseButton() == MouseButtonType::Left)
		{
			m_IsMouseButtonPressed = false;
		}
		return false;
	}

	bool EditorCamera::OnMouseMoved(MouseMovedEvent& e)
	{
		m_MousePrevPos = m_MousePos;
		m_MousePos.x = e.GetX();
		m_MousePos.y = e.GetY();
		if (m_IsMouseButtonPressed && m_ActivatedController)
		{
			float dx = (m_MousePos.x - m_MousePrevPos.x) * -1.0f;
			float dy = (m_MousePos.y - m_MousePrevPos.y) * -1.0f;
			const sf::Vector2f& cenPos = m_Camera->GetCenter();
			m_Camera->SetCenter(cenPos.x + dx, cenPos.y + dy);
		}
		return false;
	}

} // namespace fz