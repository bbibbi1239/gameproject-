#include "game.h"

//전역변수로 손잡기 상태 추가
int a = 0; // 0: 손 안잡기, 1: 손잡기

//키 조종
int keyControl() {
    char temp = getch();
    if (temp == 'w' || temp == 'W') {
        return UP;
    }
    else if (temp == 'a' || temp == 'A') {
        return LEFT;
    }
    else if (temp == 's' || temp == 'S') {
        return DOWN;
    }
    else if (temp == 'd' || temp == 'D') {
        return RIGHT;
    }
    else if (temp == ' ') { //스페이스바(공백)
        a = (a == 0) ? 1 : 0; // 명확한 상태 전환
        system("cls"); // 화면 깔끔하게 지우기
        titleDraw(); // 상태가 변경될 때마다 화면 갱신
        return SUBMIT;
    }
}

//메인화면 출력하기
void titleDraw() {
    if (a == 1) {
        // 손잡기 상태일 때 출력할 내용
        printf("현재 상태: 손잡기\n");
        a = 1;
        printf("\033[H\033[J"); // 콘솔 화면 지우기 (ANSI 코드)

        printf("................................................................................................\n");
        printf("................................................................................................\n");
        printf("                                                                                                \n");
        printf("                                                                                                \n");
        printf("                                                                                                \n");
        printf("                                                                                                \n");
        printf("                                                                                                \n");
        printf("                                                                                                \n");
        printf("                                   ,~.                            ~:,     ,:~.                  \n");
        printf("                                 . ! ;                          ~   :!.*-;~   -.               \n");
        printf("             ,...,             .*,..*.=                         .     .- .      .              \n");
        printf("           ;         :       ,-       ~..~                     .     -. .~!     $               \n");
        printf("          ~         .:      ;         !~                           .:     .::   $               \n");
        printf("          ~          #      =         .,                        - ~;         =, $               \n");
        printf("          ,          $      -         .~                        ; -          .; $               \n");
        printf("          -          #      !         .-    &&     &&           *..          .-.*               \n");
        printf("             ~,:.*             *,.,=.     &!!!!& &!!!!&              :! =.!,                    \n");
        printf("    -~~~~~~~=~~:~~=~~~~~~~~~~~~:~~~~$~~~&!!!!!!!&!!!!!!!&   :,,,,,,=,,-----,,,.............,,,,,\n");
        printf("    *               !                     &!!!!!!!!!!!&      ~    ,!!,                          \n");
        printf("    * !,            ,:~                    ;,&!!!!!!&        ~    ~,.                         . \n");
        printf("    * ~.               -$..                ;- '&!&           ~,@.$-                           . \n");
        printf("    *                    .-,!!                ' &           .=;-,                             . \n");
        printf("    * -                       -*~.--.      -: '      ,,,**.~~                                 . \n");
        printf("    * =                           ...~==...,,!===;......---~,                                 . \n");
        printf("    ::::::::::::::::::::::::::::::::::::;;!;::               :::::::::::::::::::::::::::::::::. \n");
        printf("     ;  !$     -=~.            -,.--     ;:  ;                ; : .    ;--;                   . \n");
        printf("     *****!*********!!!!!!!!!!!*****!!!******=,              ;..:.~.....,~..............,,,,,,, \n");
        printf("     ========================================$,              ================================== \n");
        printf("     ~,, ~                                   ,,              !!$                                \n");
        printf("     ~,, $                                   ,,              ! =                                \n");
        printf("     ~,, $                                   ,,              ! =                                \n");
        printf("................................................................................................\n");
    }
    else {
        // 손 안잡기 상태일 때 출력할 내용
        printf("현재 상태: 손 안잡기\n");
        printf("\033[H\033[J"); // 콘솔 화면 지우기 (ANSI 코드)

        printf("................................................................................................\n");
        printf("................................................................................................\n");
        printf("                                                                                                \n");
        printf("                                                                                                \n");
        printf("                                                                                                \n");
        printf("                                                                                                \n");
        printf("                                                                                                \n");
        printf("                                                                                                \n");
        printf("                                   ,~.                            ~:,     ,:~.                  \n");
        printf("                                 . ! ;                          ~   :!.*-;~   -.               \n");
        printf("             ,...,             .*,..*.=                         .     .- .      .              \n");
        printf("           ;         :       ,-       ~..~                     .     -. .~!     $                \n");
        printf("          ~         .:      ;         !~                           .:     .::   $               \n");
        printf("          ~          #      =         .,                        - ~;         =, $               \n");
        printf("          ,          $      -         .~                        ; -          .; $               \n");
        printf("          -          #      !         .-                        *..          .-.*               \n");
        printf("             ~,:.*             *,.,=.                                :! =.!,                    \n");
        printf("    -~~~~~~~=~~:~~=~~~~~~~~~~~~:~~~~$~~~~~~~~-.             :,,,,,,=,,-----,,,.............,,,,,\n");
        printf("    *                                        .,              ~                                  \n");
        printf("    * !,                                   ;, .              ~                                . \n");
        printf("    * ~.                                   ;- '              ~                                . \n");
        printf("    *                                         '             .=                                . \n");
        printf("    * -                                    -: '             ~                                 . \n");
        printf("    * =                                    ,,!=             ,                                 . \n");
        printf("    ::::::::::::::::::::::::::::::::::::;;!;::               :::::::::::::::::::::::::::::::::. \n");
        printf("     ;  !$     -=~.            -,.--     ;:  ;                ; : .    ;--;                   . \n");
        printf("     *****!*********!!!!!!!!!!!*****!!!******=,              ;..:.~.....,~..............,,,,,,, \n");
        printf("     ========================================$,              ================================== \n");
        printf("     ~,, ~                                   ,,              !!$                                \n");
        printf("     ~,, $                                   ,,              ! =                                \n");
        printf("     ~,, $                                   ,,              ! =                                \n");
        printf("................................................................................................\n");
    }
}

//게이지구현
void loveGauge() {
    //틀
    int x = 10;
    int y = 37;
    int currentGauge = 0;

    // 틀 그리기
    gotoxy(x - 2, y - 1);
    printf("====================================================================================\n");
    gotoxy(x - 2, y);
    printf("||");
    gotoxy(100 - x, y);
    printf("||");
    gotoxy(x - 2, y + 1);
    printf("====================================================================================\n");

    while (1) {
        // 게이지 업데이트
        gotoxy(x, y);
        printf("                                                                                "); // 게이지 초기화

        if (a == 1) {
            // 손잡기 상태일 때 게이지 증가
            if (currentGauge < 80) {
                currentGauge += 1; // 게이지 증가 속도 감소
            }
        }
        else {
            // 손 안잡기 상태일 때 게이지 감소
            if (currentGauge > 0) {
                currentGauge -= 1; // 게이지 감소 속도 감소
            }
        }

        // 게이지 그리기
        gotoxy(x, y);
        for (int i = 0; i < currentGauge; i++) {
            printf("#");
        }

        // 게이지가 다 찼을 때
        if (currentGauge >= 80) {
            system("cls"); // 화면 지우기
            gotoxy(30, 10);
            printf("다음 스테이지");
            break;
        }

        // 키 입력 확인
        if (kbhit()) {
            keyControl();
        }

        Sleep(300); // 게이지 변화 속도를 더 천천히
    }
}