#pragma once

namespace fz {

	/*
	* @brief 개별적인 기능을 담당하는 static 함수들을 모아놓은 클래스
	* @details
	* - 모든 멤버들은 static 선언, 정의가 되어있습니다.
	* - 모든 값은 임시 값으로 반환됩니다.
	* - 인자인 모든 데이터는 변경되지 않습니다.
	*/
	class Random_internal final
	{
	public:
		static Random_internal& GetInstance();	/*< Random의 인스턴스를 리턴합니다. */

		/*
		* @brief 랜덤 값을 리턴합니다.
		* @param[in] int start: 범위 시작 값
		* @param[in] int end: 범위 끝 값
		* @return int: 범위안의 값을 균일 분포로 랜덤 값을 리턴합니다.
		*/
		int operator()(int min, int max);
		/*
		* @brief 랜덤 값을 리턴합니다.
		* @param[in] float start: 범위 시작 값
		* @param[in] float end: 범위 끝 값
		* @return float: 범위안의 값을 균일 분포로 랜덤 값을 리턴합니다.
		*/
		float operator()(float min, float max);

		/*
		* @brief 360도 범위안의 랜덤한 위치(0.0f ~ 1.0f)를 반환합니다.
		* @return fz::Vec2f: 360도 범위 안의 랜덤 위치(0.0f ~ 1.0f)
		*/
		fz::Vec2f InUnitCircle() const;
		/*
		* @brief 360도 범위안의 랜덤한 위치(0.0f ~ 1.0f)를 반환합니다.
		* @return fz::Vec2f: 360도 범위 안의 랜덤 위치(0.0f ~ 1.0f)
		*/
		fz::Vec2f InUnitCircle();

	private:
		static const float s_PI;	/*< 파이값 */
	};

	/*< Random_internal 접근 인스턴스 */
	static Random_internal& Random = Random_internal::GetInstance();

} // namespace fz
