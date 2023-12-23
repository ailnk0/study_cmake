# study_cmake

## 1. Recommended Directories Structure

```
// Recommended 1
.
├── bin             // 컴파일된 실행 파일
├── data            // 데이터와 에셋
├── demo            // 데모
├── doc             // 문서
├── include         // 공개 헤더 파일
├── lib             // 외부 라이브러리
├── src             // 소스 코드
└── test            // 테스트
```

```
// Recommended 2
.
├── bin             // 컴파일된 실행 파일
│    ├── debug      // 디버그 빌드
│    └── release    // 릴리스 빌드
├── doc             // 문서
├── include         // 공개 헤더 파일
├── lib             // 외부 라이브러리
├── obj             // 컴파일 중에 생성된 중간 개체 파일
├── packages        // 종속성 관리를 위한 NuGet 패키지
├── resources       // 이미지나 데이터 파일과 같은 리소스
├── src             // 소스 코드
├── test            // 테스트
└── tools           // 프로젝트와 관련된 스크립트 또는 도구
```
