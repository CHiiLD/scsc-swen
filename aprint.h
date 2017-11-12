#ifndef APRINT_H
#define APRINT_H

/**
 * @brief 추상 프린트 클래스
 */
class APrint
{
public:
    /**
     * @brief 클래스 정보를 출력합니다.
     */
    virtual void print() = 0;
};

/**
 * @brief 상속용 프린트 클래스
 */
class Print : public APrint
{
public:
    /**
     * @brief 클래스 정보를 출력합니다.
     */
    virtual void print() override;
};

#endif // APRINT_H
