#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

#include <list>
#include "swen.h"

/**
 * @brief 난수 생성 클래스
 */
class RandNumber
{
public:
    /**
     * @brief 난수를 생성합니다.
     * @param min 생성할 난수의 최소값
     * @param max 생성할 난수의 최대값
     * @param size 생성할 난수의 개수
     * @param values 난수 리스트
     * @return 성공 시 0(ok), 잘못된 파라미터 입력엔 -1(error)을 반환합니다.
     */
    static int generate(int min, int max, int size, std::list<int>& values);
};

#endif // RANDOMNUMBER_H
