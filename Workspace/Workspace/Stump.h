#pragma once
#include <VegaEngine2.h>
#include "FSM.h"

namespace fz {

	class Stump : public VegaScript, public MonsterFSM
	{
	public:
		float JumpPower = -500.f;
		float MoveSpeed = 100.f;

		Animator animator;
		AnimationClip idle;
		AnimationClip move;
		AnimationClip damaged;
		AnimationClip die;

		TransformComponent* transform;
		RigidbodyComponent* body;

		void Start() override
		{
			transform = &GetComponent<TransformComponent>();
			body = &GetComponent<RigidbodyComponent>();
			sf::Sprite& sprite = GetComponent<SpriteComponent>();
			animator.SetTarget(sprite, *transform);
			animator.SetSpeed(1.0f);
			idle.loadFromFile("game/animations/Stump_idle.anim");
			move.loadFromFile("game/animations/Stump_move.anim");
			damaged.loadFromFile("game/animations/Stump_damaged.anim");
			die.loadFromFile("game/animations/Stump_die.anim");
			body->SetGravityScale(1.5f);
		}

		void OnDestroy() override
		{
			FZLOG_DEBUG("������ ��ũ��Ʈ �ı�! {0} {1}", 1.1, "aSDAdacSCA");
		}

		void OnUpdate(float dt) override
		{
			if (!HasComponent<RigidbodyComponent>())
				return;

			animator.Update(dt);

			// �̵� ����
			if (Input::IsKeyPressed(KeyType::D))
			{
				this->Move(Directions::RIGHT);
			}
			else if (Input::IsKeyPressed(KeyType::A))
			{
				this->Move(Directions::LEFT);
			}
			else if (Input::IsKeyPressed(KeyType::Q))
			{
				this->Damaged();
			}
			else if (Input::IsKeyPressed(KeyType::W))
			{
				this->Die();
			}

			else
			{
				this->Idle();
			}
			// ���� game/animations/
			if (Input::IsKeyDown(KeyType::Space))
			{
				this->Jump();
			}



		}

		void Idle() override
		{
			animator.Play(&idle);
		}

		void Move(Directions dir) override
		{
			fz::Transform& transform = GetComponent<TransformComponent>();
			// �̵� ����
			if (dir == Directions::RIGHT)
			{
				body->AddPosition({ MoveSpeed * 1.f, 0.0f });
				transform.SetScale(-1.0f, 1.0f);
				animator.Play(&move);
			}
			else if (dir == Directions::LEFT)
			{
				body->AddPosition({ MoveSpeed * -1.f, 0.0f });
				transform.SetScale(1.0f, 1.0f);
				animator.Play(&move);
			}
		}

		void Jump() override
		{
			// �ٴڿ� ������ ���� ���� ����
			if (body->IsOnGround())
			{
				body->AddPosition({ 0.0f, JumpPower });
			}
		}

		void Damaged() override
		{
			// �÷��̾� �ǰݽ�
			animator.Play(&damaged);
		}

		void Die() override
		{
			animator.Play(&die);
		}

	private:

	};

}

BIND_SCRIPT(Stump, "Stump", Stump);



