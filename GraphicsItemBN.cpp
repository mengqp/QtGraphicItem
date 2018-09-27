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
#include "GraphicsItemBN.hpp"
#include <QStyleOptionGraphicsItem>
#include <QPainterPath>

static const unsigned char ITEM_NAME_LEN = 12;  // 显示名字的长度
static const unsigned char ITEM_HEIGHT = 40;           // 图元的高
static const unsigned char ITEM_WIDTH = 160;            // 图元的高
static const unsigned char ITEM_IMAGE_HEIGHT = ITEM_HEIGHT / 2 ;    // 图元的图片高
static const unsigned char ITEM_NAME_HEIGHT = ITEM_HEIGHT / 4 ;    // 图元的名字高
static const unsigned char ITEM_NUM_HEIGHT = ITEM_HEIGHT / 4 ;    // 图元的报警和故障数量高
static const unsigned char ITEM_NUM_WIDTH = ITEM_WIDTH / 2 ;    // 图元的报警和故障数量高
static const QColor ALARM_COLOR = Qt::red ;    // 图元的报警和故障数量高
static const QColor FAULT_COLOR = QColor(211 , 124 , 9 );    // 图元的报警和故障数量高
static const QColor NORMAL_COLOR = Qt::green ;    // 图元的报警和故障数量高

// #include <QMouseButton>
/*******************************************************************************
 * 功能描述:构造函数
 ******************************************************************************/
CGraphicsItemBN::CGraphicsItemBN ( QWidget *parent  )
        : QWidget( parent )
{
    //可点击
    this->setFlag( QGraphicsItem::ItemIsSelectable, true );

}   /*-------- end 构造函数 -------- */

/*******************************************************************************
 * 功能描述:析构函数
 ******************************************************************************/
CGraphicsItemBN::~CGraphicsItemBN (void)
{

}   /*-------- end 析构函数 -------- */

/*------------------------------------------------------------------------------
 * 类:CGraphicsItemBN
 * 函数名:boundingRect
 * 功能描述:
 * 参数:void
 * 被调用:
 * 返回值:QRectF
 ------------------------------------------------------------------------------*/
QRectF CGraphicsItemBN::boundingRect(void) const
{
    qreal adjust = 0;
    return QRectF(0, 0,ITEM_WIDTH+adjust,ITEM_HEIGHT+adjust);
}   /*-------- end class CGraphicsItemBN method boundingRect -------- */

/*------------------------------------------------------------------------------
 * 类:CGraphicsItemBN
 * 函数名:paint
 * 功能描述:画图
 * 参数:QPainter *painter
 * 参数:const QStyleOptionGraphicsItem *option
 * 参数:QWidget *widget
 * 被调用:
 * 返回值:void
 ------------------------------------------------------------------------------*/
void CGraphicsItemBN::paint(QPainter *painter,
                            const QStyleOptionGraphicsItem *option,
                            QWidget *widget )
{

    // 画整个方框的颜色
    painter->setBrush( Qt::NoBrush );
    // 判断选中时，设置状态为 State_None
    if (option->state & QStyle::State_Selected)
    {
        painter->setBrush( Qt::gray );
    }
    // painter->drawRect(0, 0, ITEM_WIDTH, ITEM_HEIGHT); //x,y,w,h
    QPainterPath path;
    path.addRoundRect( QRectF(10,10,ITEM_WIDTH-20,ITEM_HEIGHT-20), 10 , 10 );
    painter->drawPath( path );

    if ( m_byAlarmNum > 0 )
    {
        painter->setBrush( ALARM_COLOR );
        painter->setPen( ALARM_COLOR );
    }
    else if( m_byFaultNum > 0 )
    {
        painter->setBrush( FAULT_COLOR );
        painter->setPen(FAULT_COLOR );
    }
    else
    {
        painter->setBrush( NORMAL_COLOR );
        painter->setPen(NORMAL_COLOR );
    }
    painter->drawEllipse(ITEM_WIDTH - 20, 10 ,10,10);

    painter->setPen( Qt::black );
    QString name = m_DevName;
    if ( name.length() > ITEM_NAME_LEN )
    {
        if ( name.length() - m_byNamePos <= ITEM_NAME_LEN )
        {
            name = name.mid( m_byNamePos, -1 );
            m_byNamePos = 0;
        }
        else
        {
            name = name.mid( m_byNamePos, ITEM_NAME_LEN );
            m_byNamePos += 1;
        }
    }

    painter->drawText(0, 0 ,ITEM_WIDTH,ITEM_HEIGHT,Qt::AlignCenter, name);
}   /*-------- end class CGraphicsItemBN method paint -------- */

/*------------------------------------------------------------------------------
 * 类:CGraphicsItemBN
 * 函数名:mouseReleaseEvent
 * 功能描述:鼠标松开事件
 * 参数: QGraphicsSceneMouseEvent *event
 * 被调用:
 * 返回值:void
 ------------------------------------------------------------------------------*/
void CGraphicsItemBN::mouseReleaseEvent( QGraphicsSceneMouseEvent *event )
{
    printf("event\n");

    m_byAlarmNum+=1;
    m_byFaultNum+=2;

    // update();
    // this->hide();

}   /*-------- end class CGraphicsItemBN method mouseReleaseEvent -------- */

/*------------------------------------------------------------------------------
 * 类:CGraphicsItemBN
 * 函数名:SetAlarmNum
 * 功能描述:设置报警数量
 * 参数: unsigned char num
 * 被调用:
 * 返回值:void
 ------------------------------------------------------------------------------*/
void CGraphicsItemBN::SetAlarmNum( unsigned char num )
{
    m_byAlarmNum = num;
}   /*-------- end class CGraphicsItemBN method SetAlarmNum -------- */

/*------------------------------------------------------------------------------
 * 类:CGraphicsItemBN
 * 函数名:SetFaultNum
 * 功能描述:设置故障数量
 * 参数: unsigned char num
 * 被调用:
 * 返回值:void
 ------------------------------------------------------------------------------*/
void CGraphicsItemBN::SetFaultNum( unsigned char num )
{
    m_byFaultNum = num;
}   /*-------- end class CGraphicsItemBN method SetFaultNum -------- */

/*------------------------------------------------------------------------------
 * 类:CGraphicsItemBN
 * 函数名:SetStrImage
 * 功能描述:设置图片
 * 参数: QString str
 * 被调用:
 * 返回值:void
 ------------------------------------------------------------------------------*/
void CGraphicsItemBN::SetStrImage( QString str )
{
    if ( str.isEmpty() )
    {
        return;
    }

    m_strImage = str;
    m_pixImage = QPixmap(str);
}   /*-------- end class CGraphicsItemBN method SetStrImage -------- */

/*------------------------------------------------------------------------------
 * 类:CGraphicsItemBN
 * 函数名:SetStrName
 * 功能描述:设置名字
 * 参数: QString str
 * 被调用:
 * 返回值:void
 ------------------------------------------------------------------------------*/
void CGraphicsItemBN::SetStrName( QString str )
{
    if ( str.isEmpty() )
    {
        return;
    }

    m_DevName = str;
}   /*-------- end class CGraphicsItemBN method SetStrName -------- */
