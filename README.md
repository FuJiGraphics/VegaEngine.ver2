# Simple 2D Game Engine (Beta version)

이 프로젝트는 간단한 2D 게임을 제작할 수 있는 게임 엔진입니다. 직관적인 도구와 기능들을 제공하여, 개발자들이 빠르게 2D 게임을 개발할 수 있도록 돕습니다. 최근에는 **ECS (Entity-Component-System)** 아키텍처를 통합하여 게임의 성능과 확장성을 더욱 향상시켰습니다.

---

## 📦 빌드 방법

### 1. Generate Solution 실행
프로젝트의 **Generate Solution** 기능을 실행하여 솔루션 파일을 생성합니다.

### 2. 솔루션 빌드
생성된 솔루션 파일을 열고, 원하는 빌드 환경에 맞게 빌드를 진행합니다.

> **참고**: 프로젝트를 실행하려면 `.NET` 환경 또는 Unity와 같은 추가 환경이 필요할 수 있습니다.

---

## 🔧 주요 기능

### 🎮 **Sprite Editor**
- 스프라이트 이미지를 손쉽게 편집하고 관리할 수 있는 툴입니다.
- 게임에서 사용할 2D 이미지를 쉽게 추가하고 조정할 수 있습니다.
  
### ⚙️ **유니티의 Initiate 및 Prefab 기능**
- 게임 오브젝트의 초기화 및 Prefab 기능을 제공합니다.
- Prefab을 사용하여 여러 오브젝트를 재사용 가능하게 만들어 효율적인 게임 개발을 돕습니다.

### 🛠️ **ECS (Entity-Component-System)**
- **ECS 아키텍처**가 추가되어 성능과 확장성이 크게 향상되었습니다.
- **Entity**(엔티티)와 **Component**(컴포넌트), **System**(시스템)으로 구성된 구조를 통해 게임 로직을 분리하고 최적화할 수 있습니다.
- 게임의 오브젝트와 관련된 데이터를 **컴포넌트**로 분리하고, 이를 처리하는 **시스템**을 통해 효율적으로 데이터를 관리합니다.
- ECS는 특히 **성능 최적화**가 중요한 대규모 프로젝트에서 유용합니다.

---

## 📝 설치 방법

### 1. 저장소 클론

```bash
git clone https://github.com/your-username/your-repository.git
