# 👾 Escape from Aliens

콘솔 환경에서 즐기는 외계인 슈팅 게임!  
플레이어는 외계인과 외계인의 총알을 피하고, 아이템을 활용하며 오래 생존하는 것이 목표입니다!

## 🧩 게임 소개

- **조작키**: `W`, `A`, `S`, `D` 로 이동

### 피하세요!
- **@**: 외계인
- **x**: 외계인이 쏘는 총알
- **o**: 운석
### 당신입니다!
- **\***: 플레이어
### 도움을 줄 아이템 종류!
- **H**: 힐링팩 (HP +1 회복)
- **B**: 폭탄 (플레이어 주변 7x7반경 외계인 제거)
### 랭킹 시스템!
생존 시간에 따라 스코어가 기록되며, 최고 기록 9개가 랭킹에 저장됩니다.


---

## 🧰 프로젝트 구조

```
shooting_game_project/
├── include/             # 헤더 파일
├── src/                 # 소스 코드
├── .gitignore
├── CMakeLists.txt       # CMake 빌드 설정
├── README.md # 프로젝트 소개 및 실행 방법
└── pull_request_template.md # pr 요청 규칙
```

---

# 🛠️ macOS에서 실행 방법 (CLion 기준)

### ✅ 사전 준비

- CLion 설치 (JetBrains)
- `Xcode Command Line Tools` 설치
- `CMake`와 `Make`는 CLion 및 Xcode에서 자동 제공

---

### 📂 프로젝트 열기

1. 이 저장소를 GitHub에서 **clone**합니다.

```bash
git clone https://github.com/rmsckd1640/escape-from-aliens.git
```

2. CLion을 실행하고 `Open`을 눌러 clone한 폴더를 엽니다.  
3. 프로젝트가 열리면 자동으로 CMake 설정이 로드됩니다.

---

### 🧱 빌드 및 실행

1. 오른쪽 상단 톱니바퀴 아이콘에서 `Build Project` 클릭  
2. 또는 단축키 `⇧ Shift + F10`으로 실행  

빌드가 완료되면 `cmake-build-debug/` 또는 `cmake-build-release/` 디렉토리 아래에 실행 파일이 생성되며, 게임이 바로 실행됩니다.

---

# 🛠️ Windows에서 실행 방법 (Visual Studio 기준)

### ✅ 사전 준비

- Visual Studio가 설치되어 있어야 합니다.
- 설치 시 **"C++을 위한 데스크톱 개발" 워크로드**가 포함되어 있어야 합니다.
- **CMake는 Visual Studio에 내장**되어 있으므로 별도 설치가 필요 없습니다.

---

### 📂 프로젝트 열기

1. 이 저장소를 GitHub에서 **clone**합니다.
2. Visual Studio를 실행하고 **`로컬 폴더 열기`**를 선택합니다.
3. `escape-from-aliens` 폴더를 열어줍니다.
4. 프로젝트를 열면 Visual Studio가 **자동으로 CMake 파일을 생성**합니다.

> ❗ 만약 CMake 파일이 자동으로 생성되지 않는 경우:  
> 메뉴에서 `프로젝트 > CMake 사전 설정 편집`을 선택하면 `CMakePresets.json`이 생성됩니다.

---

### 🧱 빌드

1. 상단 메뉴에서 `빌드 > 모두 빌드`를 클릭합니다.
2. 빌드가 완료되면 실행 가능한 `.exe` 파일이 생성됩니다.

---

### 🎮 게임 실행

1. **솔루션 탐색기**에서 `src/main.c` 파일을 클릭합니다.
2. 다음 중 한 가지 방법으로 실행합니다:
   - `Ctrl + F5` 키를 눌러 실행  
   - 상단 메뉴에서 `디버그 > 디버그하지 않고 시작` 선택  
3. 게임이 실행됩니다!

---

# 📝 기타

- 기본 설정에서 랭킹은 `score_rank.txt` 파일로 저장됩니다.
- 코드는 C언어(C11)를 기반으로 작성되었습니다.
- 문제 또는 제안 사항은 Issues 탭에 남겨주세요.

---
