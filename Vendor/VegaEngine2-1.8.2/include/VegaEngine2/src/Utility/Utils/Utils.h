#pragma once
#include <SFML/Graphics.hpp>

namespace fz {

	class Utils
	{
	public:
		static sf::Vector2f SetOrigin(sf::Transformable& obj, Origins preset, const sf::FloatRect& rect);
		static sf::Vector2f SetOrigin(sf::Sprite& obj, Origins preset);
		static sf::Vector2f SetOrigin(sf::RectangleShape& obj, Origins preset);
		static sf::Vector2f SetOrigin(sf::Vector2f& vec2, Origins preset, const sf::Vector2f& size);

		static float Clamp(float value, float min, float max);
		static float Clamp01(float value);

		static float Lerp(float min, float max, float t, bool clamp = true);
		static sf::Vector2f Lerp(const sf::Vector2f& min, const sf::Vector2f& max, float t, bool clamp = true);
		static sf::Color Lerp(const sf::Color& min, const sf::Color& max, float t, bool clamp = true);

		static float SqrMagnitude(const sf::Vector2f& vec);
		static float Magnitude(const sf::Vector2f& vec);

		static void Normalize(sf::Vector2f& vec);
		static sf::Vector2f GetNormal(const sf::Vector2f& vec);
		static float Distance(const sf::Vector2f& p1, const sf::Vector2f& p2);

		static float RadianToDegree(float radian);
		static float DegreeToRadian(float degree);
		static float AngleRadian(const sf::Vector2f& vec);
		static float Angle(const sf::Vector2f& vec);
		static float GetAngleToCos(float degree);
		static float GetAngleToSin(float degree);

		static sf::Vector2f GetRotateVector(float angle, const sf::Vector2f& target);
		static const double GetPi();
		static bool CanFileOpen(const std::string& path);

	};

} // namespace fz