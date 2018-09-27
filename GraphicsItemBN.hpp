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
#include <QPainter>
#include <QWidget>

/*******************************************************************************
 *功能描述:关于装置的图元
 *******************************************************************************/
class CGraphicsItemBN : public QWidget, public QGraphicsItem
{
    Q_OBJECT

  public:
    /* constructor */
    explicit CGraphicsItemBN( QWidget *parent = 0 );
    /* distructor */
    virtual ~CGraphicsItemBN(void);

    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);


  public:
    // 设置报警数量
    void SetAlarmNum( unsigned char num );
    // 设置状态
    void setState( unsigned char  state );
    // 设置故障数量
    void SetFaultNum( unsigned char num );
    // 设置图片
    void SetStrImage( QString str );
    // 设置名字
    void SetStrName( QString str );

  private:
    unsigned char m_byAlarmNum;
    unsigned char m_byFaultNum;
    QString m_DevName;
    unsigned char m_byNamePos;
    QString m_strImage;
    QPixmap m_pixImage ;

};
