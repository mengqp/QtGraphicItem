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

static const unsigned char ITEM_NAME_LEN = 6;  // 显示名字的长度
static const unsigned char ITEM_HEIGHT = 80;           // 图元的高
static const unsigned char ITEM_WIDTH = 60;            // 图元的高
static const unsigned char ITEM_IMAGE_HEIGHT = ITEM_HEIGHT / 2 ;    // 图元的图片高
static const unsigned char ITEM_NAME_HEIGHT = ITEM_HEIGHT / 4 ;    // 图元的名字高
static const unsigned char ITEM_NUM_HEIGHT = ITEM_HEIGHT / 4 ;    // 图元的报警和故障数量高
static const unsigned char ITEM_NUM_WIDTH = ITEM_WIDTH / 2 ;    // 图元的报警和故障数量高
static const QColor ALARM_COLOR = Qt::red ;    // 图元的报警和故障数量高
static const QColor FAULT_COLOR = QColor(211 , 124 , 9 );    // 图元的报警和故障数量高

// #include <QMouseButton>
/*******************************************************************************
 * 功能描述:构造函数
 ******************************************************************************/
CGraphicsItemDev::CGraphicsItemDev ( QObject *parent  )
        : QObject( parent )
{
    //可点击
    this->setFlag( QGraphicsItem::ItemIsSelectable, true );

    m_byAlarmNum = 0;
    m_byFaultNum = 0;
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
    qreal adjust = 0;
    return QRectF(0, 0,ITEM_WIDTH+adjust,ITEM_HEIGHT+adjust);
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

    // QPixmap image("./EM720LCD.JPG");
    // m_button.setGeometry( -20, -20, 40 , 40 );
    // m_button.setIcon( image );
    painter->drawPixmap( 0, 0, ITEM_WIDTH, ITEM_IMAGE_HEIGHT, m_pixImage );
    QString name = m_DevName;

    printf("%d\n", name.length());
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
    painter->drawText(0, ITEM_IMAGE_HEIGHT ,ITEM_WIDTH,ITEM_NAME_HEIGHT,Qt::AlignCenter, name);

    painter->setPen(Qt::NoPen);
    if ( m_byAlarmNum > 0 )
    {
        painter->setBrush( ALARM_COLOR );
        painter->setPen( ALARM_COLOR );
        painter->drawText(0,
                          ITEM_IMAGE_HEIGHT + ITEM_NAME_HEIGHT ,
                          ITEM_NUM_WIDTH,
                          ITEM_NUM_HEIGHT,
                          Qt::AlignLeft, QString::number( m_byAlarmNum, 10 ));
    }

    if( m_byFaultNum > 0 )
    {
        if ( m_byAlarmNum == 0 )
        {
            painter->setBrush( FAULT_COLOR );
        }
        painter->setPen(FAULT_COLOR );
        painter->drawText(ITEM_NUM_WIDTH,
                          ITEM_IMAGE_HEIGHT + ITEM_NAME_HEIGHT ,
                          ITEM_NUM_WIDTH,
                          ITEM_NUM_HEIGHT,
                          Qt::AlignRight, QString::number( m_byFaultNum, 10 ));
        // painter->drawText(20, 60 ,25,20,Qt::AlignRight, QString::number( m_byFaultNum, 10 ));
    }

    painter->drawEllipse(ITEM_WIDTH/2 -5, ITEM_WIDTH/2 +5,10,10);
}   /*-------- end class CGraphicsItemDev method paint -------- */

/*------------------------------------------------------------------------------
 * 类:CGraphicsItemDev
 * 函数名:mouseReleaseEvent
 * 功能描述:鼠标松开事件
 * 参数: QGraphicsSceneMouseEvent *event
 * 被调用:
 * 返回值:void
 ------------------------------------------------------------------------------*/
void CGraphicsItemDev::mouseReleaseEvent( QGraphicsSceneMouseEvent *event )
{
    printf("event\n");

    m_byAlarmNum+=1;
    m_byFaultNum+=2;

    update();
    // this->hide();

}   /*-------- end class CGraphicsItemDev method mouseReleaseEvent -------- */

/*------------------------------------------------------------------------------
 * 类:CGraphicsItemDev
 * 函数名:SetAlarmNum
 * 功能描述:设置报警数量
 * 参数: unsigned char num
 * 被调用:
 * 返回值:void
 ------------------------------------------------------------------------------*/
void CGraphicsItemDev::SetAlarmNum( unsigned char num )
{
    m_byAlarmNum = num;
}   /*-------- end class CGraphicsItemDev method SetAlarmNum -------- */

/*------------------------------------------------------------------------------
 * 类:CGraphicsItemDev
 * 函数名:SetFaultNum
 * 功能描述:设置故障数量
 * 参数: unsigned char num
 * 被调用:
 * 返回值:void
 ------------------------------------------------------------------------------*/
void CGraphicsItemDev::SetFaultNum( unsigned char num )
{
    m_byFaultNum = num;
}   /*-------- end class CGraphicsItemDev method SetFaultNum -------- */

/*------------------------------------------------------------------------------
 * 类:CGraphicsItemDev
 * 函数名:SetStrImage
 * 功能描述:设置图片
 * 参数: QString str
 * 被调用:
 * 返回值:void
 ------------------------------------------------------------------------------*/
void CGraphicsItemDev::SetStrImage( QString str )
{
    if ( str.isEmpty() )
    {
        return;
    }

    m_strImage = str;
    m_pixImage = QPixmap(str);
}   /*-------- end class CGraphicsItemDev method SetStrImage -------- */

/*------------------------------------------------------------------------------
 * 类:CGraphicsItemDev
 * 函数名:SetStrName
 * 功能描述:设置名字
 * 参数: QString str
 * 被调用:
 * 返回值:void
 ------------------------------------------------------------------------------*/
void CGraphicsItemDev::SetStrName( QString str )
{
    if ( str.isEmpty() )
    {
        return;
    }

    m_DevName = str;
}   /*-------- end class CGraphicsItemDev method SetStrName -------- */
