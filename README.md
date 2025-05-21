# shooting_game_project

# Visual Studio에서 GitHub CMake 프로젝트 빌드 가이드

이 문서는 Windows 환경에서 GitHub에 올라온 CMake 기반 C 프로젝트를 **Visual Studio**로 빌드하고 실행하는 방법을 안내합니다.  
(CLion 없이도 VS만으로 빌드 가능)

---

## 준비사항

- **Visual Studio 설치 시 "C++용 CMake 도구" 포함 선택**  

---

## 1. GitHub에서 프로젝트 clone

```bash
git clone https://github.com/너의아이디/레포이름.git
cd 레포이름
```

---

## 2. Visual Studio로 프로젝트 열기

1. Visual Studio 실행
2. 메뉴 → `파일 → 폴더 열기`
3. `CMakeLists.txt`가 포함된 폴더 선택

---

## 3. CMake 자동 인식 확인

- 오른쪽 상단에서 `x64-Debug`, `x86-Release` 등 선택 가능
- VS가 `.sln` 파일 없이도 CMake 기반으로 빌드 구성 자동으로 해줌

---

## 4. 빌드 & 실행

- 상단 툴바의 **녹색 ▶️ 실행 버튼** 클릭
- 또는 단축키 `Ctrl + F5` 사용

---
