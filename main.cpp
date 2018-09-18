/*******************************************************************************
 * 文件名:main.cpp
 * 文件描述:主函数入口
 * 创建日期:2018/07/26 13:44:10
 * 版本：Ver1.0
 *
 * Copyright © 2018 - 2018 mengqp.
 *
 * 历史版本：
 * 修改人                修改时间                修改版本        修改内容
 *
 *
 ******************************************************************************/

#include <QApplication>
#include <QFile>
#include "Widget.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile qss("./css.qss");
    if ( qss.open(QFile::ReadOnly) )
    {
        printf("open ok\n");
        QString str = qss.readAll();
        qDebug() << str;
        qApp->setStyleSheet( str );
        qss.close();
    }


    CWidget w;
    w.show();

    return a.exec();
}
