/*******************************************************************************
 * 文件名:Widget.cpp
 * 文件描述:
 * 创建日期:2018/07/26 13:45:36
 * 版本：Ver1.0
 *
 * Copyright © 2018 - 2018 mengqp.
 *
 * 历史版本：
 * 修改人                修改时间                修改版本        修改内容
 *
 *
 ******************************************************************************/

#include "Widget.h"
#include "GraphicsItemDev.hpp"

/*******************************************************************************
 * 功能描述:构造函数
 ******************************************************************************/
CWidget::CWidget (QWidget *parent) : QWidget ( parent )
{
    this->resize( 480, 800 );
    this->setWindowTitle("EM761_BV2");
    this->setObjectName("EM761_BV2");

    scene = new QGraphicsScene;
    scene->setSceneRect(-200,-200,400,400);

    CGraphicsItemDev *item = new CGraphicsItemDev;
    scene->addItem(item);
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,(qrand()%int(scene->sceneRect().height()))-200);

    QGraphicsView *view = new QGraphicsView( this );
    view->setScene(scene);
    view->setMinimumSize(400,400);
    view->show();

    resize(550,450);
    setWindowTitle(tr("Graphics Items"));
}   /*-------- end 构造函数 -------- */

/*******************************************************************************
 * 功能描述:析构函数
 ******************************************************************************/
CWidget::~CWidget (void)
{

}   /*-------- end 析构函数 -------- */
