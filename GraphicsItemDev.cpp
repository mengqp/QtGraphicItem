/*******************************************************************************
 * 文件名:GraphicsItemDev.cpp
 * 文件描述:见头文件
 * 创建日期:2018/09/18 11:19:18
 * 版本：Ver1.0
 *
 * Copyright © 2018 - 2018 mengqp.
 *
 * 历史版本：
 * 修改人                修改时间                修改版本        修改内容
 *
 *
 ******************************************************************************/
#include "GraphicsItemDev.hpp"
/*******************************************************************************
 * 功能描述:构造函数
 ******************************************************************************/
CGraphicsItemDev::CGraphicsItemDev ( QObject *parent  )
        : QObject( parent )
{

}   /*-------- end 构造函数 -------- */

/*******************************************************************************
 * 功能描述:析构函数
 ******************************************************************************/
CGraphicsItemDev::~CGraphicsItemDev (void)
{

}   /*-------- end 析构函数 -------- */

/*------------------------------------------------------------------------------
 * 类:CGraphicsItemDev
 * 函数名:boundingRect
 * 功能描述:
 * 参数:void
 * 被调用:
 * 返回值:QRectF
 ------------------------------------------------------------------------------*/
QRectF CGraphicsItemDev::boundingRect(void) const
{
    qreal adjust = 2;
    return QRectF(-10-adjust,-10-adjust,43+adjust,43+adjust);
}   /*-------- end class CGraphicsItemDev method boundingRect -------- */

/*------------------------------------------------------------------------------
 * 类:CGraphicsItemDev
 * 函数名:paint
 * 功能描述:画图
 * 参数:QPainter *painter
 * 参数:const QStyleOptionGraphicsItem *option
 * 参数:QWidget *widget
 * 被调用:
 * 返回值:void
 ------------------------------------------------------------------------------*/
void CGraphicsItemDev::paint(QPainter *painter,
                             const QStyleOptionGraphicsItem *option,
                             QWidget *widget )
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);
    painter->drawEllipse(-7,-7,40,40);

    painter->setPen(QPen(Qt::black,0));
    painter->setBrush(flash?(Qt::red):(Qt::yellow));
    painter->drawEllipse(-10,-10,40,40);
}   /*-------- end class CGraphicsItemDev method paint -------- */
