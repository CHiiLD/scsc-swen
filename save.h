#ifndef SAVE_H
#define SAVE_H

#include <QWidget>
//#include <QString>

/**
 * @brief 데이터 저장 클래스
 */
class Save
{
public:
    /**
     * @brief 텍스트를 새로운 파일을 생성하여 저장합니다.
     * @param parent QWidget 인스턴스
     * @param text 저장할 텍스트
     * @param error 에러 발생 이유
     * @param codec 저장할 텍스트의 인코딩을 설정합니다.(기본: UTF8)
     * @return 성공 여부를 반환합니다.
     */
    static bool ToFile(QWidget* parent, QString text, QString& error, const char* codec = "UTF-8");
};

#endif // SAVE_H
