/*******************************************************************************
 * 文件名:GraphicItemDev.hpp
 * 文件描述:自己制做的关于装置的图元，只供自己使用
 * 创建日期:2018/09/18 11:02:10
 * 版本：Ver1.0
 *
 * Copyright © 2018 - 2018 mengqp.
 *
 * 历史版本：
 * 修改人                修改时间                修改版本        修改内容
 *
 *
 ******************************************************************************/

#include <QObject>
#include <QGraphicsItem>
/*******************************************************************************
 *功能描述:关于装置的图元
 *******************************************************************************/
class CGraphicsItemDev : public QObject, public QGraphicsItem
{
  public:
    /* constructor */
    explicit CGraphicsItemDev(void);
    /* distructor */
    virtual ~CGraphicsItemDev(void);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
